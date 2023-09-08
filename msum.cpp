#include <iostream>
#include <thread>
#include <stdlib.h>
#include <vector>
#include "msum.h"

masp::masp(int _n, int _m, int *_a): n(_n), m(_m), a(_a)   //Размер массива, количество частей
{
	for (i = 0; i < n; ++i)   //Заполнение массива
	{
		a[i] = i+1;
	}
	l = n / m;   //Длина одной части массива
	for (i = 0; i < n; ++i)
	{
		std::cout << a[i] << " ";   //Вывод массива по частям
		if ((i+1)%l==0)
		{
			std::cout << '\n';   
		}
	}
	std::cout << '\n';
}

void masp:: operator () (int fi, int la, int *ar)   //Подсчет суммы подмассива
{
	int i;
	int s = 0;
	for (i = fi; i < la; ++i)
	{
		s = s + a[i];
	}
	ar[fi / l] = s;   //Запись в массив сумм
	std::cout << "s = " << s << std::endl;
}

int masp::msum(int *b, int l)   //Вычисление суммы массива
{
	int i;
	int s = 0;
	for (i = 0; i < l; ++i)
	{ 
		s = s + b[i];
	}
	return s;
}

masp::~masp()
{
	
}