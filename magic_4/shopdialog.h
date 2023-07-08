#ifndef SHOPDIALOG_H
#define SHOPDIALOG_H
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFont>
//#include<main_windows.h>
class ShopDialog : public QDialog
{
    Q_OBJECT
public:
    QPushButton *btnAttack ;
    QPushButton *btnDefense ;
    QPushButton *btnHealth ;
    QPushButton *levelup;
    QPushButton *btnExit ;
    QVBoxLayout *layout;


    ShopDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle("商店");
        this->resize(700,700);
        setWindowModality(Qt::ApplicationModal);
        layout = new QVBoxLayout;
        QFont font("Arial",30);
        btnAttack = new QPushButton("被正态了，增加3点攻击力----20rmb");
        btnDefense = new QPushButton("和游客顶撞，增加3点防御力-----20rmb");
        btnHealth = new QPushButton("吃一口“偷火锅”，增加100点生命值-----20rmb");
        btnExit = new QPushButton("退出商店");
        levelup=new QPushButton("三相之力！增加三点攻击三点防御100点生命----50rmb");
        QVideoWidget *videoWidget = new QVideoWidget;
        layout->addWidget(videoWidget);

        // 创建一个QMediaPlayer对象并设置视频源
        QMediaPlayer *player = new QMediaPlayer;
        player->setSource(QUrl("qrc:/beautiful_background.mp4"));
        player->setVideoOutput(videoWidget);
        player->play();
        btnAttack->setFont(font);
        btnDefense->setFont(font);
        btnHealth->setFont(font);
        levelup->setFont(font);
        btnExit->setFont(font);
        layout->addWidget(btnAttack);
        layout->addWidget(btnDefense);
        layout->addWidget(btnHealth);
        layout->addWidget(levelup);
        layout->addWidget(btnExit);

        setLayout(layout);



    }

};

#endif // SHOPDIALOG_H
