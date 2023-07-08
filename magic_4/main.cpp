#include <QApplication>
#include "main_windows.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // 创建主窗口

    main_windows window;
    return a.exec();
}
