#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Создаёт и заполняет массив рандомными значениями
// от min до max или же пользовательским вводом.
// Способ ввода (генерация или клавиатура) задаётся
// пользователем.
int* inputArray(int n, int min, int max);

// Вычисляет все 3 пункта задания.
// Последние 3 параметра будут заданы в вычисленные значения.
void calcEverything(int* ar, int n, int A, int* sumOfNegs, int* posAndLesOrEqA, int* lastPair);

// Отображает в красивом виде на консоль результаты вычислений.
void displayCalculationResults(int sumOfNegs, int posAndLesOrEqA, int lastPair);

/**
 * @brief Функция для ввода значения типа int с сообщением.
 * @param msg Сообщение, которое будет выведено перед вводом значения.
 * @return Введенное значение типа int.
 * Если ввод некорректен, программа выводит сообщение об ошибке и завершает выполнение.
 */
int inputInt(const char* msg);

// Выделяет память под массив из "n" элементов.
// Обрабатывает ситуацию, когда это не удалось.
// Возвращает адрес первого байта выделенного массива.
int* allocIntArray(int n);

// Генерирует случайные значения в массиве ar.
void genRandomValues(int* ar, int n, int min, int max);

// Задаёт значения элементов массива с клавиатуры.
void setArrayValuesByInput(int* ar, int n);

// Отображает элементы массива на консоль
void displayArray(int* ar, int n);

// Вычисляет сумму отрицательных элементов массива
int calcSumOfNegs(int* ar, int n);

// Вычисляет сумму положительных элементов массива,
// не превышающих "a".
int calcSumOfPosAndLesOrEqA(int* ar, int n, int A);

// Возвращает номер последней пары соседних элементов,
// с разными знаками.
// Если пар соседних элементов с разными знаками нет,
// возвращается значение 0.
int determineLastPairOfDiffSigns(int* ar, int n);

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
