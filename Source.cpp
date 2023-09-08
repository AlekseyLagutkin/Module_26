#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include "msum.h"

int main()
{
	setlocale(LC_ALL, "");
	int i;
	int n = 20;   //Длина массива
	int m = 4;   //Количество частей
	int l = n / m;
	int s = 0;
	int* a = new int[n];   //Основной массив чисел
	int* ar = new int[m];   //Массив сумм подмассивов
	std::cout << "Массив" << std::endl;
	masp ms(n, m, a);
	std::vector <std::thread> tr;   //Вектор для хранения потоков
	std::cout << "Потоки" << std::endl;
	for (i = 0; i < m; ++i)
	{
		tr.push_back(std::thread(ms, i*l, i*l+l, ar));   //Вычисление суммы подмассива
	}
	std::for_each(tr.begin(), tr.end(), [](std::thread& t)
		{ t.join(); });
	s = ms.msum(ar, m);   //Вычисление общей суммы
	std::cout << "Сумма = " << s << std::endl;
	delete[] a;
	delete[] ar;
	return 0;
}