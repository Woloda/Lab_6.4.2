
// 2 Спосіб --- "Рекурсивний
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>

void value_elements(double* masuv_b, const int elements, double Low, int High, int index, int diapazon);
void vuvestu(double* masuv_b, const int elementsm, int index);
double min_values(double* masuv_b, const int elements, int index, double min);
double suma(double* masuv_b, const int elements, int index, double sum, int k_index);
void sortirovka(double* masuv_b, const int elements, int index, int pp_index, double p_index, double value);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int k_elementiv;
	std::cout << "Введіть кількість дійсних елементів: ";
	std::cin >> k_elementiv;
	std::cout << std::endl;
	const int elements = k_elementiv;
	double* masuv_b = new double[elements];

	double Low = 0.01;
	int High = 200;
	int diapazon = 2;

	value_elements(masuv_b, elements, Low, High, 0, diapazon);

	std::cout << "сформований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(masuv_b, elements, 0);

	int p_index = 0;
	double min = min_values(masuv_b, elements, 1, masuv_b[p_index]);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "мінімальний елемент масиву b: " << min << std::endl;
	std::cout << std::endl;

	double sum = suma(masuv_b, elements, 0, 0, elements - 1);
	if (sum == 0)
		std::cout << "не існує елемнтів розташованих між першим і останнім додатними елементами: " << std::endl;
	else
		std::cout << "Суму елементів масиву, розташованих між першим і останнім додатними елементами: " << sum << std::endl;
	std::cout << std::endl;

	sortirovka(masuv_b, elements, 0, 0, 0, 0);
	std::cout << "Модифікований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(masuv_b, elements, 0);
	std::cout << std::endl;

	delete[] masuv_b;

	return 0;
}

void value_elements(double* masuv_b, const int elements, double Low, int High, int index, int diapazon)
{
	masuv_b[index] = Low * (rand() % (2 * High)) - diapazon;
	if (index < elements - 1)
		value_elements(masuv_b, elements, Low, High, index + 1, diapazon);
	else;

}

void vuvestu(double* masuv_b, const int elements, int index)
{
	std::cout << std::setprecision(2) << std::setw(6) << masuv_b[index];
	if (index < elements - 1)
		vuvestu(masuv_b, elements, index + 1);
	else;
}

double min_values(double* masuv_b, const int elements, int index, double min)
{
	if (min > masuv_b[index])
		min = masuv_b[index];
	else;
	if (index < elements - 1)
		return min_values(masuv_b, elements, index + 1, min);
	else
		return min;
}

double suma(double* masuv_b, const int elements, int index, double sum, int k_index)
{
	if (masuv_b[index] > 0)
	{
		for (; masuv_b[k_index] < 0; k_index--);
		for (index++; index < k_index; index++)
			sum += masuv_b[index];
		index = elements;
	}
	else;
	if (index < elements - 1)
		return suma(masuv_b, elements, index + 1, sum, k_index);
	else
		return sum;
}

void sortirovka(double* masuv_b, const int elements, int index, int pp_index, double p_index, double value)
{
	value = masuv_b[index];
	if ((0 <= value && value < 1) || (-1 < value && value <= 0))
	{
		p_index = masuv_b[pp_index];
		masuv_b[pp_index] = masuv_b[index];
		masuv_b[index] = p_index;
		pp_index++;
	}
	else;
	if (index < elements - 1)
		sortirovka(masuv_b, elements, index + 1, pp_index, p_index, value);
	else;

}