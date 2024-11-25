#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * Эта функция запрашивает у пользователя ввод целого числа, выводя заданное сообщение.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 */
long inputInt(const char* msg);

/**
 * @brief Функция для ввода значения типа double с сообщением.
 * Эта функция запрашивает у пользователя ввод числа с плавающей точкой, выводя заданное сообщение.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа double.
 */
double inputDouble(const char* msg);

int main() {
    int n = inputInt("n: ");
    double eps = inputDouble("e: ");
    double res = 0.0;
    double term = -1.0;
    double resLessThanEps = 0.0;
    
    // Цикл для вычисления суммы ряда
    for (int k = 1; k <= n; k++) {
        res += term; // Добавляем текущий член к результату
        if (abs(term) >= eps) {
            resLessThanEps += term; // Если член больше или равен eps, добавляем его к другой сумме
        }
        term *= -1.0 / k; // Вычисляем следующий член ряда
    }
    
    printf("sum from k=0 to k=n is equal to %8.5lf\n", res);
    printf("sum from k=0 to k=n where term greater or equal than %8.5lf is equal to %8.5lf\n", eps, resLessThanEps);
    
    return 0;
}

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * Эта функция запрашивает у пользователя ввод целого числа, выводя заданное сообщение.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 */
long inputInt(const char* msg) {
    int inputValue = 0;
    if (msg != NULL) {
        printf(msg);
    }
    
    int result = scanf("%d", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid int\n");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}

/**
 * @brief Функция для ввода значения типа double с сообщением.
 * Эта функция запрашивает у пользователя ввод числа с плавающей точкой, выводя заданное сообщение.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа double.
 */
double inputDouble(const char* msg) {
    double inputValue = 0;
    if (msg != NULL) {
        printf(msg);
    }
    
    int result = scanf("%lf", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid double");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}
