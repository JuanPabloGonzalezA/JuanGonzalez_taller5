#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 0.001;

double dq1(double p1);
double dp1(double q1);
double dp1(double q1);
double dp2(double q1, double q2);

int main()
{
	double dt=0.006;
	double T=3000;
	int Nt = T/dt;
	double q1=1.0/(2.0*sqrt(2.0));
	cout<<EPSILON<<" "<<12<<endl;
	cout<<EPSILON<<" "<<12<<endl;
	return 0;
}
double dq1(double p1)
{
	return p1;
}
double dq2(double p2)
{
	return p2;
}
double dp1(double q1)
{
	return -1.0*(q1)/(pow((4.0*q1*q1 + EPSILON*EPSILON),1.5));
}
double dp2(double q1, double q2)
{
	return (q1-q2)/(pow(pow(q1-q2,2)+pow(EPSILON,2)/4.0,1.5))-(q1+q2)/(pow(pow(q1+q2,2)+pow(EPSILON,2)/4.0,1.5));
}
