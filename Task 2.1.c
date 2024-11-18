#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция для ввода значения типа double с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа double.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
double inputDouble(const char* msg);

/**
 * @brief Функция для ввода значения типа long с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа long.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
long inputLong(const char* msg);

/**
 * @brief Перечисление для выбора операций.
 */
enum choice { CHOICE_AVG = 1, CHOICE_GEOM };

/**
 * @brief Строка меню для выбора операции.
 */
const char* menu = "Choose what you want:\n"
"1. (a^3 + b^3) / 2\n"
"2. sqrt(|a| * |b|)\n"
"other. exit\n"
"\n"
"Your choice [1-3]: ";

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успеха.
 */
int main() {
    double firstOperand = inputDouble("a: ");
    double secondOperand = inputDouble("b: ");
    printf("a = %lf, b = %lf\n\n", firstOperand, secondOperand);
    
    enum choice chosenCommand = inputLong(menu);

    switch (chosenCommand) {
    case CHOICE_AVG:
    {
        double avg = (pow(firstOperand, 3) + pow(secondOperand, 3)) / 2.0;
        printf("(a^3 + b^3) / 2 = %lf\n", avg);
        break;
    }
    case CHOICE_GEOM:
    {
        double geom = sqrt(fabs(firstOperand) * fabs(secondOperand));
        printf("sqrt(|a| * |b|) = %lf\n", geom);
        break;
    }
    default:
        printf("Bye!\n");
        break;
    }
    
    return 0;
}

/**
 * @brief Функция для ввода значения типа double с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа double.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
double inputDouble(const char* msg) {
    double inputValue;
    printf(msg);
    int result = scanf("%lf", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid double\n");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}

/**
 * @brief Функция для ввода значения типа long с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа long.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
long inputLong(const char* msg) {
    long inputValue;
    printf(msg);
    int result = scanf("%ld", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid long int\n");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}
