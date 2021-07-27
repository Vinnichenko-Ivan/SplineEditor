#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    getColor = new QColorDialog(this);
    handler = new SplineHandler();
    addSpline = new AddNewSpline(getColor, handler, this);
    setting = new Setting(addSpline, this);
    splineSetting = new SplineSetting(handler, this);

    splineSetting -> setMinimumSize(200, 600);
    setting -> setMinimumSize(200, 600);
    splineDisplay = new SplineDisplay(handler, this);
    setCentralWidget(splineDisplay);
    dockWidgetSetting = new QDockWidget(tr("Setting"), this);
    dockWidgetSetting->setAllowedAreas(Qt::RightDockWidgetArea);
    dockWidgetSetting->setWidget(setting);
    addDockWidget(Qt::RightDockWidgetArea, dockWidgetSetting);
    dockWidgetSplineSetting = new QDockWidget(tr("Spline Setting"), this);
    dockWidgetSplineSetting->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockWidgetSplineSetting->setWidget(splineSetting);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidgetSplineSetting);
    
    //connect(setting -> addNewSpline, &QPushButton::clicked, addSpline, &QWidget::show);
    connect(addSpline, &AddNewSpline::updateSplines, splineSetting, &SplineSetting::updateEditSplines);
    connect(setting -> scale, &QPushButton::clicked, splineDisplay, &SplineDisplay::scale);
    //splineSetting -> hide();
}

MainWindow::~MainWindow()
{
}

