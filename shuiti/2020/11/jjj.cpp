#include <bits/stdc++.h>

#define PI 3.141593

using namespace std;

typedef long long ll;

const ll OIU = 1e8 + 5;

ll vis[27] = {0};

int main()
{
    char s[105];
    ll t = 0;
    for (int i = 0; i < 4; i++)
    {
        fgets(s, 105, stdin);
        ll n = strlen(s);
        for (ll j = 0; j < n; j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
            {
                vis[s[j] - 'A']++;
                if (t < vis[s[j] - 'A'])
                {
                    t = vis[s[j] - 'A'];
                }
            }
        }
    }
    char a = 'A';
    for (ll i = t; i >= 0; i--)
    {
        for (ll j = 0; j < 26; j++)
        {
            if (j != 0)
            {
                printf(" ");
            }
            if (vis[j] >= i && i != 0)
            {
                printf("*");
            }
            else if (i != 0 && vis[j] < i)
            {
                printf(" ");
            }
            if (i == 0)
            {
                printf("%c", a);
                a = a + 1;
            }
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}
