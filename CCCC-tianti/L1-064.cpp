#include <bits/stdc++.h>

using namespace std;

string q[15];

string shanchukongge(string a)
{
    string b = "\0";
    int n = a.size();
    bool flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == ' ') {
            flag = 0;
            continue;
        } else {
            if (flag == 0 && b.size() > 1 && a[i] != '?') {
                b += ' ';
            }
            if (a[i] == '?') {
                b += '!';
                continue;
            }
            b += a[i];
            flag = 1;
        }
    }
    return b;
}

string bB(string a)
{
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a.at(i) >= 'A' && a.at(i) <= 'Z' && a.at(i) != 'I') {
            a[i] = a[i] + 32;
        }
    }
    return a;
}

string canyou(string a)
{
    string b = "\0";
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 'c' && a[i + 1] == 'a' && a[i + 2] == 'n' && a[i + 3] == ' '
            && a[i + 4] == 'y' && a[i + 5] == 'o' && a[i + 6] == 'u') {
            b += "I can";
            i += 6;
            continue;
        }
        if (a[i] == 'c' && a[i + 1] == 'o' && a[i + 2] == 'u' && a[i + 3] == 'l'
            && a[i + 4] == 'd' && a[i + 5] == ' ' && a[i + 6] == 'y' && a[i + 7] == 'o'
            && a[i + 8] == 'u') {
            b += "I could";
            i += 8;
            continue;
        }
        b += a[i];
    }
    return b;
}

int flag[1005] = { 0 };

string me(string a)
{
    string b = "\0";
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 'I') {
            b += "you";
            continue;
        }
        if (a[i] == 'm' && a[i + 1] == 'e') {
            b += "you";
            i += 1;
            continue;
        }
        b += a[i];
    }
    return b;
}

int main()
{
    int a;
    scanf("%d%*c", &a);
    string s[15];
    for (int i = 0; i < a; i++) {
        getline(cin, s[i]);
        q[i] = me(s[i]);
        q[i] = shanchukongge(q[i]);
        //cout << q[i] << endl;
        q[i] = bB(q[i]);
        q[i] = canyou(q[i]);
        //int n = q[i].size();
        cout << q[i] << endl;
    }
    system("pause");
    return 0;
}
