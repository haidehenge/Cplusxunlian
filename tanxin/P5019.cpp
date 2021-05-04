#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    int a;
    long long int sum = 0;
    int s[100005];

    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> s[i];
        if (i != 0) {
            if (s[i - 1] > s[i]) {
                sum += abs(s[i] - s[i - 1]);
            }
        }
    }
    sum += s[a - 1];
    cout << sum << endl;
    return 0;
}