#ifndef MY_LABEL_H
#define MY_LABEL_H
#include <QLabel>

class my_label:public QLabel{
    Q_OBJECT
    private:
    QString pic_path;
    public:
        my_label(QString a,QWidget *parent);
        my_label(QWidget *parent);
        my_label();
        void set_pic();
        void set_Position(int x,int y,int width,int height);

};
#endif // MY_LABEL_H


