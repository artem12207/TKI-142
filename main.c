#include <stdio.h>
#include <math.h>
double getA(double x, double y)
{
    return (2* cos(x-(3.14/6))) / (0.5 + (pow(sin(y), 2)));
}
double getB(double z)
{
    return 1+((pow(z , 2)) / (3 + pow(z , 2)) / 5);
}
int main()
{
    const double x = 1.426;
    const double y = 1.22;
    const double z = 3.5;
    double a = getA(x, y);
    double b = getB(z);
    printf("%s%lf\n", "a = ", a);
    printf("%s%lf", "b = ", b);
    return 0;
}