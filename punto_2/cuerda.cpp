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
	int Nsnaps = 20;
	
	double **uxt = new double *[Nsnaps];
	
	int i;//recorre tiempo
	int j;//recore x
	for(i=0;i<Nsnaps;i++)
	{
		uxt[i]= new double[Nx];
	}
	
	
	return 0;
}
