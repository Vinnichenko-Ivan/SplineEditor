#ifndef SPLINEVISUALING_H
#define SPLINEVISUALING_H

#include<QPoint>
#include<QVector>
class SplineVisualing
{
    virtual QVector<QPointF> getPoints() = 0;
};

#endif // SPLINEVISUALING_H
