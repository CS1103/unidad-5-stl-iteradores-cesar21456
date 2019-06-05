#include <iostream>
#include "range.h"
#include "GeometricProg.h"
#include "FibonacciProg.h"

using namespace std;
int main() {
    for (auto i:ArithmeticProg(5)){
        cout<<"hola ";
    }
    cout<<endl;
    for (auto i:GeometricProg(3,20)){
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i:FibonacciProg(1,1,1000000000)){
        cout<<i<<" ";
    }
}