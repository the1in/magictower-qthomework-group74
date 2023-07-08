#ifndef TOWER_CREATURE_H
#define TOWER_CREATURE_H
#include <QLabel>
#include <QCoreApplication>
#include <QThread>
#include <QMediaPlayer>
#include <QAudioOutput>


class none_life:public QLabel{
    Q_OBJECT
};

class base_creature:public none_life{
    Q_OBJECT
public:
    int life;
    int power;
    int defense;
    int get_life();
    int get_power();
    int get_defense();
};
class null:public none_life{
public:
    //0;
    null(){}
};


class brown_wall:public none_life{
public:
    //1;
    brown_wall(){}
};
class door:public none_life{
public:
    //2;
    door(){}
};
class stair_up:public none_life{
public:
    //3
    stair_up(){}
};
class stair_down:public none_life
{
public:
    //4
    stair_down(){}
};
class key:public none_life{
public:
    //5;
    key(){}
};
class blood_bottle:public none_life
{
public:
    //6
    blood_bottle(){blood_up=100;}
    int blood_up;
};
class red_stone:public none_life{
public:
    //7;
    red_stone(){attack_up=100;}
    int attack_up;
};
class blue_stone:public none_life{
public:
    //8;
    blue_stone(){defense_up=100;}
    int defense_up;
};
class hero:public base_creature{
    Q_OBJECT
public:
    int money;
    int yellow_key_number;
    int red_key_number;
    int blue_key_number;
    int meet_monster=0;
    int get_yellow_key() { return yellow_key_number; }
    int get_blue_key() { return blue_key_number; }
    int get_red_key() { return red_key_number; }
    bool fight(base_creature *aa);
    hero();
    void chenshe_2();
    void chenshe_3();
    QString music_path[10];
    QMediaPlayer *player_1;
    QAudioOutput *audioOutput_1;
public slots:
    void blood_increase();
    void blood_decrease();
};
class skeleton:public base_creature{
public:
    //20
    skeleton();
};
class bigskeleton:public base_creature{
public:
    //21;
    bigskeleton();
};
class red_slime:public base_creature{
public:
    //23;
    red_slime();
};
class green_slime:public base_creature
{
public:
    //22
    green_slime();
};
class bat:public base_creature{
public:
    //24;
    bat();
};
class ghost:public base_creature{
public:
    //25;
    ghost();
};
class boss:public base_creature{
public:
    //26
    boss();
};
class armedskeleton:public base_creature
{
public  :
    //42
    armedskeleton();
};
class bigslime:public base_creature
{
public:
    //51
    bigslime();
};
class stonemonster:public base_creature
{
public:
    //52
    stonemonster();
};
class redbat:public base_creature
{
public:
    //53
    redbat();
};
class sandguy :public base_creature
{
public:
    //54
    sandguy();
};
class angryguy:public base_creature
{
public:
    //55
    angryguy();
};
class redmaster:public base_creature
{
public:
    //56
    redmaster();
};
class bluebat:public base_creature
{
public:
    //57
    bluebat();
};
class royalguy:public base_creature
{
public:
    //61
    royalguy();
};
class redroyalguy:public base_creature
{
public:
    //62
    redroyalguy();
};
class berserker:public base_creature
{
public:
    //63
    berserker();
};
class royalmaster:public base_creature
{
public:
    //64,这位是boss
    royalmaster();
};
class redeye:public base_creature
{
public:
    //65
    redeye();
};
class whitehelmet:public base_creature
{
public:
    //66
    whitehelmet();
};
class redall:public base_creature
{
public:
    //67
    redall();
};


#endif // TOWER_CREATURE_H
