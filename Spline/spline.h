#ifndef SPLINE_H
#define SPLINE_H

#include <QColor>
#include <QColor>
#include <QString>
#include "Spline/knot.h"
#include "Spline/splineVisualing.h"

class Spline : public SplineVisualing
{
public:
    Spline(QColor colorIn = QColor(0,0,255), QString nameIn = "def");
    std::vector<Knot*> knots;
    QColor color;
    QString name;
    Knot *templ;
    bool line;
    bool visible;
    bool knotVisible;
    double k;
    virtual void addKnot();
    QVector<QPointF> getPoints() override;
};

#endif // SPLINE_H
