#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double c = 2.0;
	double L = 100;
	double T = 200;
	double dx = 0.01;
	double dt = 0.001;
	int Nx = L/dx +1;
	int Nt = T/dt +1;
	int Nsnaps = 20;
	
	double **uxt_print = new double *[Nsnaps];//arreglo que se va a imprimir
	
	int i;//recorre tiempo
	int j;//recore x
	for(i=0;i<Nsnaps;i++)
	{
		uxt_print[i]= new double[Nx];
	}
	//arreglos iterativos
	double *uxtnew = new double[Nx];
	double *uxtcenter = new double[Nx];
	double *uxtold = new double[Nx];
	//inicializacion en t = 0
	double x;
	for(j=0;j<Nx;j++)
	{
		x = j*dx;
		if(x<=0.8*L)
		{
			uxtold[j]=1.25*x/L;
			uxtcenter[j]=1.25*x/L;
		}
		else
		{
			uxtold[j]=5.0-5.0*x/L;
			uxtcenter[j]=5.0-5.0*x/L;
		}
		//cout<<x<<" "<<uxtold[j]<<endl;
	}
	uxtnew[0]=0;
	uxtnew[Nx-1]=0;
	//recursion ec. dif. 
	for(i=1;i<Nt;i++)
	{
		for(j=1;j<Nx-1;j++)
		{
			utxnew[j]=c*c*dt*dt*(uxtcenter[i+1]+uxtcenter[i-1]-2.0*uxtcenter[i])/(dx*dx)+2.0*uxtcenter[i]-uxtold[i];
		}
		for(j=0;j<Nx;j++)
		{
			uxtold[j]=uxtcenter[j];
			uxtcenter[j]=uxtnew[j];
		}
	}
	
	
	return 0;
}
