#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6, c = 7;
    b = a; c = b; a = c;
    cout<<a<<"\n"<<b<<"\n"<<c;
    return 0;
}