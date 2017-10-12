#include<iostream>
#include<cmath>

using namespace std;

double f(double x){
        //return x*x-2;
        //return 3*x*sin(10*x);
        return x*exp(-x);
}
double secant(double x0, double x1, double tol, int maxiter){
        double error = 10*tol;
        double f0=f(x0);
        int cnt = 0;
        double x2;
        while(error > tol && cnt < maxiter){
                cnt++;
                x2 = x1-(f(x1)*(x1-x0))/(f(x1)-f(x0));
                error = abs(x1-x0);
                x0 = x1;
		x1 = x2;
        }
        return x0;
}
int main(){
        double x0 = 55555;
	double x1 = 10;
        double tol = 0.0001;
        int maxiter = 1000;
        cout<<secant(x0,x1,tol,maxiter)<<endl;
        return 0;
}
