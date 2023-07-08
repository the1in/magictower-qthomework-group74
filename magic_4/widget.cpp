#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDialog *dialog= new QDialog(this);
    dialog->setModal(true);
    dialog->setWindowTitle("主菜单");
    dialog->setFixedSize(500,500);
    //dialog->setWindowFlags(Qt::FramelessWindowHint);
    dialog->move(100,100);
    dialog->show();
}

Widget::~Widget()
{
    delete ui;
}

