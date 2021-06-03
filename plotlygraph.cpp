#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView* view = new QWebEngineView(parent);
    view->load(QUrl("qrc:/graph/PlotlyGraph.html"));
    ui->gridLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::jscallme()
{
    QMessageBox::information(NULL,"jscallme","I'm called by js!");
}
void MainWindow::setsomeattribute(QString attr)
{
    m_someattribute=attr;
   emit someattributeChanged(m_someattribute);
}
