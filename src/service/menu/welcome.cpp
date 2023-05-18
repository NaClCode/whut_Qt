#include "include/service/menu/welcome.h"
#include<QPainter>
#include<QBitmap>
#include<QTimer>
Qwelcome::Qwelcome(QDialog *parent): QDialog(parent), ui(new Ui::Dialog){
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Qwelcome::~Qwelcome(){
    delete ui;
}


void Qwelcome::paintEvent(QPaintEvent* event){
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRoundedRect(bmp.rect(), 50, 50);
    setMask(bmp);
}

void Qwelcome::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        is_drag = true;
        mouse_start = event->globalPos();
        window_start = this->frameGeometry().topLeft();
    }
}

void Qwelcome::mouseMoveEvent(QMouseEvent *event){
    if (is_drag){
        QPoint move_distance = event->globalPos() - mouse_start;
        this->move(window_start + move_distance);
    }
}

void Qwelcome::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        is_drag = false;
    }
}


