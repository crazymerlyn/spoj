#include <bits/stdc++.h>

using namespace std;

long long get_min_steps(long long n) {
    if (n == 0) return 0;
    long long val = 1; while (val < n) val = val * 10 + 1;
    if (val == n) return 1;
    val /= 10;
    long long res = n / val + get_min_steps(n % val);

    long long alternate = val * 10 + 1 - n;
    if (alternate < n) res = min(res, 1 + get_min_steps(alternate));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << get_min_steps(n) - 1 << "\n";
    }
}

