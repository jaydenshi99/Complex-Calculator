#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

#define EPSILON 1e-9

int compareDouble(double a, double b);
bool isZero(double a);
vector<std::string> splitExpression(string expression, char opt);

#endif