#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QPushButton>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket * socket;
private slots:
    void readFromServer();
    void onGroupButtonClicked(int id);
    void on_pushButton_21_clicked();
    QChar set_mode();
};

#endif // MAINWINDOW_H
