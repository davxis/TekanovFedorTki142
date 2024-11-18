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

int main() {
    double firstOperand = inputDouble();
    double secondOperand = inputDouble();
    printf("a = %lf, b = %lf\n\n", firstOperand, secondOperand);

    double avg = (pow(firstOperand, 3) + pow(secondOperand, 3)) / 2.0;
    printf("(a^3 + b^3) / 2 = %lf\n", avg);

    double geom = sqrt(fabs(firstOperand) * fabs(secondOperand));
    printf("sqrt(|a| * |b|) = %lf\n", geom);

    return 0;
}

/**
 * @brief Функция для ввода значения типа double.
 * @return Введенное значение типа double.
 * Проверяет корректность ввода. В случае ошибки устанавливает errno и завершает программу.
 */
double inputDouble() {
    double inputValue;
    int result = scanf("%lf", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid double\n");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}
