#pragma once
#include <QObject>
#include <map>
#include <memory>

class Shape;

class CommandProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CommandProcessor(QObject *parent = nullptr);

public slots:
    void processCommand(const QString &cmd);
    void executeFile(const QString &filePath);

signals:
    void logMessage(const QString &msg);
    void shapeCreated(std::shared_ptr<Shape> shape);
    void connectionCreated(std::shared_ptr<Shape> shape);

private:
    std::map<QString, std::shared_ptr<Shape>> m_registry;
};
