#include <stdio.h>

/**
 * @brief Вычисляет площадь прямоугольника.
 * 
 * @param width Ширина прямоугольника.
 * @param height Высота прямоугольника.
 * @return Площадь прямоугольника.
 */
double rectangle_area(double width, double height) {
    return width * height;
}

/**
 * @brief Вычисляет площадь треугольника по формуле Герона.
 * 
 * @param a Длина первой стороны треугольника.
 * @param b Длина второй стороны треугольника.
 * @param c Длина третьей стороны треугольника.
 * @return Площадь треугольника.
 */
double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2; // Полупериметр
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Формула Герона
}

int main() {
    double width, height;
    double a, b, c;

    // Ввод данных для прямоугольника
    printf("Введите ширину прямоугольника: ");
    scanf("%lf", &width);
    printf("Введите высоту прямоугольника: ");
    scanf("%lf", &height);

    // Вычисление и вывод площади прямоугольника
    double rect_area = rectangle_area(width, height);
    printf("Площадь прямоугольника: %.2lfn", rect_area);

    // Ввод данных для треугольника
    printf("Введите длины сторон треугольника (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Вычисление и вывод площади треугольника
    double tri_area = triangle_area(a, b, c);
    printf("Площадь треугольника: %.2lfn", tri_area);

    return 0;
}
