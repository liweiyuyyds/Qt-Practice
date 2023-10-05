#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_readDataButton_clicked();

    void on_saveDataButton_clicked();

    void on_dynamicRadioButton_clicked();

    void on_staticRadioButton_clicked();

    void timeOutAction();
private:
    Ui::Widget *ui;

    QStringList m_csv_list;
    QVector<QPointF> m_wave_point_buffer;

    int m_origin_list_index;
    bool m_first_draw;
    QTimer* m_draw_wave_timer;

    QLineSeries* m_series;
    QValueAxis* m_axis_x;
    QValueAxis* m_axis_y;
    QChart* m_wave_line_chart;

private:
   void initWaveLineChart();
   void drawWave(int axis_x,qint16 data);
};
#endif // WIDGET_H
