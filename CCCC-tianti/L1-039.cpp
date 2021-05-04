#include <bits/stdc++.h>

using namespace std;

char form[105][105] = { '\0' };

int main()
{
    int n;
    int l;
    scanf("%d%*c", &n);
    string s;
    getline(cin, s);
    int m = s.size();

    if (m % n == 0) {
        l = m / n;
    } else {
        l = m / n + 1;
    }
    for (int i = l - 1, k = 0; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (s[k] != '\0') {
                form[j][i] = s[k++];
            } else {
                form[j][i] = ' ';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            printf("%c", form[i][j]);
        }
        putchar('\n');
    }
    //system("pause");
    return 0;
}