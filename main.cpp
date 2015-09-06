#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication crop_image(argc, argv);

    Widget w;
    w.setCropPercentage("0.2");
    w.show();
	
    return crop_image.exec();
}

