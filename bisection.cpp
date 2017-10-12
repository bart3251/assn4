#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	//return x + 1;	//basic test for error
	//return x - 1;	//basic test for root
	//return 3*x*sin(10*x);	//test a
	return x*exp(-x);	//test b
}
double fpiter(double a, double b, double tol, int maxiter) {
	double error = 10 * tol;
	double fa = f(a);
	double fb = f(b);
	double c = 0; 
	double fc = 0;
	if (fa*fb > 0) {
		cout << "Error" << endl;
		return(NULL);
	}
	int cnt = 0;
	while (error > tol && cnt < maxiter) {
		c = 0.5*(a + b);
		fc = f(c);
		if (fc == 0) {
			return c;
		}
		if (fa*fc < 0) {
			b = c;
			fb = fc;
		}else {
			a = c;
			fa = fc;
		}
		error = b - a;
		cnt++;
	}
	return c;
}
int main() {
	double a = -9.9;
	double b = 10;
	double tol = 0.00001;
	double maxiter = 10000;
	cout<<fpiter(a,b,tol,maxiter)<<endl;

	return 0;
}
