#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString data MEMBER m_data NOTIFY dataChanged)
    Q_PROPERTY(int num MEMBER m_num NOTIFY dataChanged)
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void jscallme(const QString &datafromjs);
    void on_pushButton_2_clicked();
signals:
    void dataChanged(const QString & data,const int & num);

private:
    Ui::MainWindow *ui;
     QString m_data;
     int m_num;
};
#endif // MAINWINDOW_H
