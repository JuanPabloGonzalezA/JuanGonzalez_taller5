#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double L = 5;
	double l = 2;
	double d = 1;
	double h = 5/215;
	double v0 = 100;
	int N = 2.0*pow((L/h),2);
	int M = 512;

	int i;//recorre en x
	int j;//recorre en y
	

	double **V = new double *[M];//V[x,y]
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
		for(j=0;j<M;j++)
		{
			V[i][j]=i;
			Ex[i][j]=1;
			Ey[i][j]=2;
		}
	}
	
	//impresion
	for(i=1;i<M-1;i++)
	{
		for(j=1;j<M-1;j++)
		{
			cout<<V[i][j]<<" "<<Ex[i][j]<<" "<<Ey[i][j]<<endl;
		}
		cout<<endl;
	}

	return 0;
}
