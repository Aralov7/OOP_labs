#pragma once
#include <vector>
#include <cmath>

using namespace std;

double PolygonArea(const std::vector<std::pair<double,double>> &vertices);
std::pair<double,double> PolygonCenter(const std::vector<std::pair<double,double>> &vertices);

