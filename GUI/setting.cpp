#include "setting.h"

Setting::Setting(AddNewSpline* addNewSplineIn, QWidget *parent) : QWidget(parent)
{
    addNewSplineDialog = addNewSplineIn;
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(p);
    addNewSpline = new QPushButton("add new spline", this);
    layout = new QGridLayout(this);
    layout -> addWidget(addNewSpline,0,0,1,1);
    connect(addNewSpline, &QPushButton::clicked, addNewSplineDialog, &QWidget::show);
    setLayout(layout);
}
