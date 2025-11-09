#include "CommandConsole.h"
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

CommandConsole::CommandConsole(QWidget *parent) : QWidget(parent)
{
    m_input = new QLineEdit(this);
    m_btn = new QPushButton("Enter", this);

    QHBoxLayout *layout = new QHBoxLayout(this);

    this->setStyleSheet("background-color: #2E2E2E; color: white;");

    layout->addWidget(m_input);
    layout->addWidget(m_btn);

    m_input->setPlaceholderText("Command console");

    m_input->setStyleSheet("background-color: white; color: black;");
    m_btn->setStyleSheet("background-color: #4CAF50; color: white;");

    connect(m_input, &QLineEdit::returnPressed, this, &CommandConsole::onEnterPressed);
    connect(m_btn, &QPushButton::clicked, this, &CommandConsole::onEnterPressed);
}

void CommandConsole::onEnterPressed()
{
    QString command = m_input->text().trimmed();

    if (!command.isEmpty())
        emit commandEntered(command);
    m_input->clear();
}
