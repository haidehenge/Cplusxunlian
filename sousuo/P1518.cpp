#include <bits/stdc++.h>

using namespace std;

const long long int OIU = 2e6 + 5;

char grid[15][15] = {'\0'};

int del[4][2] = {{-1, 0},
                 {0, 1},
                 {1, 0},
                 {0, -1}};

bool flag[OIU] = {false};

int main()
{
    int t = 0;
    int xf = 0, yf = 0;
    int xn = 0, yn = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'F')
            {
                xf = i;
                yf = j;
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'C')
            {
                xn = i;
                yn = j;
                grid[i][j] = '.';
            }
        }
    }
    int ff = 0, ft = 0;
    while (xf != xn || yf != yn)
    {
        if (xf < 10 && xf >= 0 && yf >= 0 && yf < 10 && grid[xf][yf] != '*')
        {
            xf += del[ff % 4][0];
            yf += del[ff % 4][1];
        }
        if (xf >= 10 || xf < 0 || yf < 0 || yf >= 10 || grid[xf][yf] == '*')
        {
            xf -= del[ff % 4][0];
            yf -= del[ff % 4][1];
            ff++;
        }
        if (yn < 10 && yn >= 0 && xn >= 0 && xn < 10 && grid[xn][yn] != '*')
        {
            xn += del[ft % 4][0];
            yn += del[ft % 4][1];
        }
        if (yn >= 10 || yn < 0 || xn >= 10 || xn < 0 || grid[xn][yn] == '*')
        {
            xn -= del[ft % 4][0];
            yn -= del[ft % 4][1];
            ft++;
        }
        long long sec = xf + yf * 10 + xn * 100 + yn * 1000 + (ff % 4) * 10000 + (ft % 4) * 40000;
        if (flag[sec] == false)
        {
            flag[sec] = true;
        }
        else
        {
            t = 0;
            break;
        }
        t++;
    }
    cout << t << endl;
    //system("pause");
    return 0;
}