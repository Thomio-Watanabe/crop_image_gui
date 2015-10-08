#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication crop_image(argc, argv);

    Widget window;

    // Set default crop percentage
    window.setCropPercentage("0.2");

    // Move main window to sceen center
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = screenGeometry.width() / 2;
    int y = screenGeometry.height() / 2;
    window.move(x,y);

    window.show();
	
    return crop_image.exec();
}

