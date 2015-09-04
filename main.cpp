#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication crop_image(argc, argv);

    Widget w;
    w.setCropPercentage("0.2");
    w.show();
    // QPushButton *pushButton = new QPushButton("&Open");
    // connect(pushButton,SIGNAL(clicked()),&crop_image,SLOT(w.on_pushButton_clicked()) );
    // w.openImages();

    return crop_image.exec();
}

