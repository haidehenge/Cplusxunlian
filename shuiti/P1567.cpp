#include <bits/stdc++.h>

using namespace std;

long long int s[1000005];

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int t = 0;
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (i != 0)
        {
            if (s[i] > s[i - 1])
            {
                f++;
            }
            else
            {
                if (f > t)
                {
                    t = f;
                }
                f = 1;
            }
        }
    }
    if (f > t)
    {
        t = f;
    }
    cout << t << endl;
    return 0;
}