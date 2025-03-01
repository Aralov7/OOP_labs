#include "../include/func.h"

using namespace std;

double PolygonArea(const vector<pair<double, double>> &vertices)
{
    double area = 0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        double x1 = vertices[i].first;
        double y1 = vertices[i].second;
        double x2 = vertices[(i + 1) % n].first;
        double y2 = vertices[(i + 1) % n].second;
        area += (x1 * y2 - x2 * y1);
    }
    return abs(area) / 2.0;
}

pair<double, double> PolygonCenter(const vector<pair<double, double>> &vertices)
{
    double cx = 0;
    double cy = 0;
    double area = PolygonArea(vertices);
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i)
    {
        double xi = vertices[i].first;
        double yi = vertices[i].second;
        double xi1 = vertices[(i + 1) % n].first;
        double yi1 = vertices[(i + 1) % n].second;
        double cross = xi * yi1 - xi1 * yi;
        cx += (xi + xi1) * cross;
        cy += (yi + yi1) * cross;
    }
    double factor = 1 / (6 * area);
    cx *= factor;
    cy *= factor;
    return {cx, cy};
}
