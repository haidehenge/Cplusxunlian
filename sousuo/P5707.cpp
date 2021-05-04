#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    int c = ceil(a / b) + 10;
    int house = c / 60;
    c = c % 60;
    int time = (32 - house) % 24;
    if (c != 0)
    {
        time -= 1;
    }
    printf("%02d:%02d\n", time, 60 - c);
    system("pause");
    return 0;
}