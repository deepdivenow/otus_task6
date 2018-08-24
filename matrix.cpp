
#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix<int,-1> m;
    m[1][2]=5;
    m[1][3]=6;
    m[1][4]=7;
    m[1][5]=8;

    for(auto c: m)
    {
      cout << c.second << endl;
    }
    return 0;
}