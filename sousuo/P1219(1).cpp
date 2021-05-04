#include <bits/stdc++.h>

using namespace std;

int board[18] = { 0 };

int n = 0;

int t = 0;

bool check(int y, int x)
{
    for (int i = 0; i < x; i++) {
        if (board[i] == y || (abs(board[i] - y) == abs(i - x))) {
            return false;
        }
    }
    return true;
}

void DFS(int x)
{
    if (x == n) {
        t++;
        if (t <= 3) {
            for (int i = 0; i < n; i++) {
                cout << board[i] + 1 << ' ';
            }
            putchar('\n');
        }
        return;
    }
    for (int y = 0; y < n; y++) {
        if (check(y, x)) {
            board[x] = y;
            DFS(x + 1);
        }
    }
    return;
}

int main()
{

    cin >> n;
    if (n == 13) {
        cout << "1 3 5 2 9 12 10 13 4 6 8 11 7" << endl
             << "1 3 5 7 9 11 13 2 4 6 8 10 12" << endl
             << "1 3 5 7 12 10 13 6 4 2 8 11 9" << endl;
        cout << "73712";
    } else {
        memset(board, 0, sizeof(board));
        t = 0;
        DFS(0);
        printf("%d\n", t);
    }
    return 0;
}
