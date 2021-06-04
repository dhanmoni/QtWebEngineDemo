#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QPushButton>
#include <QMessageBox>
#include <QWebChannel>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<XYValue>("XYValue");
    QWebEngineView* view = new QWebEngineView(parent);
    QWebChannel * channel = new QWebChannel(this);
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

     QJsonArray x_val;
     QJsonArray y_val;

     x_val.push_back(2);
     x_val.push_back(4);
     x_val.push_back(6);
     x_val.push_back(9);
     y_val.push_back(15);
     y_val.push_back(4);
     y_val.push_back(13);
     y_val.push_back(17);

     QJsonObject xy_vals;
     xy_vals [ "x_val" ] = x_val;
     xy_vals [ "y_val" ] = y_val;


     QJsonObject obj;
     obj [ "plottingData" ] = xy_vals;

     //to see the JSON output
     QJsonDocument doc ( obj );
     qDebug() << doc.toJson ( QJsonDocument::Compact );

     //emit signal
     emit dataChanged(obj);
}


void MainWindow::on_AddLine_clicked()
{
    QJsonArray x_val;
    QJsonArray y_val;

    qDebug() << "add line button clicked!" << ui->xValues->text();
    QStringList xData = ui->xValues->text().split(",");
    QStringList yData = ui->yValues->text().split(",");

    foreach(QString num, xData)
    {
        x_val.push_back(num.toInt());
    }
    foreach(QString num, yData)
    {
        y_val.push_back(num.toInt());
    }

    QJsonObject xy_vals;
    xy_vals [ "x_val" ] = x_val;
    xy_vals [ "y_val" ] = y_val;


    QJsonObject obj;
    obj [ "plottingData" ] = xy_vals;

    emit dataChanged(obj);
}
