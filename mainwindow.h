#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    void initPieChart();

    void bulidPieChart(int percent = 80);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *m_centerLabel;
};

#endif // MAINWINDOW_H
