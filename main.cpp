#include <iostream>
#include <diamond/Diamond.h>

using namespace std;
using namespace diamond;

int main()
{
    cout << "Enter diamond depth: ";
    unsigned int depth;
    cin >> depth;
    cout << buildDiamond(depth) << endl;
    return 0;
}