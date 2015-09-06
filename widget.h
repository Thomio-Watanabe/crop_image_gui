#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void setCropPercentage(const QString &cropPercentage);

private slots:
    QString cropPercentage() const;
    void saveImagesPaths();
    void on_openImages_clicked();
	void on_cropImages_clicked();
	
private:
    Ui::Widget *ui;
	QStringList imagesPaths;
};

#endif // WIDGET_H
