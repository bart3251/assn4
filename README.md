# Assignment 4
## Shaun Bartschi

1. The code for newtonf(), the fast running implementation of Newton's method. Software Manual entry found  on github.com/bart251 under Software library/ README.md
```C++
#include<iostream>
#include<cmath>

using namespace std;

double f(double x){
        return x*x-2;
}
double df(double x){
        return 2*x;
}

double newtonf(double x0, double tol, int maxiter){
        double error = 10*tol;
        double f0=f(x0);
        double df0 = df(x0);
        if(df0 == 0){cout<<"uh oh"<<endl;}
        int cnt = 0;
        double x1;
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
```
2.  Error checking for stationary points and divergence was implemented in the following C++ code.  Software Manual entry found  on github.com/bart251 under Software library/ README.md
```C++
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

double newton(double x0, double tol, int maxiter){
        double error = 10*tol;
        double f0=f(x0);
        double df0 = df(x0);
        int cnt = 0;
        double x1;
        int errorCnt = 0;
        double perror = abs(f0/df0);
        while(error > tol && cnt < maxiter){
                if(df0 == 0){
                //      cout<<"invalid denominator"<<endl;
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
        cout<<newton(x0,tol,maxiter)<<endl;
        return 0;
}
```
3.  Both Newton's method and bisection seem to converge rather quickly for both problems, although intuitively newton's method likely runs faster.  Both algorithms also produce the correct answers.
4.  The following is a C++ implementation of the secant method. Software Manual entry found  on github.com/bart251 under Software library/ README.md
```C++
include<iostream>
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
                error = abs(x2-x1);
                x0 = x1;
                x1=x2;
        }
        return x0;
}
int main(){
        double x0 = -1;
        double x1 = 1;
        double tol = 0.0001;
        int maxiter = 1000;
        cout<<secant(x0,x1,tol,maxiter)<<endl;
        return 0;
}
```
5. Bisection:

Newton's Method:

Secant Method:

6. The hybridized newton-bisection method is detailed below in C++ code: Software Manual entry found  on github.com/bart251 under Software library/ README.md
```C++
#include <iostream>
#include <cmath>

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

double bisectionh(double a, double b, double tol, int maxiter) {
        double error = 10 * tol;
        double fa = f(a);
        double fb = f(b);
        double c = 0;
        double fc = 0;
        if (fa*fb > 0) {
                cout << "Error" << endl;
                return(a);
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

double newtonh(double x0, double tol, int maxiter){
        double error = 10*tol;
        double f0=f(x0);
        double df0 = df(x0);
        int cnt = 0;
        double x1;
        int errorCnt = 0;
        double perror = abs(f0/df0);
        while(error > tol && cnt < maxiter){
                if(df0 == 0){
                //      cout<<"invalid denominator"<<endl;
                        x0 = x0 + 0.1;
                        f0 = f(x0);
                        df0 = df(x0);
                        continue;
                }
                cnt++;
                x1 = x0-f0/df0;
                error = abs(x1-x0);
                if(error>=perror){
                        errorCnt++
                        if(errorCnt > 2){x0 = bisectionh(x0,x1,tol,4);}
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
        cout<<newtonh(x0,tol,maxiter)<<endl;
        return 0;
}
```
7. The hybridized secant-bisection method is shown below in C++ code. Software Manual entry found  on github.com/bart251 under Software library/ README.md
```C++
#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
        //return x*x-2;
        //return 3*x*sin(10*x);
        return x*exp(-x);
}

double bisectionh(double a, double b, double tol, int maxiter) {
        double error = 10 * tol;
        double fa = f(a);
        double fb = f(b);
        double c = 0;
        double fc = 0;
        if (fa*fb > 0) {
                cout << "Error" << endl;
                return(a);
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

double secanth(double x0, double x1, double tol, int maxiter){
        double error = 10*tol;
        double f0=f(x0);
        int cnt = 0;
        double x2;
        while(error > tol && cnt < maxiter){
                cnt++;
                if(cnt%4 != 0){x2 = x1-(f(x1)*(x1-x0))/(f(x1)-f(x0));}
                else{x2 = bisectionh(x0,x1,tol,4);}
                error = abs(x2-x1);
                x0 = x1;
                x1=x2;
        }
        return x0;
}

int main(){
        double x0 = 0;
        double x1=1;
        double tol = 0.0001;
        int maxiter = 1000;
        cout<<secanth(x0,x1tol,maxiter)<<endl;
        return 0;
}
```
