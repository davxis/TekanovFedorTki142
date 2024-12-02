#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция для ввода значения типа double с проверкой корректности ввода. 
 * @return Введенное значение типа double. 
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
double inputDouble(void);

/**
 * @brief вычисляет и возвращает значение функции f(x) = x - 1 / (3 + sin(3.6x))
 *        в точке x.
 *        Т.к. нет таких "x", при которых 3 + sin(3.6x) == 0,
 *        значение может быть получено для произвольного "x" и нет необходимости
 *        проверять возможность расчёта функции в точке.
 * @return значение функции в точке
 */
double f(const double x);

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успеха.
 */
int main(void) {
    double xStart = inputDouble();
    double xEnd = inputDouble();
    double deltaX = inputDouble();
    if (deltaX <= DBL_EPSILON) {
        errno = EIO;
        perror("deltaX should be greater than 0");
        return EXIT_FAILURE;
    }

    printf("xStart = %lf, xEnd = %lf, deltaX = %lf\n\n", xStart, xEnd, deltaX);

    for (double x = xStart; x <= xEnd + DBL_EPSILON; x += deltaX) {
        printf("f(%10.6lf) = %10.6lf\n", x, f(x));
    }

    return 0;

/**
 * @brief Функция для ввода значения типа double.
 * @return Введенное значение типа double.
 * Проверяет корректность ввода. В случае ошибки устанавливает errno и завершает программу.
 */
double inputDouble() {
    double inputValue = 0;
    int result = scanf("%lf", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid double");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}

/**
 * @brief Вычисляет значение функции f(x).
 * @param x Значение, в котором вычисляется функция.
 * @return Значение функции f(x) в точке x.
 */
double f(const double x) {
    return x - 1.0 / (3.0 + sin(3.6 * x));
}
