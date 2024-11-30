#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
int inputInt(const char* msg);

double inputDouble(const char* msg);

/**
 * @brief Вычисляет сумму членов последовательности.
 * @param n Число элементов последовательности.
 */
double getSumOfSequence(int n);

/**
 * @brief Вычисляет сумму членов последовательности,
 *        которые выше по модулю чем epsilon.
 * @param n Число элементов последовательности.
 * @param eps Значение epsilon.
 */
double getSumOfSequenceMoreThanEps(int n, double eps);

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успеха.
 */
int main(void) {
    int n = inputInt("n: ");
    double eps = inputDouble("e: ");
    if (eps <= 0) {
        errno = EIO;
        perror("epsilon should be greater than 0");
        return EXIT_FAILURE;
    }
    double sumOfSeq = getSumOfSequence(n);
    double sumOfSeqMoreThanEps = getSumOfSequenceMoreThanEps(n, eps);
    printf("sum from k=0 to k=n is equal to %8.5lf\n", sumOfSeq);
    printf("sum from k=0 to k=n where term greater or equal than %8.5lf is equal to %8.5lf\n",
        eps, sumOfSeqMoreThanEps);
    return 0;
}

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
int inputInt(const char* msg) {
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

/**
 * @brief Вычисляет сумму членов последовательности.
 * @param n Число элементов последовательности.
 */
double getSumOfSequence(int n) {
    double res = 0.0;
    double term = -1.0;
    for (int k = 1; k <= n; k++) {
        res += term;
        term *= -1.0 / k;
    }
    return res;
}

/**
 * @brief Вычисляет сумму членов последовательности,
 *        которые выше по модулю чем epsilon.
 * @param n Число элементов последовательности.
 * @param eps Значение epsilon.
 */
double getSumOfSequenceMoreThanEps(int n, double eps) {
    double resLessThanEps = 0.0;
    double term = -1.0;
    for (int k = 1; k <= n; k++) {
        if (abs(term) >= eps) {
            resLessThanEps += term;
        }
        term *= -1.0 / k;
    }
    return resLessThanEps;
}
