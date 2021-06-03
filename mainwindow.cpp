#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QMessageBox>
#include <QWebChannel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView* view = new QWebEngineView(parent);
    QWebChannel * channel = new QWebChannel(parent);
    view->page()->setWebChannel(channel);
    channel->registerObject(QString("webobj"), this);
    view->load(QUrl("qrc:/graph/PlotlyGraph.html"));
    ui->gridLayout->addWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::jscallme(const QString &datafromjs)
{
    QMessageBox::information(NULL,"jscallme","I'm called by js!");
    m_data=datafromjs;
    qDebug() << "getting data.." << datafromjs;
}


void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "button clicked!";
    qDebug() << "emitting function" << m_data;
   emit dataChanged(m_data);
}
