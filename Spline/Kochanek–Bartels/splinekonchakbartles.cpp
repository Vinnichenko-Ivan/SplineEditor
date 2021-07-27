#include "splinekonchakbartles.h"
void SplineKonchakBartles::addKnot()
{
    knots.push_back(new KnotKonchakBartles());
}

QVector<QPointF> SplineKonchakBartles::getPoints()
{
    QVector<QPointF> temp;
//    for(auto &n : knots)
//    {
//        temp.push_back(QPoint(n -> x, - (n -> y)));// - для отображения знаю, что это не совсем верно
//    }
    if(knots.size() < 2)
    {
        return temp;
    }


    for(size_t i = 0; i < knots.size() - 1; i++)
    {
//        auto previosKnot = knots[i], currentKnot = knots[i], nextKnot = knots[i], nextKnot2 = knots[i];// a = i - 1 // b = i // c = i + 1 // d = i + 2
//        if(i == 0)
//        {
//            previosKnot = knots[0];
//            currentKnot = knots[0];
//        }
//        else
//        {
//            previosKnot = knots[i - 1];
//            currentKnot = knots[i];
//        }
        
//        if(i == knots.size() - 2)
//        {
//            nextKnot = knots[i + 1];
//            nextKnot2 = knots[i + 1];
//        }
//        else
//        {
//            nextKnot = knots[i + 1];
//            nextKnot2 = knots[i + 2];
//        }
        const auto currentKnot = knots[i];
        const auto nextKnot = knots[i+1];
        const auto previosKnot = i == 0 ? knots[i] : knots[i-1];
        const auto next2Knot = i + 2 >= knots.size() ? knots[i+1] : knots[i+2];
        //for x
        double t = currentKnot->parametrs["tension"], b = currentKnot->parametrs["bias"], c = currentKnot->parametrs["continuity"];
        double dix = (1 - t)*(1 + b)*(1 + c)/2*(currentKnot -> x - previosKnot -> x) + (1 - t)*(1 - b)*(1 - c)/2*(nextKnot -> x - currentKnot -> x);
        double diy = (1 - t)*(1 + b)*(1 + c)/2*(currentKnot -> y - previosKnot -> y) + (1 - t)*(1 - b)*(1 - c)/2*(nextKnot -> y - currentKnot -> y);
        t = nextKnot->parametrs["tension"];
        b = nextKnot->parametrs["bias"];
        c = nextKnot->parametrs["continuity"];
        double dinextx = (1 - t)*(1 + b)*(1 - c)/2*(nextKnot -> x - currentKnot -> x) + (1 - t)*(1 - b)*(1 - c)/2*(next2Knot -> x - nextKnot -> x);
        double dinexty = (1 - t)*(1 + b)*(1 - c)/2*(nextKnot -> y - currentKnot -> y) + (1 - t)*(1 - b)*(1 - c)/2*(next2Knot -> y - nextKnot -> y);

//        double lenx = nextKnot -> x - currentKnot -> x;
//        double leny = nextKnot -> y - currentKnot -> y;
//        //temp.push_back(QPointF(currentKnot->x,currentKnot->y));
//        for(int l = 1; l <= k; l++)
//        {
//
//            double tx = lenx/k*l;
//            double ty = leny/k*l;
//            x = dix*h3(tx) + currentKnot->x*h1(tx) + nextKnot->x*h2(tx) + dinextx*h4(tx);
//            y = diy*h3(ty) + currentKnot->y*h1(ty) + nextKnot->y*h2(ty) + dinexty*h4(ty);
//            temp.push_back(QPointF(x, -y));
//        }
        static constexpr int k = 40;
        constexpr qreal step = 1.0/k;
        t = 0.0;
        for(int l = 1; l <= k; l++)
        {
            double x, y;
            x = dix*h3(t) + currentKnot->x*h1(t) + nextKnot->x*h2(t) + dinextx*h4(t);
            y = diy*h3(t) + currentKnot->y*h1(t) + nextKnot->y*h2(t) + dinexty*h4(t);
            temp.push_back(QPointF(x, -y));
            t += step;
       }


    }

    return temp;
}


double SplineKonchakBartles::h1(double t)
{
    return 2*t*t*t - 3*t*t +1;
}

double SplineKonchakBartles::h2(double t)
{
    return -2*t*t*t+ 3*t*t;
}

double SplineKonchakBartles::h3(double t)
{
    return t*t*t - 2*t*t + t;
}

double SplineKonchakBartles::h4(double t)
{
    return t*t*t-t*t;
}
