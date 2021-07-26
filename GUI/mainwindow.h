#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QPushButton>
#include <QColorDialog>
#include <GUI/setting.h>
#include <GUI/splinedisplay.h>
#include <GUI/splinesetting.h>
#include <GUI/addnewspline.h>

#include <Spline/splinehandler.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QColorDialog *getColor;
    Setting *setting;
    SplineDisplay *splineDisplay;
    SplineSetting *splineSetting;
    AddNewSpline *addSpline;
    QDockWidget *dockWidgetSetting;
    QDockWidget *dockWidgetSplineSetting;
    SplineHandler *handler;
public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
