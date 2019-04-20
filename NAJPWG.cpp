#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        res -= res / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) res -= res / n;
    return res;
}

int main() {
    int limit = 1e5;
    vector<int> res(limit + 1);
    res[1] = 0;
    for (int i = 2; i <= limit; ++i) {
        res[i] = res[i-1] + i - phi(i);
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        cout << "Case " << i << ": " << res[n] << endl;
    }
    return 0;
}


