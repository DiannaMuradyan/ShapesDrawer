#pragma once
#include <QMainWindow>

class CanvasWidget;
class LogWidget;
class CommandConsole;
class CommandProcessor;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupUi();
    void setupConnections();

    CanvasWidget *m_canvas;
    LogWidget *m_log;
    CommandConsole *m_console;
    CommandProcessor *m_processor;
};
