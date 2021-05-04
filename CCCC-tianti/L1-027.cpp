#include <bits/stdc++.h>
using namespace std;

int a[15] = { 0 };
int b[15] = { 0 };

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        a[s[i] - '0']++;
    }
    printf("int[] arr = new int[]{");
    for (int i = 9, j = 0; i >= 0; i--) {
        if (a[i] != 0) {
            if (j != 0) {
                printf(",");
            }
            printf("%d", i);
            b[i] = j;
            j++;
        }
    }
    printf("};\nint[] index = new int[]{");
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(",");
        }
        printf("%d", b[s[i] - '0']);
    }
    printf("};\n");
    system("pause");
    return 0;
}