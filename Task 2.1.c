#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция печатает меню для пользователя, а именно,
 *        какие действия возможно выполнить.
 */
void printMenu(void);

/**
 * @brief Функция для ввода значения типа double с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа double.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
double inputDouble(const char* msg);

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
int inputInt(const char* msg);

/**
 * @brief Перечисление для выбора операций.
 */
enum choice { CHOICE_AVG = 1, CHOICE_GEOM };

/**
 * @brief Печатает выражение по выбранной операции.
 * @param choice Какая операция выбрана.
 */
void printExpressionByChoice(enum choice choice);

/**
 * @brief Точка входа в программу.
 * @return 0 в случае успеха.
 */
int main() {
    double firstOperand = inputDouble("a: ");
    double secondOperand = inputDouble("b: ");
    printf("a = %lf, b = %lf\n\n", firstOperand, secondOperand);

    printMenu();
    enum choice chosenCommand = inputInt(NULL);

    switch (chosenCommand) {
    case CHOICE_AVG:
    {
        double avg = (pow(firstOperand, 3) + pow(secondOperand, 3)) / 2.0;
        printExpressionByChoice(CHOICE_AVG);
        printf(" = %lf\n", avg);
        break;
    }
    case CHOICE_GEOM:
    {
        double geom = sqrt(fabs(firstOperand) * fabs(secondOperand));
        printExpressionByChoice(CHOICE_GEOM);
        printf(" = %lf\n", geom);
        break;
    }
    default:
        printf("Bye!\n");
        return 1;
    }

    return 0;
}

void printMenu(void) {
    printf("Choose what you want:\n");
    printf("1. ");
    printExpressionByChoice(CHOICE_AVG);
    printf("\n2. ");
    printExpressionByChoice(CHOICE_GEOM);
    printf("\nother. exit\n");
    printf("\n");
    printf("Your choice [1-3]: ");
}

double inputDouble(const char* msg) {
    double inputValue = 0;
    if (msg != NULL) {
        printf(msg);
    }
    int result = scanf("%lf", &inputValue);
    if (result != 1) {
        errno = EIO;
        perror("Your input should be valid double\n");
        exit(EXIT_FAILURE);
    }
    return inputValue;
}

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

void printExpressionByChoice(enum choice choice) {
    switch (choice) {
    case CHOICE_AVG:
    {
        printf("(a^3 + b^3) / 2");
        break;
    }
    case CHOICE_GEOM:
    {
        printf("sqrt(|a| * |b|)");
        break;
    }
    default:
        errno = EINVAL;
        perror("Not valid \"choice\" argument\n");
        exit(EXIT_FAILURE);
        break;
    }
}
