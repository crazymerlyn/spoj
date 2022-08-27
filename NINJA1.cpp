#include <bits/stdc++.h>

using namespace std;

bool possib(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int prev = min(a[0], b[0]);
    for (int i = 1; i < n; ++i) {
        if (max(a[i], b[i]) < prev) return false;
        prev = min(a[i], b[i]) >= prev ? min(a[i], b[i]) : max(a[i], b[i]);
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        if (possib(a, b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


