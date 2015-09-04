#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

// QTextStream is used to save the loades file names in a
#include <QTextStream>

Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget){
    ui->setupUi(this);
}

Widget::~Widget(){
    delete ui;
}

void Widget::setCropPercentage(const QString &name){
    ui->lineEdit->setText(name);
}

QString Widget::name() const{
    return ui->lineEdit->text();
}


// Open dialog to load files at home directory
void Widget::on_openImages_clicked(){
    QStringList files = QFileDialog::getOpenFileNames(this,
        tr("Select one or more images"),
        QDir::homePath(),
        tr("Image Files (*.png *.jpg)"));

    // Save loaded files names
    QFile data("output.txt");
    data.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&data);
    for(int i = 0; i < files.size(); ++i){
        out << " File name: " << files.at(i) << '\n';
    }
    data.close();
}
