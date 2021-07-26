#include "splinesetting.h"

SplineSetting::SplineSetting(SplineHandler* handlerIn, QWidget *parent) : QWidget(parent)
{
    handler = handlerIn;
    checkTestLine = new QCheckBox("test line ", this);
    layout = new QGridLayout(this);
    splineEdit = new QComboBox(this);
    deleteSpline = new QPushButton("delete spline", this);
    knotSetting = new KnotSetting(handler, this);
    layout -> addWidget(splineEdit,0,0,1,9);
    layout -> addWidget(deleteSpline,1,0,1,9);
    layout -> addWidget(checkTestLine,2,0,1,9);
    layout -> addWidget(knotSetting,3,0,1,9);
    connect(splineEdit, QOverload<int>::of(&QComboBox::activated), [=](){editSpline = splineEdit -> currentIndex(); knotSetting -> setIndexSpline(editSpline); updateSplineSetting();});
    connect(checkTestLine, QOverload<bool>::of(&QCheckBox::clicked), [=](bool test){handler -> setTestLine(editSpline, test); updateSplineSetting(); });
    connect(deleteSpline, &QPushButton::clicked, [=](){ handler -> deleteSpline(editSpline); editSpline = -1; knotSetting -> setIndexSpline(editSpline); updateSplineSetting(); updateEditSplines();});
    editSpline = -1;
    setLayout(layout);
    updateSplineSetting();
    checkTestLine -> setDisabled(true);
}

void SplineSetting::updateEditSplines()
{
    splineEdit -> clear();
    for(auto &n : handler -> getNames())
    {
        splineEdit -> addItem(n);
    }
}

void SplineSetting::updateSplineSetting()
{
    //editSpline = splineEdit -> currentIndex();
    if(editSpline != -1)
    {
        deleteSpline -> setEnabled(true);
        checkTestLine -> setEnabled(true);
        checkTestLine -> setChecked(handler -> getCheckLineFlag(editSpline));
    }
    else
    {
        deleteSpline -> setDisabled(true);
        checkTestLine -> setDisabled(true);

    }
    //qDebug() << editSpline;
}
