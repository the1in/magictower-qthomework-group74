#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include<QLabel>
#include<QPushButton>
#include<QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
//#include"widget.h"
//实现主菜单，包括“开始”，“退出”，“留言”，“背景”
class main_menu:public QObject{
    Q_OBJECT
public:
    QPushButton *p[4];
    explicit main_menu();
    void hide();
    void show();
    QMediaPlayer *opening;
    QAudioOutput*opening_out;
private:
    QWidget *widget;
};

#endif // MAIN_MENU_H
