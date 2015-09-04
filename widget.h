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

    void setCropPercentage(const QString &name);
    QString name() const;

private slots:
    void on_openImages_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
