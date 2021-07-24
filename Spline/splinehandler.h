#ifndef SPLINEHANDLER_H
#define SPLINEHANDLER_H

#include <vector>
#include <map>
#include <QVector>
#include "Spline/spline.h"

class SplineHandler
{
private:
    std::vector<Spline*> splines;
public:
    SplineHandler();
    QVector<QString> algorithms = {"default", "liner"};
    void addSpline(QColor color, QString name, QString algorithm);
};

#endif // SPLINEHANDLER_H
