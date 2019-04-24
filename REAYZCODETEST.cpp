#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ti = 1; ti <= t; ++ti) {
        int n, x; cin >> n >> x;
        vector<int> vs(n);
        for (int i = 0; i < n; ++i) cin >> vs[i];
        map<int, int> c;
        long long res = 0;
        for (auto val: vs) {
            res += c[val - x];
            res += c[val + x];
            c[val] += 1;
        }
        cout << "Case " << ti << ": " << res << endl;
    }
    return 0;
}


