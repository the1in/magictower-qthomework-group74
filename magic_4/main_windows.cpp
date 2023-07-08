#include<QFont>
#include<QString>
#include<QPixmap>
#include<unistd.h>
#include<QString>
#include<QPalette>
#include<QFrame>
#include<iostream>
#include<QPushButton>
#include<QApplication>
#include<QDebug>
#include"main_windows.h"
#include<QParallelAnimationGroup>
#include"maps.h"
#include<QShortcut>
#include<QPropertyAnimation>
#include<QTimer>
#include<QThread>
#include<QFileDialog>
#include<QVBoxLayout>
#include<QGraphicsOpacityEffect>
#include<QMovie>
using namespace std;
QString text[10];
QString picture_path[10]={"",":/final_dialog_1.png",":/final_dialog_2.png",
    ":/final_dialog_3.png",":/final_dialog_4.png",":/final_dialog_5.png",
     ":/final_dialog_6.png",":/final_dialog_7.png",
     ":/final_dialog_8.png"};
bool buff=false;
main_windows::main_windows(QMainWindow *parent):
    QMainWindow(parent)
{
    //属性面板

    mo_yu=new QTimer;
    mo_yu->setInterval(4000);
    mo_yu->setSingleShot(true);

    connect(mo_yu, &QTimer::timeout, this, &main_windows::mo_yu_video);//3s到了播放视频
    connect(this, &main_windows::shit, this, &main_windows::handleKeyPress);
    attribute=new my_label;
    QPixmap pixmap(":/attribute.png"); // 替换为实际的图片路径
    attribute->setPixmap(pixmap);
    attribute->set_Position(69,69,750,750);
    QShortcut* shortcutP = new QShortcut(QKeySequence(Qt::Key_P), attribute);
    connect(shortcutP, &QShortcut::activated, this, &main_windows::show_attribute);
    connect(w.p[0],SIGNAL(clicked()),this,SLOT(show_pic()));
    connect(w.p[1],SIGNAL(clicked()),this,SLOT(my_quit()));
    connect(w.p[2],SIGNAL(clicked()),this,SLOT(show_background()));
    this->setGeometry(100,100,1000,1000);//(横坐标，纵坐标，长，宽)
    NPC[0]=new skeleton();
    NPC[1]=new bigskeleton();
    NPC[2]=new green_slime();
    NPC[3]=new red_slime();
    NPC[4]=new bat();
    NPC[5]=new ghost();
    NPC[6]=new boss();
    NPC[7]=new armedskeleton();
    NPC[8]=new bigslime();
    NPC[9]=new stonemonster();
    NPC[10]=new redbat();
    NPC[11]=new sandguy();
    NPC[12]=new angryguy();
    NPC[13]=new redmaster();
    NPC[14]=new bluebat();
    NPC[15]=new royalguy();
    NPC[16]=new redroyalguy();
    NPC[17]=new berserker();
  //  NPC[18]=new royalmaster();
    NPC[19]=new redeye();
    NPC[20]=new whitehelmet();
    NPC[21]=new redall();
\

    my_hero= new hero;
    floorbgmpath[0]="qrc:/floor1.mp3";
    floorbgmpath[1]="qrc:/floor2.mp3";
    floorbgmpath[2]="qrc:/floor1.mp3";
    floorbgmpath[3]="qrc:/floor2.mp3";

    //show_pic();
    //this->show();
    //商人属性
    this->resize(1000,700);

    shopper=new ShopDialog;
    connect(shopper->btnAttack,&QPushButton::clicked,this,&main_windows::getsignal1);
    connect(shopper->btnDefense,&QPushButton::clicked,this,&main_windows::getsignal2);
    connect(shopper->btnHealth,&QPushButton::clicked,this,&main_windows::getsignal3);
    connect(shopper->btnExit,&QPushButton::clicked,this,&main_windows::getsignal4);
    connect(shopper->levelup,&QPushButton::clicked,this,&main_windows::getsignal5);
    //打魔王时的图片预加载

    qDebug()<<"初始化";

}
void main_windows::getsignal1()
{
    //my_hero->money+=50;
    if(my_hero->money>=20)
    {
        my_hero->money-=20;
        my_hero->power+=3;
    }
    show_pic();
}
void main_windows::getsignal2()
{
    //my_hero->money+=50;
    if(my_hero->money>=20)
    {
        my_hero->money-=20;
        my_hero->defense+=3;
    }
    show_pic();
}
void main_windows::getsignal3()
{
    //my_hero->money+=50;
    if(my_hero->money>=20)
    {
        my_hero->money-=20;
        my_hero->life+=100;
    }
    show_pic();
}
void main_windows::getsignal4()
{
    shopper->hide();
}
void main_windows::getsignal5()
{
    if(my_hero->money>=50)
    {
        my_hero->money-=50;
        my_hero->power+=3;
        my_hero->defense+=3;
        my_hero->life+=100;
    }
    show_pic();
}
void main_windows::show_attribute(){
    click_time++;
    if((click_time%2)==1){
        attribute->show();
    }
    else{
        qDebug()<<1;
        attribute->hide();
    }
}
void main_windows::mo_yu_video(){
    QMovie *movie = new QMovie(":/beautiful.gif");
    label[hero_x][hero_y]->setMovie(movie);
    movie->start();
    //label[hero_x][hero_y] ->set_pic();
    label[hero_x][hero_y] ->set_Position(50*hero_y,50*hero_x,50,50);
    label[hero_x][hero_y] ->show();
}
void main_windows::handleKeyPress() {
    if (mo_yu->isActive()) {
        mo_yu->stop();  // 停止计时器
    }
    mo_yu->start(3000);  // 从零开始计时并设置时间间隔为3秒
    mo_yu->setSingleShot(true);
}
void main_windows::add_now_text(){
    now_text=(now_text+1)%5;
    textLabel->setText(text[now_text]);
}
void main_windows::show_background(){
    w.hide();

    background = new QWidget;
    //background->setWindowFlags(Qt::FramelessWindowHint);
    background->setWindowTitle("背景故事");
    background->setGeometry(100,100,450,800);


    QLabel* gifLabel = new QLabel(background);
    gifLabel->setGeometry(0, 0, 450, 800);

    QMovie* movie = new QMovie(":/bigpower.gif");
    gifLabel->setMovie(movie);



    textLabel=new QLabel(this->background);
    QFont font("Arial",30);
    textLabel->setFont(font);
    QPalette gpalette;
    gpalette.setColor(QPalette::WindowText, Qt::white); // 设置文本颜色为红色
    background->setPalette(gpalette);
    QMediaPlayer *opening=new QMediaPlayer;
    QAudioOutput *opening_out=new QAudioOutput;
    opening->setAudioOutput(opening_out);
    opening->setSource(QUrl("qrc:/bigpower.mp3"));
    opening_out->setVolume(5);//音量
    opening->setLoops(-1);
    opening->play();





    now_text=0;
    text[0]="事情要追溯到遥远的1898，<br>"
              "彬彬来到了北京大学里的塔防游戏";
    text[1]="在这里他遇见了他的小伙伴：<br>"
              "坤哥，亡灵凯，盯针，大例王……";
    text[2]="他们会在这里遇到什么样的冒险？<br>"
              "他们会在这里获得怎样的经历？";
    text[3]="让我们开始游戏，进入魔塔！<br>"
              "一同随它的小伙伴来探险吧！";
    text[4]="未完待续…………";
    textLabel->setText(text[now_text]);
    textLabel->raise();
    // 计算文本滚动的起始位置和结束位置
    int startPos = background->width();
    int endPos = -background->width();
    // 创建属性动画，控制 QLabel 的 x 坐标
    QPropertyAnimation* animation = new QPropertyAnimation(textLabel, "geometry");
    animation->setDuration(5000);  // 动画持续时间为 5 秒
    animation->setStartValue(QRect(startPos, 0, background->width(), background->height()));
    animation->setEndValue(QRect(endPos, 0, background->width(), background->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
        // 设置动画循环播放
    //我们实现一行一行滚动播放
    animation->setLoopCount(-1);
    // 启动动画

    QTimer *timer=new QTimer;
    timer->start(5100);
    connect(timer,&QTimer::timeout,this,&main_windows::add_now_text);
    animation->start();
    movie->start();









    backButton = new QPushButton("返回主菜单", background);
    backButton->raise();
    backButton->setGeometry(100, background->height() - 200, 200, 200);
    QFont buttonFont("Arial", 35, QFont::Bold);  // 设置字体为Arial，大小为12，加粗
    QPalette buttonPalette;
    buttonPalette.setColor(QPalette::ButtonText, Qt::white);  // 设置文本颜色为蓝色
    backButton->setFont(buttonFont);
    backButton->setPalette(buttonPalette);
    backButton->setStyleSheet("border: none;");  // 设置按钮没有边框
    // 连接按钮的点击事件到一个槽函数，用于处理返回主菜单的逻辑
    connect(backButton,SIGNAL(clicked()),this,SLOT(back_to_menu()));
    connect(backButton,&QPushButton::clicked,opening,&QMediaPlayer::stop);
    background->show();



}
void main_windows::get_pic(int j,int i){
    switch(maps[flood][j][i]){
    case 0:
        label[j][i] = new my_label(":/0.png", this);
        break;
    case 1:
        label[j][i] = new my_label(":/1.png", this);
        break;
    case 2:
        label[j][i] = new my_label(":/2.png", this);
        break;
    case 3:
        label[j][i] = new my_label(":/3.png", this);
        break;
    case 4:
        label[j][i] = new my_label(":/4.png", this);
        break;
    case 5:
        label[j][i] = new my_label(":/5.png", this);
        break;
    case 6:
        label[j][i] =new my_label(":/6.png", this);
        //magicT[j][i]=new blood_bottle();
        break;
    case 7:
        label[j][i] = new my_label(":/7.png", this);
        //magicT[j][i]=new red_stone();
        break;
    case 8:
        label[j][i] = new my_label(":/8.png", this);
        //magicT[j][i]=new blue_stone();
        break;
    case 15:
        label[j][i] = new my_label(":/0.png", this);
        //magicT[j][i]=my_hero;
        break;
    case 20:
        label[j][i] =new my_label(":/20.png", this);
        //magicT[j][i]=new skeleton();
        break;
    case 21:
        label[j][i] = new my_label(":/21.png", this);
        //magicT[j][i]=new bigskeleton();
        break;
    case 22:
        label[j][i] = new my_label(":/22.png", this);
        //magicT[j][i]=new green_slime();
        break;
    case 23:
        label[j][i] = new my_label(":/23.png", this);
        //magicT[j][i]=new red_slime();
        break;
    case 24:
        label[j][i] = new my_label(":/24.png", this);
        //magicT[j][i]=new bat();
        break;
    case 25:
        label[j][i] = new my_label(":/25.png", this);
        //magicT[j][i]=new ghost();
        break;
    case 30:
        label[j][i] = new my_label(":/30.png", this);
        //magicT[j][i]=new boss();
        break;
    case 31:
        label[j][i] = new my_label(":/31.png", this);
        //magicT[j][i]=new boss();
        break;
    case 32:
        label[j][i] = new my_label(":/32.png", this);
        //magicT[j][i]=new boss();
        break;
    case 33:
        label[j][i] = new my_label(":/33.png", this);
        //magicT[j][i]=new boss();
        break;
    case 34:
        label[j][i] = new my_label(":/34.png", this);
        //magicT[j][i]=new boss();
        break;
    case 35:
        label[j][i] = new my_label(":/35.png", this);
        //magicT[j][i]=new boss();
        break;
    case 36:
        label[j][i] = new my_label(":/36.png", this);
        //magicT[j][i]=new boss();
        break;
    case 37:
        label[j][i] = new my_label(":/37.png", this);
        //magicT[j][i]=new boss();
        break;
    case 38:
        label[j][i] = new my_label(":/38.png", this);
        //magicT[j][i]=new boss();
        break;
    case 39:
        label[j][i] = new my_label(":/39.png", this);
        //magicT[j][i]=new boss();
        break;
    case 40:
        label[j][i] = new my_label(":/40.png", this);
        //magicT[j][i]=new boss();
        break;
    case 41:
        label[j][i] = new my_label(":/41.png", this);
        break;
    case 42:
        label[j][i] = new my_label(":/42.png", this);
        break;
    case 43:
        label[j][i] = new my_label(":/leftcash.png", this);
        break;
    case 44:
        label[j][i] = new my_label(":/rightcash.png", this);
        break;
    case 51:
        label[j][i] = new my_label(":/51.png", this);
        //magicT[j][i]=new boss();
        break;
    case 52:
        label[j][i] = new my_label(":/52.png", this);
        //magicT[j][i]=new boss();
        break;
    case 53:
        label[j][i] = new my_label(":/53.png", this);
        //magicT[j][i]=new boss();
        break;
    case 54:
        label[j][i] = new my_label(":/54.png", this);
        //magicT[j][i]=new boss();
        break;
    case 55:
        label[j][i] = new my_label(":/55.png", this);
        //magicT[j][i]=new boss();
        break;
    case 56:
        label[j][i] = new my_label(":/56.png", this);
        //magicT[j][i]=new boss();
        break;
    case 57:
        label[j][i] = new my_label(":/57.png", this);
        //magicT[j][i]=new boss();
        break;
    case 58:
        label[j][i] = new my_label(":/58.png", this);
        //magicT[j][i]=new boss();
        break;
    case 59:
        label[j][i] = new my_label(":/59.png", this);
        //magicT[j][i]=new boss();
        break;
    case 60:
        label[j][i] = new my_label(":/60.png", this);
        //magicT[j][i]=new boss();
        break;
    case 61:
        label[j][i] = new my_label(":/61.png", this);
        //magicT[j][i]=new boss();
        break;
    case 62:
        label[j][i] = new my_label(":/62.png", this);
        //magicT[j][i]=new boss();
        break;
    case 63:
        label[j][i] = new my_label(":/63.png", this);
        //magicT[j][i]=new boss();
        break;
    case 64:
        label[j][i] = new my_label(":/64.png", this);
        //magicT[j][i]=new boss();
        break;
    case 65:
        label[j][i] = new my_label(":/65.png", this);
        //magicT[j][i]=new boss();
        break;
    case 66:
        label[j][i] = new my_label(":/66.png", this);
        //magicT[j][i]=new boss();
        break;
    case 67:
        label[j][i] = new my_label(":/67.png", this);
        //magicT[j][i]=new boss();
        break;
    case 100://movie
        label[j][i] = new my_label(":/0.png", this);
        break;
    case 150:
        label[j][i] = new my_label(":/150.png", this);
        break;
    }

    label[j][i]->show();
    label[j][i]->set_pic();
    label[j][i]->set_Position(50*i,50*j,50,50);
}
void main_windows::back_to_menu(){
    background->hide();
    w.show();
}
void main_windows::my_quit(){
    QApplication::quit();
}

void main_windows::show_pic(){
    //return;
    w.hide();
    if(floorflag!=flood)
    {
        //floorbgm->stop();
        if(isstart)
        {
            delete floorbgm;
            delete floorbgm_out;
        }
        floorbgm=new QMediaPlayer;
        floorbgm_out=new QAudioOutput;
        floorbgm->setAudioOutput(floorbgm_out);
        floorbgm->setSource(QUrl(floorbgmpath[flood]));
        floorbgm->setLoops(-1);
        floorbgm_out->setVolume(0.5);//音量
        floorbgm->play();
        floorflag=flood;
    }
    isstart=true;
    this->setFixedSize(1000,700);
    this->show();
    if(start)for(int j=0;j<14;j++)for(int i=0;i<20;i++){delete label[j][i];}
    for(int j=0;j<14;++j){
        for(int i=0;i<20;i++){
            //cout<<maps[flood][j][i]<<" ";
            get_pic(j,i);
        }

    }
    if(start)delete label[hero_x][hero_y];
    label[hero_x][hero_y] = new my_label(":/15.png", this);
    //cout<<hero_x<<" "<<hero_y<<endl;
    label[hero_x][hero_y] ->set_pic();
    label[hero_x][hero_y] ->set_Position(50*hero_y,50*hero_x,50,50);
    label[hero_x][hero_y] ->show();
    //以上是地图和hero的构建
    //下面构建属性面板
    if(start)for(int i=2;i<12;i++)delete hp_pw_df[i];
    QFont font("Arial",25);
    hp_pw_df[3] = new my_label(this);
    hp_pw_df[3]->setNum(my_hero->yellow_key_number);
    hp_pw_df[3]->set_Position(200,450,100,50);
    hp_pw_df[4] = new my_label(this);
    hp_pw_df[4]->setNum(my_hero->red_key_number);
    hp_pw_df[4]->set_Position(200,450+50,100,50);
    hp_pw_df[5] = new my_label(this);
    hp_pw_df[5]->setNum(my_hero->blue_key_number);
    hp_pw_df[5]->set_Position(200,450+100,100,50);
    hp_pw_df[2] = new my_label(this);
    hp_pw_df[2]->setNum(my_hero->money);
    hp_pw_df[2]->set_Position(200,450+150,100,50);
    for(int i=2;i<6;i++){
        hp_pw_df[i]->setFont(font);
        hp_pw_df[i]->show();
    }
    QFont font2("Arial",25);
    hp_pw_df[6] =new my_label(this);
    hp_pw_df[7] =new my_label(this);
    hp_pw_df[8] =new my_label(this);
    hp_pw_df[9] =new my_label(this);
    hp_pw_df[10] =new my_label(this);
    hp_pw_df[11] =new my_label(this);
    hp_pw_df[6]->setText("生命值");
    hp_pw_df[6]->setFont(font2);
    hp_pw_df[6]->set_Position(50,50,100,50);
    hp_pw_df[6]->show();
    hp_pw_df[7]->setText("攻击力");
    hp_pw_df[7]->setFont(font2);
    hp_pw_df[7]->set_Position(50,50+8*18,100,50);
    hp_pw_df[7]->show();
    hp_pw_df[8]->setText("防御值");
    hp_pw_df[8]->setFont(font2);
    hp_pw_df[8]->set_Position(50,50+16*18,100,50);
    hp_pw_df[8]->show();
    hp_pw_df[9]->setNum(my_hero->life);
    hp_pw_df[9]->set_Position(150,50,100,50);
    hp_pw_df[9]->setFont(font2);
    hp_pw_df[9]->show();
    hp_pw_df[10]->setNum(my_hero->power);
    hp_pw_df[10]->set_Position(150,50+8*18,100,50);
    hp_pw_df[10]->setFont(font2);
    hp_pw_df[10]->show();
    hp_pw_df[11]->setNum(my_hero->defense);
    hp_pw_df[11]->set_Position(150,50+16*18,100,50);
    hp_pw_df[11]->setFont(font2);
    hp_pw_df[11]->show();
    start=true;
    if(maps[flood][hero_x+1][hero_y]==64||maps[flood][hero_x-1][hero_y]==64||maps[flood][hero_x][hero_y-1]==64
        ||maps[flood][hero_x][hero_y-1]==64||maps[flood][hero_x][hero_y+1]==64){
    if(meet_boss){
        meet_boss=false;
        for(int i=1;i<=8;i++){
            if(start_boss)delete imageLabel[i];
            imageLabel[i]=new my_label(picture_path[i],this);
            imageLabel[i]->set_pic();
            //imageLabel[i]->show();
        }
        start_boss=true;
        for(int i=1;i<=8;i++){
            if(i%2==1||i>=5)//魔王
            {
                imageLabel[i]->set_Position(650,120,200,200);
            }
            else{
                imageLabel[i]->set_Position(hero_y*50-150,hero_x*50-70,200,200);
            }
        }
        if(get_the_book==false){
            QTimer::singleShot(1, [&]() {
                imageLabel[1]->show();
            });
            QTimer::singleShot(2000, [&]() {
                imageLabel[1]->hide();
                imageLabel[2]->show();
            });
            QTimer::singleShot(4000, [&]() {
                imageLabel[2]->hide();
                imageLabel[3]->show();
            });
            QTimer::singleShot(7000, [&]() {
                imageLabel[3]->hide();
                imageLabel[4]->show();
            });
            QTimer::singleShot(9000, [&]() {
                imageLabel[4]->hide();
                imageLabel[5]->show();
            });
            QTimer::singleShot(12000, [&]() {
                imageLabel[5]->hide();
                this->hide();
                for(int ii=0;ii<14;ii++)for(int jjj=0;jjj<20;jjj++)delete label[ii][jjj];
                 main_windows windows2;
            });


        }
        else{
            meet_boss=false;
            imageLabel[7]->set_Position(650,130,200,200);
            imageLabel[8]->set_Position(650,70,200,200);
            QTimer::singleShot(1, [&]() {
                imageLabel[1]->show();
            });
            QTimer::singleShot(2000, [&]() {
                imageLabel[1]->hide();
                imageLabel[2]->show();
            });
            QTimer::singleShot(4000, [&]() {
                imageLabel[2]->hide();
                imageLabel[3]->show();
            });
            QTimer::singleShot(7000, [&]() {
                imageLabel[3]->hide();
                imageLabel[4]->show();
            });

            QTimer::singleShot(9000, [&]() {
                imageLabel[4]->hide();
                imageLabel[6]->show();
            });
            QTimer::singleShot(11000, [&]() {
                imageLabel[6]->hide();
                imageLabel[7]->show();
            });
            QTimer::singleShot(13000, [&]() {
                imageLabel[7]->hide();
                imageLabel[8]->show();
            });
            QTimer::singleShot(15000, [&]() {
                imageLabel[8]->hide();
                QMediaPlayer* player_ = new QMediaPlayer;
                QAudioOutput *bgm=new QAudioOutput;
                player_->setAudioOutput(bgm);
                player_->setSource(QUrl("qrc:/chenglong.MP3")); // 设置要播放的音频文件路径
                bgm->setVolume(50); // 设置音量（0-100之间的值）
                player_->play(); // 播放音频


                playerv = new QMediaPlayer;
                videoWidget = new QVideoWidget;
                playerv->setSource(QUrl("qrc:/chenglong.mp4"));
                videoWidget = new QVideoWidget;
                playerv->setVideoOutput(videoWidget);
                videoWidget->show();
                QVBoxLayout* layout = new QVBoxLayout;
                layout->addWidget(videoWidget);


                // 设置布局和窗口
                QWidget* centralWidget = new QWidget;
                centralWidget->setLayout(layout);
                this->setCentralWidget(centralWidget);
                playerv->play();
            });
            QTimer::singleShot(33000, [&]() {
                playerv->stop();
                videoWidget->hide();
                this->hide();
                for(int ii=0;ii<14;ii++)for(int jjj=0;jjj<20;jjj++)delete label[ii][jjj];
            });
        }
    }
    }
}
void main_windows::keyPressEvent(QKeyEvent *event)
{
    emit shit();
    show_pic();
    switch (event->key()) {
    case Qt::Key_Up:
        move(-1,0);
        //hero_x--;
        break;
    case Qt::Key_Down:
        //hero_x++;
        move(1,0);
        break;
    case Qt::Key_Right:
        //hero_y++;
        move(0,1);
        break;
    case Qt::Key_Left:
        //hero_y--;
        move(0,-1);
        break;
    case Qt::Key_P:
        if(handbook)
        {
            click_time++;
        if((click_time%2)==1){
            attribute->show();
        }
        else{
            qDebug()<<1;
            attribute->hide();
        }
        }
        break;
    default:
        break;
    }
    if(maps[flood][hero_x][hero_y]!=150)
    show_pic();

}
void main_windows::move(int a,int b){//x+a,y+b;
    switch(maps[flood][hero_x+a][hero_y+b]){
        case 0:
            //碰到普通的路
            hero_x+=a;
            hero_y+=b;
            break;
        case 100:
            //碰到普通的路
            hero_x+=a;
            hero_y+=b;
            break;
        case 1://不能走的黄色石块
            break;
        case 2://黄色的锁
            if(my_hero->get_yellow_key()>0){
                my_hero->yellow_key_number--;
                maps[flood][hero_x+a][hero_y+b]=0;
                hero_x+=a;
                hero_y+=b;
                break;
            }
            break;
        case 3://上升的楼梯
            flood++;
            switch(flood+1){
            case 1:break;
            case 2:hero_x=12;hero_y=9;break;
            case 3:hero_x=7;hero_y=7;break;
            case 4:hero_x=12;hero_y=7;break;
            case 5:hero_x=12;hero_y=12;break;
            }
            break;
        case 4://下降的楼梯
            flood--;
            switch(flood+1){
            case 1:hero_x=7;hero_y=12;break;
            case 2:hero_x=12;hero_y=16;break;
            case 3:hero_x=7;hero_y=17;break;
            case 4:hero_x=12;hero_y=17;break;
            case 5:break;
            }
            break;
        case 5://拿到了一个黄色钥匙
            //qDebug()<<a<<" "<<b;

            my_hero->yellow_key_number++;
            maps[flood][hero_x+a][hero_y+b]=0;
            hero_x+=a;
            hero_y+=b;
            //qDebug()<<hero_x<<" "<<hero_y;
            break;
        case 6://拿到生命药水
            my_hero->life+=200;
            maps[flood][hero_x+a][hero_y+b]=0;
            hero_x=hero_x+a;
            hero_y=hero_y+b;
            break;
        case 7:
            my_hero->power+=3;
            maps[flood][hero_x+a][hero_y+b]=0;
            hero_x=hero_x+a;
            hero_y=hero_y+b;
            break;
        case 8:
            my_hero->defense+=3;
            maps[flood][hero_x+a][hero_y+b]=0;
            maps[flood][hero_x][hero_y]=0;
            hero_x=hero_x+a;
            hero_y=hero_y+b;
            break;
        case 20:
            if(my_hero->fight(NPC[0]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            my_hero->money+=20;
            break;
        case 21:
            if(my_hero->fight(NPC[1])){

                maps[flood][hero_x+a][hero_y+b]=0;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
                            my_hero->money+=30;
            }
            break;
        case 22:
            if(my_hero->fight(NPC[2])){
            my_hero->money+=10;
                maps[flood][hero_x+a][hero_y+b]=0;
                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            break;
        case 23:
            if(my_hero->fight(NPC[3])){

                maps[flood][hero_x+a][hero_y+b]=0;
            my_hero->money+=12;
                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            break;

        case 24:
            if(my_hero->fight(NPC[4])){

                maps[flood][hero_x+a][hero_y+b]=0;
            my_hero->money+=20;
                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            break;
        case 25:
            if(my_hero->fight(NPC[5])){
                maps[flood][hero_x+a][hero_y+b]=0;
            my_hero->money+=40;
                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            break;

        case 26:
            if(my_hero->fight(NPC[6])){
                maps[flood][hero_x+a][hero_y+b]=0;

                hero_x=hero_x+a;
                hero_y=hero_y+b;}
            break;
        case 42:
            if(my_hero->fight(NPC[7]))
            {
                handbook=true;
                maps[flood][hero_x+a][hero_y+b]=0;
            my_hero->money+=40;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 51:
            if(my_hero->fight(NPC[8]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=30;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 52:
            if(my_hero->fight(NPC[9]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=40;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 53:
            if(my_hero->fight(NPC[10]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=50;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 54:
            if(my_hero->fight(NPC[11]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=30;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 55:
            if(my_hero->fight(NPC[12]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=60;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 56:
            if(my_hero->fight(NPC[13]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=60;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 57:
            if(my_hero->fight(NPC[14]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=40;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 61:
            if(my_hero->fight(NPC[15]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=70;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 62:
            if(my_hero->fight(NPC[16]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=80;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 63:
            if(my_hero->fight(NPC[17]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=100;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 64:
            meet_boss=true;
\
            break;
        case 65:
            if(my_hero->fight(NPC[19]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
                my_hero->money+=75;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 66:
            if(my_hero->fight(NPC[20]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=90;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 67:
            if(my_hero->fight(NPC[21]))
            {
                maps[flood][hero_x+a][hero_y+b]=0;
my_hero->money+=60;
                hero_x=hero_x+a;
                hero_y=hero_y+b;
            }
            break;
        case 58://商人
            shopper->show();
            break;
        case 59://sword
            my_hero->power=my_hero->power*1.1;
            maps[flood][hero_x+a][hero_y+b]=0;
            hero_x=hero_x+a;
            hero_y=hero_y+b;
            break;
        case 60://shield
            my_hero->defense=my_hero->defense*1.1;
            maps[flood][hero_x+a][hero_y+b]=0;
            hero_x=hero_x+a;
            hero_y=hero_y+b;
            break;

        case 150:
            get_the_book=true;
            int x=hero_x;
            int y=hero_y;
            hero_x+=a;
            hero_y+=b;

            //for(int i=0;i<14;i++)for(int j=0;j<20;j++)label[i][j]->setVisible(false);
            //首先因为我这里调用move函数之后我没有调用show_pic，所以我要移动一下勇士的图片

            //然后是动画播放器，把两个像素格放大，我们就不做定格动画了，我们放大之后直接开始一段视频。
            QParallelAnimationGroup *group=new QParallelAnimationGroup;

            if(label[hero_x][hero_y])delete label[hero_x][hero_y];
            label[x][y]=new my_label(":/left.png",this);
            //label[12][10]=new my_label("/Users/yuanmingyulinyizaitaofan/Desktop/左.png",this);
            label[x][y]->setGeometry(600,500,50,50);
            label[x][y]->set_pic();
            label[x][y]->show();
            label[hero_x][hero_y]=new my_label(":/right.png",this);
            //label[12][11]=new my_label("/Users/yuanmingyulinyizaitaofan/Desktop/右.png",this);
            label[hero_x][hero_y]->setGeometry(600,550,50,50);
            label[hero_x][hero_y]->set_pic();
            label[hero_x][hero_y]->show();
            QPropertyAnimation *animation=new QPropertyAnimation(label[x][y],"geometry");
            animation->setDuration(2000);
            animation->setStartValue(QRect(y*50, x*50, 50,50)); // 动画起始大小
            animation->setEndValue(QRect(0, 0, 501,700)); // 动画结束大小
            animation->setEasingCurve(QEasingCurve::InOutQuad); // 使用缓动曲线控制动画速度
            group->addAnimation(animation);
            QPropertyAnimation *animation2=new QPropertyAnimation(label[hero_x][hero_y],"geometry");
            animation2->setDuration(2000); // 动画持续时间
            animation2->setStartValue(QRect(hero_y*50, hero_x*50, 50,50)); // 动画起始大小
            animation2->setEndValue(QRect(500, 0, 501,700)); // 动画结束大小
            animation2->setEasingCurve(QEasingCurve::InOutQuad); // 使用缓动曲线控制动画速度
            group->addAnimation(animation2);

            group->start();

            //放大之后开始播放
            QTimer::singleShot(2500, [&]() {
                playerv = new QMediaPlayer;
                videoWidget = new QVideoWidget;
                playerv->setSource(QUrl("qrc:/stickfight.mp4"));
                videoWidget = new QVideoWidget;
                playerv->setVideoOutput(videoWidget);
                videoWidget->show();
                QVBoxLayout* layout = new QVBoxLayout;
                layout->addWidget(videoWidget);


                // 设置布局和窗口
                QWidget* centralWidget = new QWidget;
                centralWidget->setLayout(layout);
                this->setCentralWidget(centralWidget);
                playerv->play();
                QTimer::singleShot(21000, [&]() {
                    playerv->stop();
                    videoWidget->hide();
                    maps[flood][hero_x][hero_y]=0;
                    show_pic();
                    // 在这里可以执行其他操作，比如关闭窗口等
                });

            });
            break;

        }


        if(maps[flood][hero_x][hero_y]==100){
            //补充播放视频的代码
            get_the_book=true;
            if(hidefirst)
            {
                hidefirst=false;
                QTimer *timer;
                timer = new QTimer(this);
                int startTime=9000;
                timer->start(startTime);


                QMediaPlayer* player_ = new QMediaPlayer;
                QAudioOutput *bgm=new QAudioOutput;
                player_->setAudioOutput(bgm);
                player_->setSource(QUrl("qrc:/littlekawaii.MP3")); // 设置要播放的音频文件路径
                bgm->setVolume(50); // 设置音量（0-100之间的值）
                player_->play(); // 播放音频


                playerv = new QMediaPlayer;
                videoWidget = new QVideoWidget;
                playerv->setSource(QUrl("qrc:/littlekawaii.mp4"));
                videoWidget = new QVideoWidget;
                playerv->setVideoOutput(videoWidget);
                videoWidget->show();
                playerv->play();
                connect(timer,&QTimer::timeout,videoWidget,&QVideoWidget::hide);
            }
            //connect(playerv,SIGNAL(positionChanged(1000)),videoWidget,SLOT(close));

        }
}
//}
