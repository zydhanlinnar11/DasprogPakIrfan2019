#include <iostream>
#include <cmath>
#include <string>

#define ull unsigned long long

using std::cout;
using std::endl;

class Calculator {
public:
    void determineOperation(double, double, std::string);
    Calculator() {
        result = (double)0;
        fail = 0;
        cout<<"Welcome to Calculator App"<<endl
            <<"Function -> Input format:"<<endl
            <<"Addition -> a + b"<<endl
            <<"Minus -> a - b"<<endl
            <<"Multiplication -> a x b"<<endl
            <<"Division -> a / b"<<endl
            <<"Power -> a ^ b"<<endl
            <<"a-th root of b -> a root b      (b >= 0) (a != 0)"<<endl
            <<"Modulo -> a mod b               (a and b must integer)"<<endl
            <<"Logarithm -> (basis) log n      (basis > 1 and n > 0)"<<endl
            <<"Permutation -> a P b            (a and b must integer) (a >= b)"<<endl
            <<"Combination -> a C b            (a and b must integer) (a >= b)"<<endl
            <<"Note: need space between number and operator"<<endl
            <<"Input: ";
    };
private:
    unsigned fail;
    double result;
    void plus(double a, double b) {result = a+b;};
    void minus(double a, double b) {result = a-b;};
    void multiply(double a, double b) {result = a*b;};
    void divide(double a, double b) {result = a/b;};
    void modulo(ull a, ull b) {result = (int)a%(int)b;};
    void logarithm(double a, double b) {result = log(b)/log(a);};
    void power(double a, double b) {result = pow(a, b);};
    void permutation(ull a, ull b) {result = factorial(a)/factorial(a-b);};
    void combination(ull a, ull b) {result = factorial(a)/(factorial(a-b)*factorial(b));};
    void rootof(double a, double b) {result = pow(b, 1/a);};
    ull factorial(ull);
};

ull Calculator::factorial(ull n) {
    if(n<=1) return 1;
    else return n*factorial(n-1);
}

using std::cin;

void Calculator::determineOperation(double a, double b, std::string s) {
    if(s=="+") plus(a, b);
    else if (s=="-") minus(a,b);
    else if (s=="x") multiply(a,b);
    else if (s=="/") divide(a,b);
    else if (s=="log") {
        if(a==1 || a==0) fail=3;
        else if(a<0 || b<0) fail=4;
        else logarithm(a,b);
    }
    else if (s=="^") power(a,b);
    else if (s=="mod") {
        double intpart1, intpart2;
        if(modf(a, &intpart1) != 0.0 || modf(b, &intpart2) != 0.0) fail=1;
        else modulo((ull)a, (ull)b);
    } else if (s=="P") {
        double intpart1, intpart2;
        if(modf(a, &intpart1) != 0.0 || modf(b, &intpart2) != 0.0) fail=1;
        else if(a<b) fail=5;
        else permutation((ull)a, (ull)b);
    } else if (s=="C") {
        double intpart1, intpart2;
        if(modf(a, &intpart1) != 0.0 || modf(b, &intpart2) != 0.0) fail=1;
        else if(a<b) fail=5;
        else combination((ull)a, (ull)b);
    } else if (s=="root") {
        if(b>=0 && a!=0) rootof(a, b);
        else fail=6;
    } else fail=2;
    if(fail==1) cout<<"Sorry, "<<s<<" operator only support integer value."<<endl;
    else if(fail==0) cout<<"Result = "<<result<<endl;
    else if(fail==2) cout<<"Wrong operator"<<endl;
    else if(fail==3) cout<<s<<" operator does not support basis 0 or 1"<<endl;
    else if(fail==4) cout<<s<<" operator does not support negative value of basis or n"<<endl;
    else if(fail==5) cout<<s<<" operator needs a >= b"<<endl;
    else if(fail==6) cout<<s<<" operator needs b >= 0 and a != 0"<<endl;
}

int main() {
    double x, y;
    std::string s;
    Calculator kalkulator;
    cin>>x>>s>>y;
    kalkulator.determineOperation(x,y,s);
    return 0;
}