#ifndef SPLINEKONCHAKBARTLES_H
#define SPLINEKONCHAKBARTLES_H

#include <Spline/spline.h>
#include <Spline/Kochanek–Bartels/knotkonchakbartles.h>

class SplineKonchakBartles : public Spline
{
public:
    SplineKonchakBartles(QColor colorIn, QString nameIn)
    {
        color = colorIn;
        name = nameIn;
        line = false;
        visible = true;
        knotVisible = true;
        templ = new Knot();
        k = 10;
    }
    void addKnot() override;
    QVector<QPointF> getPoints() override;
    double h1(double t);
    double h2(double t);
    double h3(double t);
    double h4(double t);
};

#endif // SPLINEKONCHAKBARTLES_H
