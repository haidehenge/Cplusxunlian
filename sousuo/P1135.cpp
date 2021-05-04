#include <bits/stdc++.h>

using namespace std;

int sfa[205];

int a, b, c;

struct node {
    int ans = 0;
    int x;
};

queue<node> f;

void bfs()
{
    node start;
    start.x = b;
    start.ans = 0;
    f.push(start);
    while (!f.empty()) {
        node start = f.front();
        f.pop();
        if (start.x == c) {
            printf("%d\n", start.ans);
            system("pause");
            return;
        }
        node next;
        if (start.x + sfa[start.x] <= a) {
            next.x = start.x + sfa[start.x];
            next.ans = start.ans + 1;
            f.push(next);
        }
        if (start.x - sfa[start.x] > 0) {
            next.x = start.x - sfa[start.x];
            next.ans = start.ans + 1;
            f.push(next);
        }
    }
}

int main()
{

    scanf("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= a; i++) {
        scanf("%d", &sfa[i]);
    }
    bfs();
    return 0;
}