#pragma once
#include <QMainWindow>
#include <QPushButton>
#include "QMDKWidget.h"
#include <thread>

class mdkplayer : public QMainWindow {
    Q_OBJECT

public:
    mdkplayer(QWidget* parent = nullptr);
    ~mdkplayer();

private:
    void run();

private:
    QMDKWidget* qmdkwidget_;
    QPushButton* play_btn_;
    QPushButton* stop_btn_;
    // QPushButton* play_btn_;
    std::thread* pthred_;

};