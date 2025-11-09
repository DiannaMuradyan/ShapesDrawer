#pragma once
#include <QWidget>

class QLineEdit;
class QPushButton;

class CommandConsole : public QWidget
{
    Q_OBJECT
public:
    explicit CommandConsole(QWidget *parent = nullptr);

signals:
    void commandEntered(const QString &command);

private slots:
    void onEnterPressed();

private:
    QLineEdit *m_input;
    QPushButton *m_btn;
};
