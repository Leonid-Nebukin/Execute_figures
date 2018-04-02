#pragma once
#define FIGURESDLL_EXPORT __declspec(dllexport) 
#define FIGURESDLL_IMPORT __declspec(dllimport) 
#include <cmath>
#include <stdexcept>
class FIGURESDLL_EXPORT  Point {
public:
    virtual double Square() = 0;
};
class FIGURESDLL_EXPORT Triangle :public Point {
private:
    double x1, y1;
    double x2, y2;
    double x3, y3;
public:
    Triangle();
    Triangle(const double& x11, const double& y11, const double& x22, const double& y22, const double& x33, const double& y33);
    const Triangle& operator= (const Triangle&);
    virtual double Square() override final;
};
class FIGURESDLL_EXPORT Rectangle :public Point {
private:
    double x1, y1;
    double x2, y2;
    double x3, y3;
public:
    Rectangle();
    Rectangle(const double& x11, const double& y11, const double& x22, const double& y22, const double& x33, const double& y33);
    double Square() override final;
};
class FIGURESDLL_EXPORT regular_polygons :public Point {
private:
    double x1, y1;
    double x2, y2;//координаты точек любой его стороны
    unsigned int n;//число углов
public:
    regular_polygons();
    regular_polygons(const double& x11, const double& y11, const double& x22, const double& y22, const unsigned int& n);
    double Square() override;
};