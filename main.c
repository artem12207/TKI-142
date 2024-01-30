#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <float.h>
#include <math.h>

/**
* @brief Пользовательский ввод
*/
enum user_input
{
/**
* @brief Объём
*/
VOLUME = 1,
/**
* @brief Площадь поверхности
*/
SURFACE_AREA = 2
};

/**
* @brief Получает целое значение
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Целое значение
*/
int get_choice();

/**
* @brief Функция для проверки ввода радиуса фигуры
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Радииус фигуры
*/
double get_radius();

/**
* @brief Функция для подсчёта объёма шара
* @param r - радиус шара
* @return Периметр прямоугольника
*/
double get_volume(double r);

/**
* @brief Функция для подсчёта площади поверхности шара
* @param r - радиус шара
* @return Площадь прямоугольника
*/
double get_surface_area(double r);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
setlocale(LC_ALL, "RU");

puts("Введите номер соответствующий заданию:\n");
printf("%d - для вычисления объёма шара\n", VOLUME);
printf("%d - для вычисления площади поверхности шара\n", SURFACE_AREA);

int choice = get_choice();

enum user_input figure = (enum user_input)choice;

puts("Введите радиус шара: ");
double r = get_radius();

switch (figure)
{
case VOLUME:
{
double volume = get_volume(r);
printf("%lf - объём шара", volume);
break;
}
case SURFACE_AREA:
{
double surface_area = get_surface_area(r);
printf("%lf - площадь поверхности шара", surface_area);
break;
}
default:
{
errno = EDOM;
perror("Ошибка ввода");
return EXIT_FAILURE;
}
}

return EXIT_SUCCESS;
}

int get_choice()
{
int choice;
int result = scanf("%d", &choice);
if (result != 1)
{
errno = EIO;
perror("Ошибка ввода");
abort();
}

return choice;
}

double get_radius()
{
double radius;
int result = scanf("%lf", &radius);
if (result != 1 && radius <= 0)
{
errno = EIO;
perror("Введено неправильное значение");
abort();
}
return radius;
}

double get_volume(double r)
{
return (4 / 3) * 3.14159265358979323846 * pow(r,3);
}

double get_surface_area(double r)
{
return 4 * 3.14159265358979323846 * pow(r,2);
}
