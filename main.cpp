#include "vettore.h"
#include <iostream>
using namespace std;

//g++ -std=c++11 main.cpp
int main(int argc, char *argv[])
{   
    int a[4] = {0,1,2,3};
    Vettore<int> v(4,a);
    cout << v[0];
}
