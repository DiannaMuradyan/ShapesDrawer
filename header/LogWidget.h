#pragma once
#include <QWidget>

class QPlainTextEdit;

class LogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LogWidget(QWidget *parent = nullptr);

public slots:
    void appendMessage(const QString &msg);
    void clearLog();

private:
    QPlainTextEdit *m_view;
};
