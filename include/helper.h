#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

#define EPSILON 1e-9

int compareDouble(double a, double b);
bool isZero(double a);
std::vector<std::string> splitExpression(std::string expression, char opt);

#endif