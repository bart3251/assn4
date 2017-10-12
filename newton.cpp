#include<iostream>
#include<cmath>

using namespace std;

double f(double x){
	//return x*x-2;
	//return 3*x*sin(10*x);
	return x*exp(-x);
}
double df(double x){
	//return 2*x;
	//return 3*sin(10*x)+30*x*cos(10*x);
	return -exp(-x)*(x-1);
}

double newtonf(double x0, double tol, int maxiter){
	double error = 10*tol;
	double f0=f(x0);
	double df0 = df(x0);
	int cnt = 0;
	int x1;
	int errorCnt = 0;
	double perror = abs(f0/df0);
	while(error > tol && cnt < maxiter){
		if(df0 == 0){
		//	cout<<"invalid denominator"<<endl;
			x0 = x0 + 0.1;
			f0 = f(x0);
			df0 = df(x0);
			continue;
		}
		cnt++;
		x1 = x0-f0/df0;
		error = abs(x1-x0);
		if(error>perror){
			errorCnt++
			if(errorCnt > 5){cout<<"Diverging, closing program"<<endl;  return NULL;}
		}else{errorCnt=0; perror = error;}   
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
	return 0;
}
