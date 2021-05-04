#include <iostream>
using namespace std;

void mult(int num)
{
    int i, j;
    for (i = 1; i <= num; ++i) {
        for (j = i; j <= num; ++j) {
            cout << i << " * " << j << " = " << i * j << "\t";
        }
        cout << endl;
    }
}

int main(void)
{
    int num = 9;
    mult(num);
    return 0;
}