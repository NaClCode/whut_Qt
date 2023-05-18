#ifndef _WELCOME_
#define _WELCOME_
#include<ui_welcome.h>
#include<QMouseEvent>
#include<QTimer>
#include<QPaintEvent>
class Qwelcome : public QDialog {
    Q_OBJECT
    
public:
    Qwelcome(QDialog* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~Qwelcome();
private:
    Ui::Dialog *ui;


    bool is_drag = false;
    QPoint mouse_start;
    QPoint window_start;

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
#endif
