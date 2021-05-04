#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int d;
    cin >> d;
    long long int s = 0, x = 0;
    int n = 0;
    while (d > s) {
        s = s * 10 + 1;
        n++;
    }
    while (s % d != 0) {
        x = s / d;
        cout << x;
        s = (s - x * d) * 10 + 1;
        n++;
    }
    cout << s / d << ' ' << n << endl;
    system("pause");
    return 0;
}