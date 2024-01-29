#include "mdkplayer.h"
#include <QTimer>
#include <QWidget>
#include<QVBoxLayout>

mdkplayer::mdkplayer(QWidget* parent)
    : QMainWindow(parent)
{
    resize(800,600);

     QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
  
    // 创建一个布局
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  
   


    qmdkwidget_ = new QMDKWidget(this);
    qmdkwidget_->resize(400,300);

    play_btn_ = new QPushButton("play", this);
    stop_btn_ = new QPushButton("stop", this);

    // 将按钮添加到布局中
    layout->addWidget(qmdkwidget_);
    layout->addWidget(play_btn_);
    layout->addWidget(stop_btn_);

    connect(play_btn_, &QPushButton::clicked, [=](){
        pthred_ = new std::thread(std::bind(&mdkplayer::run, this));
    });

    connect(stop_btn_, &QPushButton::clicked, [=](){
       qmdkwidget_->pause();
    });
}

mdkplayer::~mdkplayer()
{
    if(qmdkwidget_) {
        delete qmdkwidget_;
        qmdkwidget_ = nullptr;
    }
}

void mdkplayer::run() 
{
    qmdkwidget_->setMedia("D:/work/ffmpeg_rtsp/build/second.mp4");
    qmdkwidget_->play();
    QTimer t;
    t.setInterval(100);
    t.callOnTimeout([&]{
        const auto pos = qmdkwidget_->position()/1000;
        qmdkwidget_->setWindowTitle(QString("%1:%2:%3").arg(pos/3600, 2, 10, QLatin1Char('0')).arg((pos%3600) / 60, 2, 10, QLatin1Char('0')).arg(pos % 60, 2, 10, QLatin1Char('0')));
    });
    t.start();
}