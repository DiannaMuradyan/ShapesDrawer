#include "MainWindow.h"
#include "CanvasWidget.h"
#include "LogWidget.h"
#include "CommandConsole.h"
#include "CommandProcessor.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    setupConnections();
}

void MainWindow::setupUi()
{
    m_canvas = new CanvasWidget(this);
    m_log = new LogWidget(this);
    m_console = new CommandConsole(this);
    m_processor = new CommandProcessor(this);

    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    layout->addWidget(m_canvas, 5);
    layout->addWidget(m_log, 2);

    layout->addWidget(m_console, 1);
    layout->setContentsMargins(5, 5, 5, 5);

    setCentralWidget(central);

    menuBar()->addMenu("File");
    menuBar()->addMenu("Help");

    resize(900, 700);
    setWindowTitle("Shape Drawer");
}

void MainWindow::setupConnections()
{
    connect(m_console, &CommandConsole::commandEntered, m_processor, &CommandProcessor::processCommand);

    connect(m_processor, &CommandProcessor::logMessage, m_log, &LogWidget::appendMessage);

    connect(m_processor, &CommandProcessor::shapeCreated, m_canvas, &CanvasWidget::addShape);

    connect(m_processor, &CommandProcessor::connectionCreated, m_canvas, &CanvasWidget::addShape);
}

