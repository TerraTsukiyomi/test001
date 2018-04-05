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
		int    tv_sec;         /* ������� */
		int    tv_usec;        /* ������������ */
	};
	struct timeval tv1, tv2;
	/* ��������� �����. ��� �������� �������, � ����������, �� ���������
	�������� 1, � �������� ������� ��������� �������� 2. ������� ��������
	����� �����������.
	* � ����� ������, �� ������� N+1, �� ����� ������ ���������� 1. */
	mf = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			(i == j) ? (A[i][j] = 2) : (A[i][j] = 1);
		F[i] = N + 1;
		/* ������������� ���� �������� �������� ������� F,
		* ����� ��������� �����. */
		mf += F[i] * F[i];
	}
	/* ��������� ����� t � e. */
	t = 0.01;
	e = 0.00001; 
	/* �������� �������� ����������� ������. � �1 ����������� �������� ������ (�+1)-� �������� */
	for (i = 0; i < N; i++)
		X1[i] = 0.6;
	/* ����������� ��������� ��� ��������� ���������. */
	int gettimeofday(struct timeval &tv1, struct timezone NULL);
	do
	{
		for (i = 0; i < N; i++)
			/* � � ����������� �������� ������ �-� �������� */
			X[i] = X1[i];
		for (msf = 0, i = 0; i < N; i++)
		{
			for (S[i] = 0, j = 0; j < N; j++)
				S[i] += A[i][j] * X[j];
			X1[i] = X[i] - t * (S[i] - F[i]);
			/* ������������� ���� �������� �������� ������� */
			//msf += (S[i]�F[i])*(S[i]�F[i]);
			msf += (S[i]-F[i])*(S[i]-F[i]);
		}
	} while (msf / mf > e*e); /* ������������ ������ (1). */
						   /* ������������� ��� ��������� ���������. */
	int gettimeofday(struct timeval &tv2, struct timezone NULL);
	dt = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
	//dt = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;
	/* ���� ���� ���������. */
	printf(" Time= %d\n", dt);
	/* ���� ������ 4-� ������ */
	for (i = 0; i < 4; i++)
		printf(" %f\n", X[i]);
	return(0);
}