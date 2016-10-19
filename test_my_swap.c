#include<iostream>
#include "myswap.h"

using std::cout;
using std::endl;

int main() {
int a = 1;
int b = 2;
cout << a << " " << b << endl;
myswap(a, b);
cout << a << " " << b << endl;
}
