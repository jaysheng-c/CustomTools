#include <QApplication>
#include <QPushButton>
#include "guide/guide_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuideWidget widget;
    widget.show();
    return QApplication::exec();
}