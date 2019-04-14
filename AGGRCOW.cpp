#include <bits/stdc++.h>

using namespace std;

int valid(int diff, const vector<int>& s) {
    int n = s.size();
    int last = s[0];
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] - last < diff) continue;
        last = s[i];
        res += 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) cin >> s[i];

        sort(s.begin(), s.end());

        int lo = 1;
        int high = s[n-1] - s[0];

        while (high > lo) {
            int mid = lo + (high - lo + 1) / 2;
            if (valid(mid, s) >= c) lo = mid;
            else high = mid - 1;
        }
        cout << lo << endl;
    }
    return 0;
}
