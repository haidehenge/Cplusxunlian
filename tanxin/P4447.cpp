#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<int> a;
    int t;
    int cont;
    node(int f = 0)
        : t(f)
        , cont(f)
    {
    }
} group[100005];

bool cmp(struct node a, struct node b)
{
    return (a.cont) < (b.cont);
}

int main()
{
    int manx = 0xfffffff;
    int n, m[100005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    sort(m, m + n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            group[j].a.push_back(m[i]);
            group[j].cont++;
            j++;
        } else {
            int flag = 0;
            for (int k = j - 1; k >= 0; k--) { //倒序是从小到大 不用排序节约时间
                if (group[k].a[group[k].t] == (m[i] - 1)) {
                    group[k].a.push_back(m[i]);
                    group[k].t++;
                    group[k].cont++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                group[j].a.push_back(m[i]);
                group[j].cont++;
                j++;
            }
        }
    }
    for (int v = 0; v < j; v++) {
        manx = min(manx, group[v].cont);
    }
    printf("%d\n", manx);
    //system("pause");
    return 0;
}