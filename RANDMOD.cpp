#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    int limit = 300000;
    vector<double> res(limit+1), ss(limit+1);
    res[1] = 1;
    ss[1] = 1;

    for (int n = 2; n <= limit; ++n) {
        res[n] = 1 + ss[n-1] / n;
        ss[n] = ss[n-1] + res[n];
    }

    while (t--) {
        int n; cin >> n;
        cout << setprecision(16) << res[n] << "\n";
    }
}

