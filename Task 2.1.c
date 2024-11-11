#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Функция для ввода числа с плавающей точкой (double).
 * 
 * @param msg Сообщение, выводимое пользователю перед вводом.
 * @return Введенное число типа double.
 */

double inputDouble(const char* msg) {
    char tmp[100];
    double a;
    int failed;
    char* e;
    do {
        printf(msg);
        fgets(tmp, 100, stdin);
        errno = 0;
        a = strtod(tmp, &e);
        failed = *e != '\n' || errno != 0;
        if (failed) {
            printf("Your input should be valid double\n");
        }
    } while (failed);
    return a;
}

/**
 * Функция для ввода целого числа (long).
 * 
 * @param msg Сообщение, выводимое пользователю перед вводом.
 * @return Введенное число типа long.
 */

long inputLong(const char* msg) {
    char tmp[100];
    long a;
    int failed;
    char* e;
    do {
        printf(msg);
        fgets(tmp, 100, stdin);
        errno = 0;
        a = strtol(tmp, &e, 10);
        failed = *e != '\n' || errno != 0;
        if (failed) {
            printf("Your input should be valid long int\n");
        }
    } while (failed);
    return a;
}

/**
 * Перечисление для выбора операции.
 */

enum choice { CHOICE_AVG = 1, CHOICE_GEOM };

int main() {
    double a = inputDouble("a: ");
    double b = inputDouble("b: ");
    printf("a = %lf, b = %lf\n\n", a, b);
    enum choice c = inputLong("Choose what you want:\n"
        "1. (a^3 + b^3) / 2\n"
        "2. sqrt(|a| * |b|)\n"
        "other. exit\n"
        "\n"
        "Your choice [1-3]: ");

    switch (c) {
    case CHOICE_AVG:
    {
        double avg = (pow(a, 3) + pow(b, 3)) / 2.0;
        printf("(a^3 + b^3) / 2 = %lf\n", avg);
        break;
    }
    case CHOICE_GEOM:
    {
        double geom = sqrt(fabs(a) * fabs(b));
        printf("sqrt(|a| * |b|) = %lf\n", geom);
        break;
    }
    }
    return 0;
}
