#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    string newline; getline(cin, newline);
    while (t--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        int res = 0;
        int j = 0;
        for (auto ch: a) {
            if (ch == b[j]) {
                j = (j + 1) % b.size();
            } else {
                res += 1;
            }
        }

        cout << res + j << endl;
    }
    return 0;
}


