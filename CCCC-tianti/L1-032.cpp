#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    char c;
    scanf("%d %c%*c", &a, &c);
    string s;
    getline(cin, s);
    int j = 0;
    int k = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (n + j == a + k) {
            //printf("%d\n", i);
            putchar(s[i]);
        }
        if (n + j < a) {
            putchar(c);
            i--;
            j++;
        }
        if (a + k < n) {
            k++;
        }
    }
    //system("pause");
    return 0;
}