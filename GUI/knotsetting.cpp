#include "knotsetting.h"

KnotSetting::KnotSetting(SplineHandler* handlerIn, QWidget *parent) : QWidget(parent)
{
    indexKnot = -1;
    indexSpline = -1;
    handler = handlerIn;
    addNewKnot = new QPushButton("add new knot", this);
    knotMenu = new QSpinBox(this);
    y = new QLabel("y", this);
    x = new QLabel("x", this);
    knot = new QLabel("knot", this);
    xIn = new QDoubleSpinBox(this);
    yIn = new QDoubleSpinBox(this);
    parametrIn = new QComboBox;
    parametrDataIn = new QDoubleSpinBox(this);
    connect(knotMenu, QOverload<int>::of(&QSpinBox::valueChanged),[=](int i){indexKnot = i; updateKnot();});
    connect(xIn, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double i){xData = i; updateKnotData();});
    connect(yIn, QOverload<double>::of(&QDoubleSpinBox::valueChanged),[=](double i){yData = i; updateKnotData();});
    connect(addNewKnot, &QPushButton::clicked, [=](){handler -> splines[indexSpline] -> knots.push_back(new Knot());updateKnot();});
    layout = new QGridLayout(this);
    layout -> addWidget(knot, 0, 0);
    layout -> addWidget(knotMenu, 0, 1);
    layout -> addWidget(x, 1, 0);
    layout -> addWidget(xIn, 1, 1);
    layout -> addWidget(y, 2, 0);
    layout -> addWidget(yIn, 2, 1);
    layout -> addWidget(parametrIn, 3, 0);
    layout -> addWidget(parametrDataIn, 3, 1);
    layout -> addWidget(addNewKnot, 4, 1);
    xIn -> setMaximum(10000);
    yIn -> setMaximum(10000);
    xIn -> setMinimum(-10000);
    yIn -> setMinimum(-10000);
    setLayout(layout);
    updateKnot();
}

void KnotSetting::updateKnot()
{
    if(indexSpline == -1)
    {
        addNewKnot -> setDisabled(true);
        knot -> setDisabled(true);
        knotMenu -> setDisabled(true);
        x -> setDisabled(true);
        y -> setDisabled(true);
        xIn -> setDisabled(true);
        yIn -> setDisabled(true);
        parametrIn -> setDisabled(true);
        parametrDataIn -> setDisabled(true);
    }
    else
    {
        addNewKnot -> setEnabled(true);
        knot -> setEnabled(true);
        knotMenu -> setEnabled(true);

        knotMenu -> setMinimum(0);
        knotMenu -> setMaximum(handler -> splines[indexSpline] -> knots.size() -1);
        if(indexKnot != -1)
        {
            x -> setEnabled(true);
            y -> setEnabled(true);
            xIn -> setEnabled(true);
            yIn -> setEnabled(true);
            parametrIn -> setEnabled(true);
            parametrDataIn -> setEnabled(true);
            xData = handler -> splines[indexSpline] -> knots[indexKnot] -> x;
            yData = handler -> splines[indexSpline] -> knots[indexKnot] -> y;
            xIn -> setValue(handler -> splines[indexSpline] -> knots[indexKnot] -> x);
            yIn -> setValue(handler -> splines[indexSpline] -> knots[indexKnot] -> y);

        }
        else
        {
            knotMenu -> setMinimum(0);
            knotMenu -> setValue(0);
            indexKnot = -1;
            knotMenu -> setMaximum(handler -> splines[indexSpline] -> knots.size() -1);
            x -> setDisabled(true);
            y -> setDisabled(true);
            xIn -> setDisabled(true);
            yIn -> setDisabled(true);
            parametrIn -> setDisabled(true);
            parametrDataIn -> setDisabled(true);
        }

    }
}

void KnotSetting::setIndexSpline(int index)
{
    indexSpline = index;
    indexKnot = -1;
    updateKnot();
}

void KnotSetting::updateKnotData()
{
    if(indexSpline != -1)
    {
        if(indexKnot != -1)
        {
            handler -> splines[indexSpline] -> knots[indexKnot] -> x = xData;
            handler -> splines[indexSpline] -> knots[indexKnot] -> y = yData;
        }
        else
        {

        }
    }
    else
    {

    }
}
