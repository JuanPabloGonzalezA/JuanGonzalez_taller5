#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double c = 2.0;
	double L = 100;
	double T = 200;
	double dx = 1;
	double dt = 0.1;
	int Nx = L/dx +1;
	int Nt = T/dt +1;
	int Nsnaps = 20;
	
	int i;//recorre tiempo
	int j;//recore x
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
		cout<<uxtold[j]<<" ";
	}
	cout<<endl;
	uxtnew[0]=0;
	uxtnew[Nx-1]=0;
	//recursion ec. dif. 
	int snap = 0;
	for(i=1;i<Nt;i++)
	{
		int t=i*dt;
		if(t!=0 and t % 10 == 0)
		{
			for(j=0;j<Nx;j++)
			{
				cout<<uxtold[j]<<" ";
			}
			cout<<endl;
		}
		for(j=1;j<Nx-1;j++)
		{
			uxtnew[j]=c*c*dt*dt*(uxtcenter[j+1]+uxtcenter[j-1]-2.0*uxtcenter[j])/(dx*dx)+2.0*uxtcenter[j]-uxtold[j];
		}
		for(j=0;j<Nx;j++)
		{
			uxtold[j]=uxtcenter[j];
			uxtcenter[j]=uxtnew[j];
		}
	}

	return 0;
}
