#include <iostream>
#include <diamond/Diamond.h>

using namespace std;
using diamond::diamondCutter;

int main()
{
    cout << "Enter diamond depth: ";
    unsigned int depth;
    cin >> depth;
    cout << diamondCutter(depth) << endl;
    return 0;
}