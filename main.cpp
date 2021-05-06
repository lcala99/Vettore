#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[7] = {0,1,2,3,4,5,6};
    Vettore<int> v(7,a);
    Vettore<int> ciao(v);
    auto it = v.begin();
    auto it2 = v.begin()+5;
    Vettore<int> u(it,it2);
    cout << u;
}
