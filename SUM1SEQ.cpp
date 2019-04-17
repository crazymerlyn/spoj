#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int s; cin >> s;
        /* cout << n << " " << s << endl; */

        int m = n * (n - 1) / 2;

        if (abs(s) > m || (s + m) % 2 != 0) {
            cout << "No" << endl;
            if (t) cout << endl;
            continue;
        }

        int val = 0;
        int todiff = (m - s) / 2;
        for (int i = 0; i < n; ++i) {
            cout << val << endl;
            if (todiff > (n - i - 1) * (n - i - 2) / 2) {
                todiff -= n - i - 1;
                val -= 1;
            } else val += 1;
        }
        if (t) cout << endl;
    }
    return 0;
}


