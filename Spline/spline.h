#ifndef SPLINE_H
#define SPLINE_H

#include <QColor>
#include <QColor>
#include <QString>
#include "Spline/knot.h"

class Spline
{
public:
    Spline(QColor colorIn = QColor(0,0,255), QString nameIn = "def");
    std::vector<Knot> knots;
    QColor color;
    QString name;
};

#endif // SPLINE_H
