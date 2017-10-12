#include<iostream>
#include<cmath>

using namespace std;

double f(double x){
	return x*x-1;
}
double df(double x){
	return 2*x;
}

double newtonf(double x0, double tol, int maxiter){
	double error = 10*tol;
	double f0=f(x0);
	double df0 = df(x0);
	int cnt = 0;
	int x1;
	while(error > tol && cnt < maxiter){
		cnt++;
		x1 = x0-f0/df0;
		error = abs(x1-x0);
		x0 = x1;
		f0 = f(x0);
		df0 = df(x0);
	}
	return x0;
}
int main(){
	double x0 = 0;
	double tol = 0.0001;
	int maxiter = 1000;
	cout<<newtonf(x0,tol,maxiter)<<endl;
}
