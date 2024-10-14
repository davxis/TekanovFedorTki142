#include <stdio.h>
#include <math.h>

/** @brief рассчитывает выражение A по формуле 
 * @param x значение константы x
 * @param y значение константы y
 * @param z значение константы z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/** @brief рассчитывает выражение B по формуле
 * @param x значение константы x
 * @param y значение константы y
 * @param z значение константы z
 * @return рассчитанное значение.
 */
double getB(const double x, const double y, const double z);

/** @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    const double x = 1.4;
    const double y = 3.1;
    const double z = 0.5;
    printf("%lf\n%lf", getA(x, y, z), getB(x, y, z));

    return 0;
}

double getA(const double x, const double y, const double z)
{
    return sqrt(z * x * sin(2 * x) + exp(-2 * x) * (x + y));
}

double getB(const double x, const double y, const double z)
{
    return exp(2*x) * log(z + x) - pow(y, 3*x) * log(y - x);
}
