#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <errno.h>
#include <time.h>
#include <locale.h>

/**
 * @brief функция, выполняющая проверку введенного пользователем числа
 * @return ошибку в случае, если пользователь ввел не число или ввел не одно значение
 */
int input(void);

/**
 * @brief функция, выполняющая проверку на положительное число
 * @return ошибку в случае, если пользователь ввел отрицательное число
 */
int pozitiv_input(void);

/**
 * @brief функция, создающая массив
 * @param n переменная, отвечающая за размер массива
 * @return возвращает созданный массив
 */
int* create_array(const size_t n);

/**
 * @param INPUT отвечате за заполнение массива из потока ввода
 * @param RANDOM отвечает за рандомнное заполнение массива
 */
enum choice{ 
    INPUT = 0, RANDOM = 1
};

/**
 * @brief заполняет массив рандомными числами
 * @param array - указатель на массив (эквивалентно array[])
 * @param n переменная, отвечающая за размер массива
 * @param min переменная, хранящая в себе минимальное число
 * @param max переменная, хранящая в себе максимальное число
 */
void random_filling(int *array, const size_t n);

/**
 * @brief заполняет массив пользовательским вводом
 * @param array - указатель на массив (эквивалентно array[])
 * @param n перемнная, отвечающая за размер массива
 */
void user_input(int *array, const size_t n);

/**
 * @brief функция которая печатает массив
 * @param array указатель на массив (эквивалентно array []) 
 * @param n перменная, отвечающая за размер массива
 */
void print_array(const int *array, const size_t n);

/**
 * @brief функция, проверяющая адресс
 * @return в случае, если адрессс нулевой, программа закрывается
 */
void check_array(const int * array);

/**
 * @brief создает новый массив на копии старого
 * @param array указатель на массив 
 */
int* copy_array(const int *array, const size_t n);

/**
 * @brief функция, считающая сумму отрицательных элементов
 * @param *array указатель на массив
 * @param n переменная, отвечающая за размер массива
 * @return возвращает рассчитанную сумму
 */
int sum_of_the_negative_elements(const int *array, const size_t n);

/**
 * @brief функция, считающая кол-во положительных элементов непревосходящих заданного числа
 * @param *array указатель на массива 
 * @param n переменная, отвечающая за размер массива
 * @param a заданное число
 * @return кол-во таких элементов
 */
int number_of_positive_elements_depending_on_A(const int *array, const size_t n, const int a);

/**
 * @brief функция, считающая кол-во пар с разными знаками
 * @param *array указатель на массив
 * @param n переменная отвечающая за размер массива
 * @return возвращает кол-во таких пар
 */
int pairs_of_elements(const int *array, const size_t n);

int number_of_the_last_pair(const int *array, const size_t n);
