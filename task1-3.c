#include  <stdio.h>
#include <math.h> 
#include <stdlib.h> 
#include  <errno.h>

/**
 * @brief считывает вещественное число
 * @return возвращает вещественное число
 */
double input(void);

/**
 * @brief рассчитывает работу эл.тока по формуле
 * @param I - сила тока
 * @param U - напряжение
 * @param time - время переведенное в секунды 
 * return рассчитанное значение работы силы тока
 */
double result(const double R, const double I, const double Q);

/**
* @brief точка входу в прогамму
* return 0 в случае успехa
*/
int main(void)
{
    const double R = input();
    const double I = input();
    const double Q = input();
    printf("Проволка нагревалась %lf секунд\n", result(R, I, Q));

    return 0;
}

double input(void) 
{
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1)
   {
       errno = EIO;
       perror("Ошибка ввода");
       exit(EXIT_FAILURE);
   }
   return value;
}

double result(const double R, const double I, const double Q)
{
    return Q / pow(I, 2) * R;
}
