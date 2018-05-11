#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 0.001;

double dq1(double p1);
double dp1(double q1);
double dq2(double p2);
double dp2(double q1, double q2);

int main()
{
	double dt=0.006;
	double T=3000;
	int Nt = T/dt;
	double d;
	double q1=1.0/(2.0*pow(2.0,0.5));
	double p1=0.0;
	double q2=-1.0/(2.0*pow(2.0,0.5));
	double p2=0.0;
	double q1_new;
	double p1_new;
	double q2_new;
	double p2_new;

	//inicio rungekuta
	
	int i;

	double k1_q1;
	double k1_p1;
	double k1_q2;
	double k1_p2;

	double k2_q1;
	double k2_p1;
	double k2_q2;
	double k2_p2;

	double k3_q1;
	double k3_p1;
	double k3_q2;
	double k3_p2;

	double k4_q1;
	double k4_p1;
	double k4_q2;
	double k4_p2;

	for(i=0;i<Nt;i++)
	{
		k1_q1=dq1(p1);
		k1_p1=dp1(q1);
		k1_q2=dq2(p2);
		k1_p2=dp2(q1, q2);

		k2_q1=dq1(p1 + k1_p1*dt/2);
		k2_p1=dp1(q1 + k1_q1*dt/2);
		k2_q2=dq2(p2 + k1_p2*dt/2);
		k2_p2=dp2(q1 + k1_q1*dt/2, q2 + k1_q2*dt/2);

		k3_q1=dq1(p1 + k2_p1*dt/2);
		k3_p1=dp1(q1 + k2_q1*dt/2);
		k3_q2=dq2(p2 + k2_p2*dt/2);
		k3_p2=dp2(q1 + k2_q1*dt/2, q2 + k2_q2*dt/2);

		k4_q1=dq1(p1 + k3_p1*dt);
		k4_p1=dp1(q1 + k3_q1*dt);
		k4_q2=dq2(p2 + k3_p2*dt);
		k4_p2=dp2(q1 + k3_q1*dt, q2 + k1_q2*dt);
		
		q1_new=q1+dt*(k1_q1 + 2*k2_q1 + 2*k3_q1 + k4_q1)/6.0;
		p1_new=p1+dt*(k1_p1 + 2*k2_p1 + 2*k3_p1 + k4_p1)/6.0;
		q2_new=q2+dt*(k1_q2 + 2*k2_q2 + 2*k3_q2 + k4_q2)/6.0;
		p2_new=p2+dt*(k1_p2 + 2*k2_p2 + 2*k3_p2 + k4_p2)/6.0;

		if(i%100==0/*(q1>0 and q1_new<0) or (q1<0 and q1_new>0)*/)
		{
			cout<<q1<<" "<<q1_new<<endl;			
			/*cout<<p2_new<<" "<<q2_new<<endl;*/
		}
		q1=q1_new;
		p1=p1_new;
		q2=q2_new;
		p2=p2_new;
	}

	return 0;
}
double dq1(double p1)
{
	return p1;
}
double dp1(double q1)
{
	return -2.0*(q1)/(pow((4.0*q1*q1 + EPSILON*EPSILON),1.5));
}
double dq2(double p2)
{
	return p2;
}
double dp2(double q1, double q2)
{
	return (q1-q2)/(pow(pow(q1-q2,2)+pow(EPSILON,2)/4.0,1.5))-(q1+q2)/(pow(pow(q1+q2,2)+pow(EPSILON,2)/4.0,1.5));
}
