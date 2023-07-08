#include "my_label.h"

my_label::my_label(QString a,QWidget *parents){
    pic_path=a;
    this->setParent(parents);
}
my_label::my_label(QWidget *parents){
    this->setParent(parents);
}
my_label::my_label(){

}
void my_label::set_pic(){
    QPixmap pixmap(this->pic_path);
    this->setPixmap(pixmap);
}
void my_label::set_Position(int x,int y,int width,int height){
    this->setGeometry(x,y,width,height);
}


