#ifndef MAIN_WINDOWS_H
#define MAIN_WINDOWS_H
#include "shopdialog.h"
#include "my_label.h"
#include "main_menu.h"
#include "tower_creature.h"
#include <QKeyEvent>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QVideoWidget>
#include<QPropertyAnimation>
class main_windows : public QMainWindow{
    Q_OBJECT
public:
    explicit main_windows(QMainWindow *parent=nullptr);
    void move(int a,int b);
    int now_text;
    QLabel *textLabel;
    int floorflag=-1;
    QString floorbgmpath[10];
    bool isstart=false;
    ShopDialog *shopper;
    bool hidefirst=true;
    void get_pic(int i,int j);
protected:
    void keyPressEvent(QKeyEvent *event)override;
private:
    QTimer *mo_yu;
    my_label *label[14][20];
    QLabel *label_back;
    main_menu w;
    QWidget *background;
    my_label *imageLabel[10];
    QPushButton *backButton;
    hero *my_hero;
    base_creature *NPC[30];
    my_label *hp_pw_df[20];
    my_label *attribute;
    QMediaPlayer *floorbgm;
    QAudioOutput*floorbgm_out;
    QMediaPlayer *playerv;
    QVideoWidget* videoWidget;

public slots:
    void show_attribute();//属性s
    void show_pic();
    void my_quit();
    void show_background();
    void back_to_menu();
    void add_now_text();
    void handleKeyPress();
    void mo_yu_video();
    void getsignal1();
    void getsignal2();
    void getsignal3();
    void getsignal4();
    void getsignal5();
signals:

    void buttonclicked();
    void shit();
};
#endif // MAIN_WINDOWS_H
