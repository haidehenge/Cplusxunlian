#include <bits/stdc++.h>

using namespace std;

int s[405][405] = {0};

bool flag[405][405] = {0};

int del[][2] = {{-2, -1},
                {-2, 1},
                {-1, 2},
                {1, 2},
                {2, 1},
                {2, -1},
                {1, -2},
                {-1, -2}};

struct node
{
    int x;
    int y;
    int sum = 0;
};

int n, m, x, y;

void BFS(node start)
{
    queue<node> q;
    node next = start;
    flag[start.x][start.y] = 1;
    s[start.x][start.y] = start.sum;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            next.x = start.x + del[i][0];
            next.y = start.y + del[i][1];
            next.sum = start.sum;
            if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m && flag[next.x][next.y] == 0)
            {
                next.sum++;
                flag[next.x][next.y] = 1;
                s[next.x][next.y] = next.sum;
                q.push(next);
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> m >> x >> y;
    memset(flag, 0, sizeof(flag));
    memset(s, -1, sizeof(s));
    /*
    for (int i = 0; i < 405; i++)
    {
        memset(flag[i], 0, 405 * sizeof(bool));
        memset(s[i], -1, 405 * sizeof(int));
    }
    */
    node a;
    a.x = x;
    a.y = y;
    a.sum = 0;
    BFS(a);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%-5d", s[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}