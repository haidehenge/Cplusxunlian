#include <bits/stdc++.h>

using namespace std;

int sdet[35][35] = {0};

int del[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n;

struct node
{
    int x = 0;
    int y = 0;
};

void BFS(int x, int y)
{
    queue<node> q;
    node start;
    start.x = x;
    start.y = y;
    q.push(start);
    if (sdet[x][y] == 2)
    {
        sdet[x][y] = 0;
    }
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = start.x + del[i][0];
            int yy = start.y + del[i][1];
            if (xx >= 0 && xx <= n + 1 && yy >= 0 && yy <= n + 1)
            {
                if (sdet[xx][yy] == 2)
                {
                    sdet[xx][yy] = 0;
                    node next;
                    next.x = xx;
                    next.y = yy;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    n = a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            scanf("%d", &sdet[i][j]);
            if (sdet[i][j] == 0)
            {
                sdet[i][j] = 2;
            }
        }
    }
    for (int i = 0; i <= n + 1; i++)
    {
        sdet[0][i] = 2;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        sdet[i][n + 1] = 2;
    }
    for (int i = n + 1; i >= 0; i--)
    {
        sdet[n + 1][i] = 2;
    }
    for (int i = n + 1; i >= 0; i--)
    {
        sdet[i][0] = 2;
    }
    BFS(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != 1)
            {
                printf(" ");
            }
            printf("%d", sdet[i][j]);
        }
        putchar('\n');
    }
    //system("pause");
    return 0;
}