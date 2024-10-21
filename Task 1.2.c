#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @param arifmetic_of_cubes - среднее арифметическое кубов этих чисел
 * @param abs_of_geometry - среднее геометрическое модулей этих чисел
 */
enum repuest{arifmetic_of_cubes, abs_of_geometry};

/**
 * @brief среднее арифметическое кубов этих чисел
 * @return возвращает значение
 */
double arifmetic_cubes(const double a, const double b);

/**
 * @brief среднее геометрическое модулей этих чисел
 * @return возвращает значение
 */
double abs_geometry(const double a, const double b);

/**
 * @brief выбор варианта 
 * @return возвращает номер выбранного варианта
 */
void menu(void);

/**
 * @brief считывает число
 * @return число
 */
double input(void);

/** 
 * @brief точка входа в программу
 * @return 0, в случае успеха 
 */
int main(void)
{
    const double a = input(), b = input();
    menu();
    int choice = input();
    switch(choice)
    {
        case arifmetic_of_cubes:
            printf("%lf", arifmetic_cubes(a, b));
            break;
        case abs_of_geometry:
            printf("%lf", abs_geometry(a, b));
            break;
        default:
            printf("Неправильный ввод");
    }
    return 0;
}

void menu(void)
{
    printf("arifmetic_of_cubes - %d\n", arifmetic_of_cubes);
    printf("abs_of_geometry - %d\n", abs_of_geometry);
}

double input(void)
{
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1) { 
        errno = EIO;
        printf("Не удалось считать число");
        exit(EXIT_FAILURE);
    } 
    return value;
}

double arifmetic_cubes(const double a, const double b)
{
    return ((pow(a, 3) + pow(b, 3)) / 2);
}

double abs_geometry(const double a, const double b)
{
    return pow((fabs(a) * fabs(b)), (1/2));
}
