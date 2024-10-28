#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Вычисляет площадь прямоугольника.
 * 
 * @param width Ширина прямоугольника.
 * @param height Высота прямоугольника.
 * @return Площадь прямоугольника.
 */
double rectangle_area(const double width, const double height);

/**
 * @brief Вычисляет площадь треугольника по формуле Герона.
 * 
 * @param a Длина первой стороны треугольника.
 * @param b Длина второй стороны треугольника.
 * @param c Длина третьей стороны треугольника.
 * @return Площадь треугольника.
 */
double triangle_area(const double a, const double b, const double c);

/**
 * @brief считывает вещественное число
 * @return возвращает вещественное число
 */
double input(void);

int main(void) 
{
    printf("Введите ширину и длину через пробел\n");
    const double width = input(), height = input();
    
    printf("Введите стороны треугольника через пробел\n");
    const double a = input(), b = input(), c = input();
    
    // Вычисление и вывод площади прямоугольника
    printf("Площадь прямоугольника: %.2lf\n", rectangle_area(width, height));
    
    // Вычисление и вывод площади треугольника
    printf("Площадь треугольника: %.2lf\n", triangle_area(a, b, c));
    
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

double triangle_area(const double a, const double b, const double c) 
{
    if (a + b - c > 0 && a - b + c > 0 && b + c - a > 0)
    {
            const double s = (a + b + c) / 2; // Полупериметр
        return sqrt(s * (s - a) * (s - b) * (s - c)); // Формула Герона
    }
    else 
    {
        printf("Такого треугольника не может существовать\n");
        errno = EIO;
        exit(EXIT_FAILURE);
    }
}

double rectangle_area(const double width, const double height) 
{
    return width * height;
}
