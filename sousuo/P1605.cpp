#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll OIU = 2e6 + 5;

int s[10][10] = {0};

int sum = 0;

int n, m, t;

int startx, starty, endx, endy;

int del[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            s[i][j] = 0;
        }
    }
    return;
}

void DFS(int x, int y)
{
    if (x == endx && y == endy)
    {
        sum++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + del[i][0];
        int ny = y + del[i][1];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && s[nx][ny] != 1)
        {
            s[nx][ny] = 1;
            DFS(nx, ny);
            s[nx][ny] = 0;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    cin >> n >> m >> t;
    int fx, fy;
    cin >> startx >> starty >> endx >> endy;
    s[startx][starty] = 1;
    while (t--)
    {
        cin >> fx >> fy;
        s[fx][fy] = 1;
    }
    DFS(startx, starty);
    cout << sum << endl;
    system("pause");
    return 0;
}
