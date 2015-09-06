#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

// QTextStream is used to save the loades file names in a
#include <QTextStream>

#include <CroppedImage.hpp>
#include <QMessageBox>


Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget){
    ui->setupUi(this);
}

Widget::~Widget(){
    delete ui;
}

void Widget::setCropPercentage(const QString &cropPercentage){
    ui->lineEdit->setText(cropPercentage);
}

QString Widget::cropPercentage() const{
    return ui->lineEdit->text();
}


void Widget::saveImagesPaths(){
    // Save loaded images paths
    QFile data("output.txt");
    data.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&data);
    for(int i = 0; i < imagesPaths.size(); ++i){
        out << " File name: " << imagesPaths.at(i) << '\n';
    }
    data.close();
}


void Widget::on_openImages_clicked(){
    // Open dialog to load files at home directory
    imagesPaths = QFileDialog::getOpenFileNames(this,
        tr("Select one or more images"),
        QDir::homePath(),
        tr("Image Files (*.png *.jpg)"));
}


void Widget::on_cropImages_clicked(){
    QMessageBox messageBox;
	bool ok;
	QString cpString = cropPercentage();
	float cropPercentage = cpString.toFloat(&ok);
	if(!ok){
		// Input cropPercentage was not a valid number
        messageBox.critical(0,"Error","Input cropPercentage was not a valid number !");
        QCoreApplication::exit();
	}else{
		if(cropPercentage < 0.0 || cropPercentage >= 0.5){
			// Input cropPercentage is out of limits
            messageBox.critical(0,"Error","Input cropPercentage is out of limits \n (0.0 < cp < 5.0) !");
            QCoreApplication::exit();
		}else{
			// Input cropPercentage is valid
            // Load image
            CroppedImage cpImage(cropPercentage);
            for(int i = 0; i < imagesPaths.size(); ++i){
                QString imagePathString = imagesPaths.at(i);
                cpImage.loadImage( imagePathString.toStdString() );
                cpImage.cropImage();
                cpImage.saveImage( imagePathString.toStdString() );
            }
        }
	}
}




