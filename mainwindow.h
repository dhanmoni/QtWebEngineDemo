#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct XYValue
{
    QVector<int> xValues;
    QVector<int> yValues;
};
Q_DECLARE_METATYPE(XYValue)

class MainWindow : public QMainWindow
{
    Q_OBJECT
//    Q_PROPERTY(QString data MEMBER m_data NOTIFY dataChanged)
//    Q_PROPERTY(int num MEMBER m_num NOTIFY dataChanged)
//    Q_PROPERTY(QVector<int> xValues MEMBER m_xValues NOTIFY dataChanged)
//    Q_PROPERTY(QVector<int> yValues MEMBER m_yValues NOTIFY dataChanged)
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void jscallme(const QString &datafromjs);
    void on_pushButton_2_clicked();
    void on_AddLine_clicked();
signals:
    //void dataChanged(const QVector<int> & xValues,const QVector<int> & yValues);
    void dataChanged(const QJsonObject & val);
private:
    Ui::MainWindow *ui;
     QString m_data;
     int m_num;
//     QVector<int> m_xValues;
//     QVector<int> m_yValues;
};
#endif // MAINWINDOW_H
