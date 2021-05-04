#include <bits/stdc++.h>

using namespace std;

char s[105][105];

bool flag[105][105] = {0};

bool sd[105][105] = {0};

int n;

int del[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void panduan(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int t = 1;
        int nx = x + del[i][0];
        int ny = y + del[i][1];
        while (nx >= 0 && ny >= 0 && nx < n && ny < n && t != 7)
        {
            if (t == 1 && s[nx][ny] == 'i')
            {
                t++;
            }
            else if (t == 2 && s[nx][ny] == 'z')
            {
                t++;
            }
            else if (t == 3 && s[nx][ny] == 'h')
            {
                t++;
            }
            else if (t == 4 && s[nx][ny] == 'o')
            {
                t++;
            }
            else if (t == 5 && s[nx][ny] == 'n')
            {
                t++;
            }
            else if (t == 6 && s[nx][ny] == 'g')
            {
                t++;
            }
            else
            {
                break;
            }
            nx += del[i][0];
            ny += del[i][1];
        }
        nx -= del[i][0];
        ny -= del[i][1];
        if (t == 7)
        {
            while (t--)
            {
                flag[nx][ny] = 1;
                nx -= del[i][0];
                ny -= del[i][1];
            }
        }
    }
    return;
}

void DFS(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int xn = x + del[i][0];
        int yn = y + del[i][1];
        if (xn >= 0 && yn >= 0 && xn < n && yn < n && sd[xn][yn] == 0)
        {
            if (s[xn][yn] == 'y')
            {
                panduan(xn, yn);
            }
            sd[xn][yn] = 1;
            DFS(xn, yn);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    DFS(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (flag[i][j] == 1)
            {
                cout << s[i][j];
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}