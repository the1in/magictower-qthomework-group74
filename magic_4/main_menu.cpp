#include"main_menu.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QFont>

main_menu::main_menu()
{

    widget = new QWidget;  // 创建一个 QWidget 作为父级窗口

    QVBoxLayout *lay_out = new QVBoxLayout(widget);  // 创建一个垂直布局
    p[0]=new QPushButton("开始游戏",nullptr);
    p[1]=new QPushButton("退出游戏",nullptr);
    p[2]=new QPushButton("背景",nullptr);

    QFont fontTimes("Arial", 20);
    for(int i=0;i<3;i++){
        p[i]->setFixedSize(100,100);
        p[i]->move(100,100+100*i);
        p[i]->setFont(fontTimes);
        p[i]->setStyleSheet("QPushButton { color:black;border: none; }");
        //p[i]->show();
        lay_out->addWidget(p[i]);
    }
    widget->setLayout(lay_out);  // 将布局设置给父级窗口
    widget->setGeometry(0,0,947,478);
    widget->setStyleSheet("background-image:url(:/menu_background.png)");
    widget->show();  // 显示父级窗口
}
void main_menu::hide(){
    widget->hide();
}

void main_menu::show(){
    widget->show();
}
