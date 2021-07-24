#include "splinehandler.h"

SplineHandler::SplineHandler()
{

}

void SplineHandler::addSpline(QColor color, QString name, QString algorithm)
{
    if(algorithm == "default")
    {
        Spline *buff = new Spline(color, name);
        splines.push_back(buff);
    }
    else if(algorithm == "liner")
    {
        Spline *buff = new Spline(color, name);
        splines.push_back(buff);
    }
}
