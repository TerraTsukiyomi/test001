#include <stdio.h>
#include <math.h>
#include <time.h>


#define N 100
#define NULL

double A[N][N], F[N], mf, X[N], X1[N], S[N], msf;
int i, j;
long int dt;
double t, e;

int main()
{
#pragma once
	struct timeval
	{
		int    tv_sec;         /* секунды */
		int    tv_usec;        /* микросекунды */
	};
	struct timeval tv1, tv2;
	/* Генерація даних. Тут задається матриця, з елементами, які дорівнюють
	значенню 1, а елементи діагоналі дорівнюють значенню 2. Матриця береться
	добре обумовленою.
	* у правій частині, що дорівнює N+1, усі корені будуть дорівнювати 1. */
	mf = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			(i == j) ? (A[i][j] = 2) : (A[i][j] = 1);
		F[i] = N + 1;
		/* Розраховується сума квадратів елементів вектора F,
		* тобто підкорений вираз. */
		mf += F[i] * F[i];
	}
	/* Задаються кроки t і e. */
	t = 0.01;
	e = 0.00001; 
	/* Задається начальне приближення коренів. В Х1 зберігаються значення коренів (к+1)-ї ітерації */
	for (i = 0; i < N; i++)
		X1[i] = 0.6;
	/* Визначається стартовий час виконання обчислень. */
	int gettimeofday(struct timeval &tv1, struct timezone NULL);
	do
	{
		for (i = 0; i < N; i++)
			/* В Х зберігаються значення коренів к-ї ітерації */
			X[i] = X1[i];
		for (msf = 0, i = 0; i < N; i++)
		{
			for (S[i] = 0, j = 0; j < N; j++)
				S[i] += A[i][j] * X[j];
			X1[i] = X[i] - t * (S[i] - F[i]);
			/* Розраховується сума квадратів елементів нев’язки */
			//msf += (S[i]–F[i])*(S[i]–F[i]);
			msf += (S[i]-F[i])*(S[i]-F[i]);
		}
	} while (msf / mf > e*e); /* Перевіряється вилога (1). */
						   /* Розраховується час закінчення обчислень. */
	int gettimeofday(struct timeval &tv2, struct timezone NULL);
	dt = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
	//dt = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
	/* Вивід часу обчислень. */
	printf(" Time= %d\n", dt);
	/* вивід перших 4-х коренів */
	for (i = 0; i < 4; i++)
		printf(" %f\n", X[i]);
	return(0);
}