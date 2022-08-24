#include <bits/stdc++.h>

using namespace std;

double distanceOfCordinatePoints(double x1, double y1, double x2, double y2)
{
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

double angleOfTriangle(double a, double b, double c)
{
    // will return value of angle A in radian
    return acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));
}

double areaOfTriangle(double a, double b, double c)
{
    return 0.5 * a * b * sin(angleOfTriangle(c, b, a));
}

int main()
{

    // double x1, y1, x2, y2;
    // cin >> x1 >> y1 >> x2 >> y2;
    // cout << distanceOfCordinatePoints(x1, y1, x2, y2) << endl;

    // double a, b, c;
    // cin >> a >> b >> c;
    // cout << angleOfTriangle(a, b, c) << endl;
    // cout << angleOfTriangle(b, a, c) << endl;
    // cout << angleOfTriangle(c, a, b) << endl;

    // double a, b, c;
    // cin >> a >> b >> c;
    // cout << areaOfTriangle(a, b, c) << endl;
    // cout << areaOfTriangle(b, a, c) << endl;
    // cout << areaOfTriangle(c, b, a) << endl;

    // double a, b, c, x1, y1, x2, y2, x3, y3;
    // cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // a = distanceOfCordinatePoints(x1, y1, x2, y2);
    // b = distanceOfCordinatePoints(x2, y2, x3, y3);
    // c = distanceOfCordinatePoints(x1, y1, x3, y3);
    // cout << areaOfTriangle(a, b, c) << endl;

    return 0;
}