#include "LogWidget.h"
#include <QPlainTextEdit>
#include <QVBoxLayout>

LogWidget::LogWidget(QWidget *parent) : QWidget(parent)
{
    m_view = new QPlainTextEdit(this);
    m_view->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_view);
}

void LogWidget::appendMessage(const QString &msg)
{
    m_view->appendPlainText(msg);
}

void LogWidget::clearLog()
{
    m_view->clear();
}
