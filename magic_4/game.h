#ifndef GAME_H
#define GAME_H
#include <QRandomGenerator>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
class Game_random : public QDialog {
public:
    Game_random(QWidget *parent = nullptr) : QDialog(parent) {
        QLabel *label = new QLabel("你好，我是'十七张牌你能秒我?的芦苯尾'，<br>"
                                   "现在我要来和你赌100以内的数字，<br>"
                                   "如果你赌对了（误差在2及以内），我会告诉你我的赌博绝招，<br>"
                                   "否则你就要扣血！");
        QLineEdit *lineEdit = new QLineEdit;
        QPushButton *button = new QPushButton("确定");
        QLabel *randomNumberLabel = new QLabel;

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(lineEdit);
        layout->addWidget(button);
        layout->addWidget(randomNumberLabel); // 添加用于显示随机数的 QLabel
        setLayout(layout);

        connect(button, &QPushButton::clicked, this, [this,lineEdit,randomNumberLabel]() {
            bool ok;
            int inputNumber = lineEdit->text().toInt(&ok);
            if (ok) {
                int randomNumber = QRandomGenerator::global()->bounded(100); // 生成0到99之间的随机数
                int difference = qAbs(inputNumber - randomNumber); // 计算差的绝对值
                QString message;
                if (difference <= 2) {
                    win_or_lose=true;
                    message = "你赢了！我的赌博绝招是......2023年度最好玩游戏Vitual Stdio";
                } else {
                    win_or_lose=false;
                    message = "你输了！请叫我，土块（赌怪）！！";
                }
                QMessageBox::information(this, "结果", message);
                randomNumberLabel->setText("随机数：" + QString::number(randomNumber)); // 显示随机数

                QTimer::singleShot(2000, this, &QDialog::accept); // 2秒后自动关闭对话框
            } else {
                QMessageBox::warning(this, "错误", "请输入一个有效的数字！");
            }
        });
    }
    bool win_or_lose=false;
};








#endif // GAME_H
