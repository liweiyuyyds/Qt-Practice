#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("波形处理小工具"));
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

    ui->procDataProgressBar->setVisible(false);

    initWaveLineChart();

    m_origin_list_index=0;
    m_first_draw=true;
    m_draw_wave_timer=new QTimer(this);
    connect(m_draw_wave_timer,SIGNAL(timeout()),this,SLOT(timeOutAction()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initWaveLineChart()
{
    m_axis_x = new QValueAxis();
    m_axis_y = new QValueAxis();
    m_series = new QLineSeries();
    m_wave_line_chart=new QChart();

    m_wave_line_chart->addSeries(m_series);
    m_axis_x->setRange(0,2048);
    m_axis_y->setRange(0,4096);

    m_axis_x->setGridLineVisible(false);
    m_axis_y->setGridLineVisible(false);

    m_axis_x->setLabelsVisible(false);
    m_axis_y->setLabelsVisible(false);

    m_wave_line_chart->addAxis(m_axis_x,Qt::AlignBottom);
    m_wave_line_chart->addAxis(m_axis_y,Qt::AlignLeft);

    m_series->attachAxis(m_axis_x);
    m_series->attachAxis(m_axis_y);
    m_series->setColor(QColor(Qt::black));

    m_wave_line_chart->layout()->setContentsMargins(0,0,0,0);
    m_wave_line_chart->setMargins(QMargins(0,0,0,0));
    m_wave_line_chart->setBackgroundRoundness(0);
    m_wave_line_chart->legend()->hide();
    ui->waveGraphicsView->setChart(m_wave_line_chart);
}

void Widget::timeOutAction()
{
    qDebug()<<"timer action";
    if(m_origin_list_index>(m_csv_list.length()-1))
    {
        m_origin_list_index=0;
        m_first_draw=false;
    }
    qint16 temp_int16=m_csv_list.at(m_origin_list_index).toInt();
    qDebug() << temp_int16;
    drawWave(m_origin_list_index,temp_int16);
    m_origin_list_index++;
}

void Widget::drawWave(int axis_x,qint16 data)
{
    int times_counts=axis_x/2048;
    if(times_counts>0||m_first_draw==false)
    {
        axis_x=axis_x-times_counts*2048;
        m_wave_point_buffer[axis_x].setY(data);
    }
    else
    {
        m_wave_point_buffer.append(QPointF(axis_x,data));
    }
    m_series->replace(m_wave_point_buffer);
}

void Widget::on_readDataButton_clicked()
{
    QString read_data_string;
    int i=0;
    QString file_name = QFileDialog::getOpenFileName(this,tr("Open File"),"","CSV Files(*.csv)");
    if(!file_name.isNull())
    {
        qDebug()<<file_name;
        QFile csv_file(file_name);
        m_csv_list.clear();

        if(csv_file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&csv_file);
            while(!stream.atEnd())
            {
                m_csv_list.push_back(stream.readLine());
            }
            csv_file.close();
        }
    }

    ui->procDataProgressBar->setRange(0,m_csv_list.length()-1);
    ui->procDataProgressBar->setValue(0);
    ui->procDataProgressBar->setVisible(true);

    foreach (auto str, m_csv_list)
    {
        ui->procDataProgressBar->setValue(i);
        i++;
        read_data_string+=str+" ";
    }
    ui->procDataProgressBar->setVisible(false);
    ui->dataPlainTextEdit->clear();
    ui->dataPlainTextEdit->appendPlainText(read_data_string);

    m_wave_point_buffer.clear();

    ui->staticRadioButton->setChecked(true);

    if(m_csv_list.length()>=2048)
    {
        for(int j=0;j<2048;j++)
        {
            m_wave_point_buffer.append(QPointF(j,m_csv_list.at(j).toInt()));
        }
    }
    else
    {
        for(int k=0;k<m_csv_list.length();k++)
        {
            m_wave_point_buffer.append(QPointF(k,m_csv_list.at(k).toInt()));
        }
    }
    m_series->replace(m_wave_point_buffer);
}


void Widget::on_saveDataButton_clicked()
{
    QString file_name=QFileDialog::getSaveFileName(this,tr("save file"),"",tr("CSV Files(*.csv)"));
    QStringList save_string;
    int i;

    if(!file_name.isNull())
    {
        qDebug()<<file_name;
        QFile file(file_name);
        save_string=ui->dataPlainTextEdit->toPlainText().split(" ");
        if(file.open(QFile::WriteOnly|QFile::Text))
        {
            QTextStream out(&file);
            ui->procDataProgressBar->setRange(0,save_string.length()-1);
            ui->procDataProgressBar->setValue(0);
            ui->procDataProgressBar->setTextVisible(true);

            foreach(auto str,save_string)
            {
                out<<str+"\n";
                ui->procDataProgressBar->setValue(i);
                i++;
            }
            ui->procDataProgressBar->setVisible(false);
            file.close();
        }
    }
}


void Widget::on_dynamicRadioButton_clicked()
{
    qDebug()<<"dynamic radiobutton click";
    if(m_csv_list.length()==0)
    {
        return;
    }

    if(!m_draw_wave_timer->isActive())
    {
        m_origin_list_index=0;
        m_first_draw=true;
        m_draw_wave_timer->start(1);
        m_wave_point_buffer.clear();
    }
}


void Widget::on_staticRadioButton_clicked()
{
    qDebug()<<"static radiobutton click";
    if(m_draw_wave_timer->isActive())
    {
        m_draw_wave_timer->stop();
        m_wave_point_buffer.clear();

        if(m_csv_list.length()>=2048)
        {
            for(int i=0;i<2048;i++)
            {
                m_wave_point_buffer.append(QPointF(i,m_csv_list.at(i).toInt()));
            }
        }
        else
        {
            for(int i=0;i<m_csv_list.length();i++)
            {
                m_wave_point_buffer.append(QPointF(i,m_csv_list.at(i).toInt()));
            }
        }
        m_series->replace(m_wave_point_buffer);
    }
}

