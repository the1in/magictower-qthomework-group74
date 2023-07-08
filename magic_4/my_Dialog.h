#ifndef MY_DIALOG_H
#define MY_DIALOG_H
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
static bool question_right_or_true=false;
class CustomDialog_monster1 : public QDialog
{

public:
    CustomDialog_monster1(QString content[8],QWidget* parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("题目");
        // 创建顶部图片标签
        QLabel* imageLabel = new QLabel(this);
        QPixmap image(":/gaga.png");  // 替换为实际的图片路径
        imageLabel->setPixmap(image);
        imageLabel->setAlignment(Qt::AlignCenter);

        // 创建题目标签
        QLabel* titleLabel = new QLabel("请问下面哪个选项是正确的？", this);
        titleLabel->setAlignment(Qt::AlignCenter);

        // 添加选项按钮
        QPushButton* buttonA = new QPushButton(content[0], this);
        QPushButton* buttonB = new QPushButton(content[1], this);
        QPushButton* buttonC = new QPushButton(content[2], this);
        QPushButton* buttonD = new QPushButton(content[3], this);

        // 垂直布局
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(imageLabel);
        layout->addWidget(titleLabel);
        layout->addWidget(buttonA);
        layout->addWidget(buttonB);
        layout->addWidget(buttonC);
        layout->addWidget(buttonD);

        // 连接按钮的点击事件到槽函数
        connect(buttonA, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[4]);
            //this->accept();
        });
        connect(buttonB, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[5]);
            //this->accept();
        });
        connect(buttonC, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[6]);
            //this->accept();
        });
        connect(buttonD, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[7]);
            //this->accept();
        });
    }
};
class CustomDialog_monster2 : public QDialog
{
    public:
    CustomDialog_monster2(QString content[8],QString right_answer,QWidget* parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("题目");
        // 创建顶部图片标签
        QLabel* imageLabel = new QLabel(this);
        QPixmap image(":/gaga.png");  // 替换为实际的图片路径
        imageLabel->setPixmap(image);
        imageLabel->setAlignment(Qt::AlignCenter);

        // 创建题目标签
        QLabel* titleLabel = new QLabel("请问下面哪个选项是正确的？", this);
        titleLabel->setAlignment(Qt::AlignCenter);

        // 添加选项按钮
        QPushButton* buttonA = new QPushButton(content[0], this);
        QPushButton* buttonB = new QPushButton(content[1], this);
        QPushButton* buttonC = new QPushButton(content[2], this);
        QPushButton* buttonD = new QPushButton(content[3], this);

        // 垂直布局
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(imageLabel);
        layout->addWidget(titleLabel);
        layout->addWidget(buttonA);
        layout->addWidget(buttonB);
        layout->addWidget(buttonC);
        layout->addWidget(buttonD);

        // 连接按钮的点击事件到槽函数
        connect(buttonA, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[4]);
            if(right_answer=="A"){
                question_right_or_true=true;
            }
            //this->accept();
        });

        connect(buttonB, &QPushButton::clicked, this, [=]() {
            QMessageBox::information(this, "结果", content[5]);
            if(right_answer=="B"){
                question_right_or_true=true;
            }
            //this->accept();
        });
        connect(buttonC, &QPushButton::clicked, this, [=]() {
            if(right_answer=="C"){
                question_right_or_true=true;
            }
            QMessageBox::information(this, "结果", content[6]);
            //this->accept();
        });
        connect(buttonD, &QPushButton::clicked, this, [=]() {
            if(right_answer=="D"){
                question_right_or_true=true;
            }
            QMessageBox::information(this, "结果", content[7]);
            //this->accept();
        });
    }
signals:
    void wrong_ans(){};
    void right_ans(){};
};

#endif // MY_DIALOG_H
