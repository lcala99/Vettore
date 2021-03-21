#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[4] = {0,1,2,3};
    Vettore<int> v(4,a);
    cout << v.Size() << endl;
    v.push_back(5);
    v.push_back(8);
    int b=44;
    v.insert(b);
    cout << v.Size() << endl;
    cout << v << endl;
    int c=11;
    v.insert(v.end()-3, c);
    cout << v << endl;
}
