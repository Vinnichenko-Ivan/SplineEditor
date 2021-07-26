#include "spline.h"

Spline::Spline(QColor colorIn, QString nameIn)
{
    color = colorIn;
    name = nameIn;
    line = false;
    visible = true;
    knotVisible = true;
    Knot* k = new Knot;
    k->x = 10;
    k->y = 10;
    knots.push_back(k);

    Knot* l = new Knot;
    l->x = 100;
    l->y = 100;
    knots.push_back(l);
}
