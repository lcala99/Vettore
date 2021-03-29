#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[7] = {0,1,2,3,4,5,6};
    Vettore<int> v(7,a);
    Vettore<int> ciao(v);
    cout << v << endl;
    cout << ciao << endl;
    ciao.push_back(7);
    cout << v << endl;
    cout << ciao << endl;
    ciao.insert(5);
    ciao.insert(8);
    cout << ciao << endl;
}
