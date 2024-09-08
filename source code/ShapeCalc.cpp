#include "ShapeCalc.h"
#include<cmath>

const double _pi = acos(-1.0);
bool Triangle::IsTriangle()
{
    if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) { return true; }
    else { return false; }
}
double Triangle::Preimeter() { return side1 + side2 + side3; }
double Triangle::Area()
{
    double HalfPreimeter = Preimeter() / 2.0;
    return sqrt(HalfPreimeter * (HalfPreimeter - side1) * (HalfPreimeter - side2) * (HalfPreimeter - side3));
}
double Circle::Preimeter() { return 2.0 * _pi * radius; }
double Circle::Area() { return radius * radius * _pi; }
bool CircluarRing::compareRadius() { return radius1 > radius2; }
double CircluarRing::Preimeter()
{
    Circle c1(radius1), c2(radius2);
    return c1.Preimeter() + c2.Preimeter();
}
double CircluarRing::Area()
{
    Circle c1(radius1), c2(radius2);
    if (compareRadius()) { return c1.Area() - c2.Area(); }
    else { return c2.Area() - c1.Area(); }
}
double Trapezoid::Preimeter() { return side1 + side2 + side3 + side4; }
double Trapezoid::Area() { return ((side1 + side2) * (heigth_parallzed_sides)) / 2.0; }
double Parallelogram::Preimeter() { return (side1 + side2) * 2.0; }
double Parallelogram::Area() { return side1 * heigthOnSide1; }
double Rectangle::Preimeter() { return (length + width) * 2.0; }
double Rectangle::Area() { return length * width; }
double Square::Preimeter() { return sidelength * 4.0; }
double Square::Area() { return sidelength * sidelength; }