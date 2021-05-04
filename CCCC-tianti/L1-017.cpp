#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    double a = 1;
    int b = 0;
    int sum = 0;
    if (s[0] == '-') {
        a *= 1.5;
        b = -1;
    }
    int n = s.size();
    if ((s[n - 1] - '0') % 2 == 0) {
        a *= 2;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            sum++;
        }
    }
    a *= (1.0 * sum / (1.0 * (n + b)));
    printf("%.2lf%\n", a * 100);
    //system("pause");
    return 0;
}