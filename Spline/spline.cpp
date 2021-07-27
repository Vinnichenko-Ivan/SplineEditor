#include "spline.h"

Spline::Spline(QColor colorIn, QString nameIn)
{
    color = colorIn;
    name = nameIn;
    line = false;
    visible = true;
    knotVisible = true;
    templ = new Knot();
    k = 10;
}

void Spline::addKnot()
{
    knots.push_back(new Knot());
}


QVector<QPointF> Spline::getPoints()
{
    QVector<QPointF> temp;
//    for(auto &n : knots)
//    {
//        temp.push_back(QPoint(n -> x, - (n -> y)));// - для отображения знаю, что это не совсем верно
//    }
    return temp;
}
