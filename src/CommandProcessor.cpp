#include "CommandProcessor.h"
#include "ShapeFactory.h"
#include "Connection.h"
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDebug>


CommandProcessor::CommandProcessor(QObject *parent): QObject(parent) {}

static QVector<QPointF> parseCoords(const QStringList &tokens)
{
    QVector<QPointF> pts;
    QRegularExpression re("\\{?\\s*(-?\\d+(?:\\.\\d+)?)\\s*,\\s*(-?\\d+(?:\\.\\d+)?)\\s*\\}?");

    QRegularExpressionMatch m;

    for (auto &t : tokens) {
        m = re.match(t);

        if (m.hasMatch())
            pts.append(QPointF(m.captured(1).toDouble(), m.captured(2).toDouble()));
    }

    return pts;
}

void CommandProcessor::processCommand(const QString &cmd)
{
    QString c = cmd.trimmed();

    if (c.startsWith("create_")) {
        QString type = c.section(' ', 0, 0).mid(7);
        QRegularExpression nameRe("-name\\s*\\{?([^}\\s]+)\\}?");

        QRegularExpressionMatch nameMatch;
        nameMatch = nameRe.match(c);

        if (!nameMatch.hasMatch()) {
            emit logMessage("Error: missing -name {name}");
            return;
        }

        QString name = nameMatch.captured(1);

        if (m_registry.count(name)) {
            emit logMessage("Error: duplicate name: " + name);
            return;
        }

        QVector<QPointF> pts = parseCoords(c.split(' '));

        auto shape = ShapeFactory::createShape(type, name, pts);

        if (shape) {
            m_registry[name] = shape;
            emit shapeCreated(shape);

            emit logMessage("Created " + type + " '" + name + "'");
        }
        else {
            emit logMessage("Error: invalid " + type + " parameters");
        }
    }
    else if (c.startsWith("connect")) {
        QRegularExpression re1("-object_name_1\\s*\\{([^}]*)\\}");
        QRegularExpression re2("-object_name_2\\s*\\{([^}]*)\\}");

        auto m1 = re1.match(c);
        auto m2 = re2.match(c);

        if (!m1.hasMatch() || !m2.hasMatch()) {
            emit logMessage("Error: connect syntax invalid");
            return;
        }

        QString a = m1.captured(1), b = m2.captured(1);

        if (!m_registry.count(a) || !m_registry.count(b)) {
            emit logMessage("Error: unknown object(s)");
            return;
        }

        auto conn = std::make_shared<Connection>("conn_"+a+"_"+b, m_registry[a], m_registry[b]);
        emit connectionCreated(conn);

        emit logMessage("Connected " + a + " and " + b);
    }
    else if (c.startsWith("execute_file")) {
        QRegularExpression re("-file_path\\s*\\{([^}]*)\\}");

        auto m = re.match(c);

        if (m.hasMatch()) {
            QString path = m.captured(1);
            executeFile(path);
        } else {
            emit logMessage("Error: invalid execute_file syntax");
        }

        return;
    }
}



void CommandProcessor::executeFile(const QString &filePath)
{
    QFile file(filePath);

    if (!file.exists()) {
        emit logMessage("Error: file does not exist: " + filePath);
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit logMessage("Error: cannot open file: " + filePath);
        return;
    }

    QByteArray data = file.readAll();
    QStringList lines = QString(data).split('\n');

    for (QString line : lines) {
        line = line.trimmed();

        if (!line.isEmpty()) {
            processCommand(line);
        }
    }
}


