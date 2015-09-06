#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

// QTextStream is used to save the loades file names in a
#include <QTextStream>
// // Qt graphics headers
// #include <QGraphicsScene>
// #include <QGraphicsView>

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

// Open dialog to load files at home directory
void Widget::on_openImages_clicked(){
    imagesPaths = QFileDialog::getOpenFileNames(this,
        tr("Select one or more images"),
        QDir::homePath(),
        tr("Image Files (*.png *.jpg)"));

    //     // Open and show images
    //     QImage* imageObject = new QImage();
    //     imageObject->load(imagesPaths.at(0));
    //
    //     QPixmap image = QPixmap::fromImage(*imageObject);
    //
    //     QGraphicsScene* scene = new QGraphicsScene(this);
    // scene->addPixmap(image);
    //     scene->setSceneRect(image.rect());
    //     QGraphicsView view(scene,this);
    //     view.show();
    //     // ui->graphicsView->setScene(scene);
    
    // Save loaded images paths
    QFile data("output.txt");
    data.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&data);
    for(int i = 0; i < imagesPaths.size(); ++i){
        out << " File name: " << imagesPaths.at(i) << '\n';
    }
    data.close();
}

void Widget::on_cropImages_clicked(){
	bool ok;
	QString cpString = cropPercentage();
	float cropPercentage = cpString.toFloat(&ok);
	if(!ok){
		// Input cropPercentage was not a valid number
		// Exit with an error code
	}else{
		if(cropPercentage >= 0.0 && cropPercentage < 0.5){
			// Input cropPercentage is valid
            // Load image
            // QString imagePath = imagesPaths.at(0);
            // cv::Mat image = cv::imread(imagePath.toUtf8().constData(), CV_LOAD_IMAGE_COLOR );
            // if( !image.data ){
            //     // Error: Could not open or find the image
            // } 
		}else{
			// Input cropPercentage is out of limits
			// Exit with an error code
		}
	}
    

}




