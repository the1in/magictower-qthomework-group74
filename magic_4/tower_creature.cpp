#include"tower_creature.h"
#include"my_Dialog.h"
#include <QMessageBox>
#include <game.h>
#include<cstdlib>
QString ques_1[8]={"家瑛姐最美","程设最恶心","北大世一大","我有对象啦",
    "家瑛家瑛，我爱家瑛！","小点声！，别让老师听见了！","听你这么说，你很勇哦？","天亮啦，别做梦啦！"};
QString ques_2[8]={"构造函数必须返回当前对象","常量成员函数不能修改任何成员变量，包括静态成员变量",
                     "重载赋值运算符“=”可以重载为全局函数","()运算符不能重载为友元函数",
                     "你是猪吗？","回家种田！","家瑛姐姐：“待会来我办公室！”","你可真是个机灵鬼"};
QString ques_3[8]={"派生类的成员函数可以访问继承自基类的private成员变量","派生类的成员函数可以访问其他基类对象的protected成员变量","派生类的成员函数可以访问其他同类对象的private成员变量"
,"基类的成员函数可以访问派生类的protected成员变量","真聪明！","这都能错！","不对，再想想！","不是哦"
};
hero::hero()
{
    money=0;
    life=1000000;
    power=10000;
    defense=10000;
    music_path[0]="qrc:/cxk.mp3";
    music_path[1]="qrc:/xue_1.mp3";
    music_path[2]="qrc:/xue_2.mp3";

    yellow_key_number=0;red_key_number=0;blue_key_number=0;
}
void hero::blood_increase(){
    life+=100;
}
void hero::blood_decrease(){
    life-=50;
}
void hero::shopper_life(){

}
void hero::shopper_attack(){

}
void hero::shopper_defense(){

}
void chenshe_1(){
    CustomDialog_monster1 *dialog=new CustomDialog_monster1(ques_1);
    dialog->exec();
    delete dialog;
}
void hero::chenshe_2(){
    CustomDialog_monster2 *dialog=new CustomDialog_monster2(ques_2,"D");
    dialog->exec();
    delete dialog;
}
void hero::chenshe_3()
{
    CustomDialog_monster2 *dialog=new CustomDialog_monster2(ques_3,"A");
    dialog->exec();
    delete dialog;
}


bool hero::fight(base_creature *aa){
    int hero_life=life;
    int monster_life=aa->life;
    int monster_power=aa->power;
    int monster_defense=aa->defense;
    if(power>monster_defense){
        while(hero_life>0&&monster_life>0){
            monster_life-=(power-monster_defense);
            if(monster_life>0){
                hero_life-=fmax(0,monster_power-defense);
            }
        }
        //打完了
        if(hero_life>0){
            int tempmoney=rand()%6+1;
            money+=tempmoney;
            if(meet_monster)
                meet_monster++;
            if(meet_monster==0){//第一个对话框选择题
                meet_monster++;

                chenshe_1();
            }
            if(meet_monster==7){//第二个对话框选择题
                this->chenshe_2();
                if(question_right_or_true)
                {this->life+=100;
                    hero_life+=100;}
                else
                {this->life-=50;
                    hero_life-=50;}
                question_right_or_true=false;
                //meet_monster++;
            }
            if(meet_monster==14){//小游戏
                //return 1;
                Game_random *game=new Game_random;
                game->show();
                game->exec();
                if(game->win_or_lose==true){
                    hero_life+=30;
                    this->power+=10;
                    this->defense+=10;
                }
                else{
                    hero_life-=10;
                    this->power-=5;
                    this->defense-=5;
                }
            }
            if(meet_monster==21){//第三个对话框选择题
                this->chenshe_3();
                if(question_right_or_true)
                {this->life+=100;
                    hero_life+=100;}
                else
                {this->life-=50;
                    hero_life-=50;}
                question_right_or_true=false;
                //meet_monster++;
            }
            //return 1;
            player_1=new QMediaPlayer;
            int random_num=QRandomGenerator::global()->bounded(0,5);
            audioOutput_1=new QAudioOutput;
            player_1->setAudioOutput(audioOutput_1);
            player_1->setSource(QUrl(music_path[random_num]));
            audioOutput_1->setVolume(5);//音量
            player_1->play();
            life = hero_life;
            meet_monster++;
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}
skeleton::skeleton()
{
    life=200;
    power=30;
    defense=20;
}
bigskeleton::bigskeleton()
{
    life=300;
    power=40;
    defense=30;
}
red_slime::red_slime()
{
    life=100;
    power=18;
    defense=15;
}
green_slime::green_slime()
{
    life=100;
    power=15;
    defense=10;
}
bat::bat()
{
    life=100;
    power=50;
    defense=10;
}
ghost::ghost()
{
    life=200;
    power=60;
    defense=10;
}
boss::boss()
{
    life=200;
    power=50;
    defense=50;
}
armedskeleton::armedskeleton()
{
    life=400;
    power=50;
    defense=40;
}
bigslime::bigslime()
{
    life=800;
    power=30;
    defense=30;
}
stonemonster::stonemonster()
{
    life=600;
    power=20;
    defense=80;
}
redbat::redbat()
{
    life=300;
    power=60;
    defense=20;
}
sandguy::sandguy()
{
    life=600;
    power=35;
    defense=30;
}
angryguy::angryguy()
{
    life=500;
    power=55;
    defense=40;
}
redmaster::redmaster()
{
    life=600;
    power=70;
    defense=15;
}
bluebat::bluebat()
{
    life=200;
    power=65;
    defense=15;
}
royalguy::royalguy()
{
    life=600;
    power=60;
    defense=40;
}
redroyalguy::redroyalguy()
{
    life=800;
    power=70;
    defense=50;
}
berserker::berserker()
{
    life=1000;
    power=80;
    defense=60;
}
redeye::redeye()
{
    life=800;
    power=60;
    defense=50;
}
whitehelmet::whitehelmet()
{
    life=1000;
    power=70;
    defense=60;
}
redall::redall()
{
    life=800;
    power=50;
    defense=50;
}
