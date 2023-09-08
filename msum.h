#pragma once

class masp {

public:
	masp(int _n, int _m, int *a);   //Размер массива, количество частей, массив

	int msum(int *b, int l);   //Подсчет суммы 
	void operator () (int fi, int la, int *ar);   //Подсчет суммы подмассива, номер первого и последнего индекса, массив для записи результата
	~masp();

private:
	int i;
	int n;
	int m;
	int l;
	int* a;
};



