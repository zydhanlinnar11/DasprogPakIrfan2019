#include <iostream>

class addClassTwoVariables {
public:
    int add(int a, int b){
        return a+b;
    }
};

class addClassThreeVariables : public addClassTwoVariables {
public:
    int add(int a, int b, int c){
        return a+b+c;
    }
};

class addClassFourVariables : public addClassTwoVariables {
public:
    int add(int a, int b, int c, int d){
        return a+b+c+d;
    }
};

class addClassFiveVariables : public addClassTwoVariables {
public:
    int add(int a, int b, int c, int d, int e){
        return a+b+c+d+e;
    }
};

using std::cout;
using std::endl;

int main() {
    addClassTwoVariables addclass2;
    addClassThreeVariables addclass3;
    addClassFourVariables addclass4;
    addClassFiveVariables addclass5;
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    cout<<"a = "<<a<<endl
        <<"b = "<<b<<endl
        <<"c = "<<c<<endl
        <<"d = "<<d<<endl
        <<"e = "<<e<<endl;
    cout<<"a + b = "<<addclass2.add(a,b)<<endl
        <<"a + b + c = "<<addclass3.add(a,b,c)<<endl
        <<"a + b + c + d = "<<addclass4.add(a,b,c,d)<<endl
        <<"a + b + c + d + e = "<<addclass5.add(a,b,c,d,e)<<endl;
    return 0;
}