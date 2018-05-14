#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double L = 5.0;
	double l = 2.0;
	double d = 1.0;
	double h = 5.0/512.0;
	double v0 = 100.0;
	int N = 2.0*pow((L/h),2.0);
	int M = 512;

	int i;//recorre en y
	double y;
	int j;//recorre en x
	double x;

	double **V = new double *[M];//V[y,x]
	double **Vold = new double *[M];
	double **Ex = new double *[M];
	double **Ey = new double *[M];
  
	for(i=0;i<M;i++)
	{
		V[i]=new double[M];
		Vold[i]=new double[M];
		Ex[i]=new double[M];
		Ey[i]=new double[M];
	}

	//condiciones frontera potencial:
	//inicializo potencial 0 en todos lados menos en las placas
	for(i=0;i<M;i++)//recorre y
	{
		y=-2.5+i*h;
		for(j=0;j<M;j++)//recorre x
		{
			x=-2.5+j*h;
			if(i>307-1 and i <307+1 and j<358 and j >154)
			{
				Vold[i][j]=v0/2.0;
				V[i][j]=v0/2.0;
			}else if(i>205-1 and i<205+1 and j<358 and j >154)
			{
				Vold[i][j]=-v0/2.0;
				V[i][j]=-v0/2.0;
			}else
			{
				Vold[i][j]=0;
				V[i][j]=0;
			}
		}
	}
	//metodo de "rela"
	int k;
	for(k=0;k<5000;k++)//iteraciones hasta 5000 porque se demoraba mucho con n=2*pow(L/h,2.0). si quiere cambielo pero se demora mucho
	{
		for(i=1;i<M-1;i++)//recorre y
		{
			for(j=1;j<M-1;j++)//recorre x
			{
				if(i>307-1 and i <307+1 and j<358 and j >154)
				{
					V[i][j]=v0/2.0;
				}else if(i>205-1 and i<205+1 and j<358 and j >154)
				{
					V[i][j]=-v0/2.0;
				}else
				{
					V[i][j]=((Vold[i+1][j]+V[i-1][j]+Vold[i][j+1]+V[i][j-1])/4.0);
				}
			}
		}
		
		for(i=0;i<M;i++)//recorre y
		{
			for(j=0;j<M;j++)//recorre x
			{
				Vold[i][j]=V[i][j];
			}
		}	
	}
	
	//encuentra el campo
	for(i=1;i<M-1;i++)//recorre y
	{
		for(j=1;j<M-1;j++)//recorre x
		{
			Ex[i][j]=-(V[i][j-1]-V[i][j+1])/(2*h);
			Ey[i][j]=(V[i-1][j]-V[i+1][j])/(2*h);
		}
	}	
	
	//impresion
	for(i=M-2;i>0;i--)
	{
		for(j=1;j<M-1;j++)
		{
			cout<<V[i][j]<<" "<<Ex[i][j]<<" "<<Ey[i][j]<<endl;
		}
		cout<<endl;
	}

	return 0;
}
