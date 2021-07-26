#include "addnewspline.h"

AddNewSpline::AddNewSpline(QColorDialog* getColorIn, SplineHandler* handlerIn, QWidget *parent) : QWidget(parent, Qt::Window)
{
    setMinimumSize(100,100);
    getColor = getColorIn;
    handler = handlerIn;
    colorLable = new QLabel(this);
    colorLable -> setAutoFillBackground(true);
    nameIn = new QLineEdit("Spline",this);
    algorithms = new QComboBox(this);
    colorIn = new QPushButton("Set color",this);
    layout = new QGridLayout(this);
    addNew = new QPushButton("add", this);

    for(auto &n: handlerIn -> algorithms)
    {
        algorithms -> addItem(n);
    }

    layout -> addWidget(nameIn, 0, 0, 1, 6);
    layout -> addWidget(algorithms, 1, 0, 1, 6);
    layout -> addWidget(colorIn, 2, 0, 1, 5);
    layout -> addWidget(colorLable, 2, 5, 1, 1);
    layout -> addWidget(addNew, 3, 0, 1, 6);
    palette = new QPalette();
    palette->setColor(QPalette::Window, changedColor);
    colorLable -> setPalette(*palette);
    connect(colorIn, &QPushButton::clicked, [=](){getColor -> open();});
    connect(getColor, &QColorDialog::colorSelected, [=](){changedColor =  getColor -> currentColor(); ; palette->setColor(QPalette::Window, changedColor); colorLable -> setPalette(*palette);});
    connect(algorithms, QOverload<int>::of(&QComboBox::activated), [=](){changedAlgorithm = algorithms -> currentText();});
    connect(addNew, &QPushButton::clicked, this, &AddNewSpline::addSpline);

    setLayout(layout);
}



void AddNewSpline::addSpline()
{
    handler -> addSpline(changedColor, nameIn -> text(), changedAlgorithm);
    close();
    updateSplines();
}


