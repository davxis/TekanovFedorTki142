#include "4.h"

int main(void)
{ 
    printf("Введите размер массива\n");
    const size_t n = (size_t)pozitiv_input();
    int* array = create_array(n);

    printf("Выберите метод заполнения массива.\n");
    printf("%d - ручной ввод, %d - случайное заполнение\n", INPUT, RANDOM);
    int dependet = pozitiv_input();
    switch (dependet) {
        case INPUT:
            user_input(array, n);
            break;
        case RANDOM:
            random_filling(array, n);
            break;
        default:
            printf("Неверный ввод.\n");
            free(array);
            exit(EXIT_FAILURE);
    }

    print_array(array, n);

    printf("Эта программа подсчитывает сумму неотрицательнхы элементов массива\n");
    int sum_negativ = sum_of_the_negative_elements(array, n);
    printf("Сумма таких элементов: %d\n", sum_negativ);

    printf("Пожалуйста введите целочисленное положительное число A\n");
    int a = pozitiv_input(); 
    int counter = number_of_positive_elements_depending_on_A(array, n, a);
    printf("Кол-во положительных элементов массива < A: %d\n", counter);

    printf("Так же эта программа находит номер последней пары, в который элементы имеют разные знаки");
    int pairs = number_of_the_last_pair(array, n);
    printf("Номер этой пары: %d", pairs);

    free(array);
    return 0;
}



int input(void) {
    int value;
    if (scanf("%d", &value) != 1) {
        perror("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
    return value;
}

int pozitiv_input(void) {
    int value = input();
    if (value <= 0) {
        perror("Ошибка: введено некорректное число (должно быть > 0)");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* create_array(const size_t n) {
    int* array = (int*)malloc(n * sizeof(int));
    check_array(array);
    return array;
}

void random_filling(int *array, const size_t n) {
    check_array(array);

    printf("Введите минимальное и максимальное значение:\n");
    int min = input();
    int max = input();

    if (min > max) {
        printf("Ошибка: минимальное значение больше максимального.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void user_input(int *array, const size_t n) {
    check_array(array);
    for (size_t i = 0; i < n; ++i) {
        printf("Введите %zu-й элемент:\n", i + 1);
        array[i] = input();
    }
}

void print_array(const int *array, const size_t n) {
    check_array(array);
    printf("Ваш массив: [");
    for (size_t i = 0; i < n; ++i) {
        printf("%d%s", array[i], (i < n - 1) ? ", " : "]\n");
    }
}

void check_array(const int *array) {
    if (!array) {
        perror("Ошибка: массив не выделен");
        exit(EXIT_FAILURE);
    }
}

int* copy_array(const int *array, const size_t n) {
    check_array(array);
    int* new_array = (int*)malloc(n * sizeof(int));
    check_array(new_array);

    for (size_t i = 0; i < n; ++i) {
        new_array[i] = array[i];
    }
    return new_array;
}

int sum_of_the_negative_elements(const int *array, const size_t n)
{ 
    check_array(array);

    int sum = 0;
    int nema = 0;
    for(size_t i = 0; i < n; i++)
    { 
        if (array[i] < 0)
        { 
            sum += array[i];
        }
        else
        { 
            nema++;
        }
    }
     
    if (nema == n)
    { 
        printf("В вашем массиве нет отрицательных элементов\n");
    }
    
    return sum;
}

int number_of_positive_elements_depending_on_A(const int *array, const size_t n, const int a)
{
    check_array(array);
    int counter = 0;
    for(size_t i = 0; i < n; i++)
    { 
        if (array[i] > 0 && array[i] < a)
            counter++;
    }

    if (counter == 0)
    { 
        printf("Таких элементов не нашлось\n");
    }

    return counter;
}

int pairs_of_elements(const int *array, const size_t n)
{ 
    check_array(array);
    int counter = 0;
    for (size_t i = 0; i < n - 1; i++)
    { 
        if ((array[i] * array[i + 1])< 0 )
            counter++;
    }

    if (counter == 0)
        printf("Таких пар в вашем массиве нет\n");

    return counter;
}

int number_of_the_last_pair(const int *array, const size_t n)
{ 
    check_array(array);

    
    for (size_t i = n - 1; i > 0; i--) 
    { 
        if ((array[i] * array[i - 1]) < 0) 
            return i - 1; 
    }

    
    printf("Таких пар в вашем массиве нет\n");
    return -1; 
}
