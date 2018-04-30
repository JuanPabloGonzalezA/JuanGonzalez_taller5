#include <iostream>
#include <math.h>

using namespace std;

int main{
	double L = 5;
	double l = 2;
	double d = 1;
	double h = 5/215;
	double v0 = 100;
	int N = 2.0*pow((L/h),2);
	int M = 512;

	int i;
	int j;
	

	double **V = new double *[M];
	double **Ex = new double *[M];
	double **Ey = new double *[M];
  
	for(i=0;i<M;i++)
	{
		V[i]=new double[M];
		Ex[i]=new double[M];
		Ey[i]=new double[M];
	}

	for(i=0;i<M;i++)
	{
	
	}

	return 0;
}
