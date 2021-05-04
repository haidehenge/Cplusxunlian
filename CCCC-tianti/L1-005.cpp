#include <bits/stdc++.h>

using namespace std;

struct stud {
    unsigned long long int a;
    int k;
} student[1005];

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int j, v;
    unsigned long long int m;
    for (int i = 0; i < n; i++) {
        scanf("%lld %d %d", &m, &v, &j);
        student[v].a = m;
        student[v].k = j;
    }
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        printf("%lld %d\n", student[x].a, student[x].k);
    }
    //system("pause");
    return 0;
}