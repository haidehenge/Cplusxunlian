#include <bits/stdc++.h>

using namespace std;

int finddd(string x)
{
    int m = 0;
    int n = x.size();
    for (int i = n - 1; i >= 0; i--) {
        if (x[i] == ' ') {
            m++;
        }
        if (m == 3) {
            return i;
        }
    }
    return 0;
}

string s[105];

int main()
{
    int a;
    scanf("%d%*c", &a);
    string::size_type idx, idy;
    for (int i = 0; i < a; i++) {
        getline(cin, s[i]);
        idx = s[i].find(",", 0);
        idy = s[i].find(".", 0);
        if (idx >= 3) {
            if (idx != string::npos && idy != string::npos) {
                if (s[i].at(idx - 1) == 'g' && s[i].at(idy - 1) == 'g' && s[i].at(idx - 2) == 'n'
                    && s[i].at(idy - 2) == 'n' && s[i].at(idx - 3) == 'o' && s[i].at(idy - 3) == 'o') {
                    int fad = finddd(s[i]);
                    int m = s[i].size();
                    for (int j = 0; j < m; j++) {
                        if (fad == j) {
                            cout << " qiao ben zhong." << endl;
                            break;
                        } else {
                            cout << s[i].at(j);
                        }
                    }
                } else {
                    cout << "Skipped" << endl;
                }
            }
        } else {
            cout << "Skipped" << endl;
        }
    }
    system("pause");
    return 0;
}