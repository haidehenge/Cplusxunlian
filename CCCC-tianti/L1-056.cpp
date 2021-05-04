#include <bits/stdc++.h>

using namespace std;

struct shu {
    string s;
    int d;
} df[10005];

int MAX = 999999;

int main()
{
    int a;
    string flag;
    ios::sync_with_stdio(false);
    cin >> a;
    double sum = 0;
    for (int i = 0; i < a; i++) {
        cin >> df[i].s >> df[i].d;
        sum += 1.0 * df[i].d;
    }
    int loc = sum / (1.0 * a) * 0.5;
    for (int i = 0; i < a; i++) {
        if (abs(loc - df[i].d) < MAX) {
            MAX = abs(loc - df[i].d);
            flag = df[i].s;
        }
    }
    cout << loc << ' ' << flag << endl;
    system("pause");
    return 0;
}