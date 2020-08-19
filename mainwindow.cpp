#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initPieChart();

    m_centerLabel = new QLabel("80%", ui->chartViewPie);
    m_centerLabel->setStyleSheet(QString("background:transparent;font-family:\"Mircsoft Yahei\";"
                                         "font-size:20px; color:#1564FF; font-weight:bold;"));
    m_centerLabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_centerLabel->move((ui->chartViewPie->width()-m_centerLabel->width())/2,
                        (ui->chartViewPie->height()-m_centerLabel->height())/2-5);
}

void MainWindow::initPieChart()
{
    QChart *chart = new QChart();

    chart->setTitle("Pie chart演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewPie->setChart(chart);

    ui->chartViewPie->setRenderHint(QPainter::Antialiasing);

}

void MainWindow::bulidPieChart(int percent)
{
    QChart *chart = ui->chartViewPie->chart();
    chart->removeAllSeries();

    ui->chartViewPie->setRenderHint(QPainter::NonCosmeticDefaultPen);
    QPieSeries *series = new QPieSeries();//创建饼图序列
    series->setHoleSize(0.25);//饼图中间空心的大小
    series->setPieSize(0.5);//饼图的大小

    int halfRemainAngle = (1.0 - percent / 100.0) * 360 / 2;
    int startAngle = halfRemainAngle;
    int endAngle = 360 - halfRemainAngle;
    series->setPieStartAngle(startAngle);
    series->setPieEndAngle(endAngle);

    series->append(QString("数据块2"), 10);

    QPieSlice *slice;//饼图分块
    for(int i=0; i<1; i++)
    {
        slice = series->slices().at(i);
        slice->setColor(Qt::gray);
        slice->setLabel(slice->label()+QString::asprintf(":%.0f人, %.1f%%",
                                                         slice->value(), slice->percentage()*100));
    }

    series->setLabelsVisible(true);//必须添加完slice之后在设置
    chart->addSeries(series);//添加饼图序列
    chart->setTitle("Piechart ----");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    m_centerLabel->show();
    resizeEvent(NULL);

}

void MainWindow::on_pushButton_clicked()
{
    bulidPieChart();
}
