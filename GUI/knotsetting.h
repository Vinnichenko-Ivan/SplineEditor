#ifndef KNOTSETTING_H
#define KNOTSETTING_H

#include <QWidget>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <Spline/splinehandler.h>

class KnotSetting : public QWidget
{
    Q_OBJECT
private:
    QLabel* knot;
    QLabel* y;
    QLabel* x;
    SplineHandler *handler;
    QGridLayout *layout;
    QPushButton *addNewKnot;
    QSpinBox *knotMenu;
    QDoubleSpinBox *xIn;
    QDoubleSpinBox *yIn;
    QComboBox *parametrIn;
    QDoubleSpinBox *parametrDataIn;
    int indexKnot;
    int indexSpline;
    double xData;
    double yData;
public:
    explicit KnotSetting(SplineHandler* handlerIn, QWidget *parent = nullptr);
    void updateKnot();
    void setIndexSpline(int index);
    void updateKnotData();
signals:

};

#endif // KNOTSETTING_H
