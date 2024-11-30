#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Создаёт и заполняет массив случайными значениями от min до max или же пользовательским вводом.
 * Способ ввода (генерация или клавиатура) задаётся пользователем.
 * @param n Количество элементов в массиве.
 * @param min Минимальное значение для генерации случайных чисел.
 * @param max Максимальное значение для генерации случайных чисел.
 * @return Указатель на созданный и заполненный массив целых чисел.
 */
int* inputArray(const size_t n, const int min, const int max);

/**
 * @brief Вычисляет три пункта задания и возвращает структуру с результатами вычислений.
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @param a Параметр для второго вычисления.
 * @return Структура Result, содержащая результаты трех вычислений.
 */
const struct Result calcEverything(const int* ar, const size_t n, const int a);

/**
 * @brief Отображает результаты вычислений в удобочитаемом виде на консоли.
 * @param result Структура Result, содержащая результаты вычислений.
 */
void displayCalculationResults(const struct Result result);

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * Выводит сообщение перед вводом значения и ожидает ввода от пользователя.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 */
int inputInt(const char* msg);

/**
 * @brief Выделяет память под массив из "n" элементов.
 * Обрабатывает ситуацию, когда это не удалось, выводя сообщение об ошибке и завершив выполнение программы.
 * @param n Количество элементов в массиве.
 * @return Указатель на выделенный массив целых чисел или NULL в случае ошибки.
 */
int* allocIntArray(const size_t n);

/**
 * @brief Генерирует случайные значения в массиве ar.
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @param min Минимальное значение для генерации случайных чисел.
 * @param max Максимальное значение для генерации случайных чисел.
 */
void genRandomValues(int* ar, const size_t n, const int min, const int max);

/**
 * @brief Заполняет массив значениями, введёнными пользователем.
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 */
void setArrayValuesByInput(int* ar, const size_t n);

/**
 * @brief Отображает элементы массива на консоль.
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 */
void displayArray(const int* ar, const size_t n);

/**
 * @brief Вычисляет сумму отрицательных элементов массива.
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return Сумма отрицательных элементов массива.
 */
int calcSumOfNegs(const int* ar, const size_t n);

/**
 * @brief Вычисляет сумму положительных элементов массива, которые не превышают значение "a"
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @param a Параметр для ограничения суммы.
 * @return Сумма положительных элементов, не превышающих "a".
 */
int calcSumOfPosAndLesOrEqA(const int* ar, const size_t n, const int a);

/**
 * @brief Возвращает индекс последней пары соседних элементов, имеющих разные знаки.
 * Если таких пар нет, возвращается значение 0 (или -1 в зависимости от реализации).
 * @param ar Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return Индекс последней пары с разными знаками или 0, если таких пар нет.
 */
int determineLastPairOfDiffSigns(const int* ar, const size_t n);
/**
 * @brief точка входа в программу
 * @return 0 в случае успехa
 */
int main() {
    srand((unsigned int)time(NULL));
    int min = -100;
    int max = 200;

    int n = inputInt("n: ");
    int A = inputInt("A: ");
    int* ar = inputArray(n, min, max);
    displayArray(ar, n);

    int sumOfNegs, posAndLesOrEqA, lastPair;
    calcEverything(ar, n, A, &sumOfNegs, &posAndLesOrEqA, &lastPair);

    displayCalculationResults(sumOfNegs, posAndLesOrEqA, lastPair);

    free(ar);
    return 0;
}

int* inputArray(int n, int min, int max) {
    int* ar = allocIntArray(n);
    int choice = inputInt("choice (1 - random, other - keyboard): ");
    if (choice == 1) {
        genRandomValues(ar, n, min, max);
    } else {
        setArrayValuesByInput(ar, n);
    }
    return ar;
}

void calcEverything(int* ar, int n, int A, int* sumOfNegs, int* posAndLesOrEqA, int* lastPair) {
    *sumOfNegs = calcSumOfNegs(ar, n);
    *posAndLesOrEqA = calcSumOfPosAndLesOrEqA(ar, n, A);
    *lastPair = determineLastPairOfDiffSigns(ar, n);
}


void displayCalculationResults(int sumOfNegs, int posAndLesOrEqA, int lastPair) {
    printf("sum of negative elems: %d\n", sumOfNegs);
    printf("sum of elems in range (0; A]: %d\n", posAndLesOrEqA);

    if (lastPair > 0) {
        printf("number of last pair with different signs: %d\n", lastPair);
    } else {
        printf("no pairs with different signs\n");
    }
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

int* allocIntArray(int n) {
    int* ar = (int*)malloc(n * sizeof(int));
    if (!ar) {
        errno = ENOMEM;
        perror("no memory");
        exit(EXIT_FAILURE);
    }
    return ar;
}

void genRandomValues(int* ar, int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        ar[i] = rand() % (max - min + 1) + min;
    }
}

void setArrayValuesByInput(int* ar, int n) {
    for (int i = 0; i < n; i++) {
        ar[i] = inputInt("elem: ");
    }
}

void displayArray(int* ar, int n) {
    printf("ar = [");
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", ar[i]);
    }
    printf("]\n");
}


int calcSumOfNegs(int* ar, int n) {
    int sumOfNegs = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] < 0) {
            sumOfNegs += ar[i];
        }
    }
    return sumOfNegs;
}

int calcSumOfPosAndLesOrEqA(int* ar, int n, int A) {
    int sumOfPosLesOrEqA = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] > 0 && ar[i] <= A) {
            sumOfPosLesOrEqA += ar[i];
        }
    }
    return sumOfPosLesOrEqA;
}

int determineLastPairOfDiffSigns(int* ar, int n) {
    int lastPair = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] < 0 != ar[i + 1] < 0) {
            lastPair++;
        }
    }
    return lastPair;
}
