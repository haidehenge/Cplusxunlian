#include <bits/stdc++.h>

using namespace std;

int flag[5] = { 0 };

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G' || s[i] == 'g') {
            flag[0]++;
        }
        if (s[i] == 'P' || s[i] == 'p') {
            flag[1]++;
        }
        if (s[i] == 'L' || s[i] == 'l') {
            flag[2]++;
        }
        if (s[i] == 'T' || s[i] == 't') {
            flag[3]++;
        }
    }
    while (flag[0] != 0 || flag[1] != 0 || flag[2] != 0 || flag[3] != 0) {
        if (flag[0] != 0) {
            printf("G");
            flag[0]--;
        }
        if (flag[1] != 0) {
            printf("P");
            flag[1]--;
        }
        if (flag[2] != 0) {
            printf("L");
            flag[2]--;
        }
        if (flag[3] != 0) {
            printf("T");
            flag[3]--;
        }
    }
    system("pause");
    return 0;
}