#include <bits/stdc++.h>

using namespace std;

string s[25];

int ans = 999999;

void bfs(string x, int n)
{
    ans = max(ans, n);
}

int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }
    char t;
    cin >> t;
    for (int i = 0; i < a; i++) {
        if (s[i].at(0) == t) {
            bfs(s[i], s[i].length());
        }
    }
    return 0;
}