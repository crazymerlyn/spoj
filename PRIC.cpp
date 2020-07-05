#include <bits/stdc++.h>

using namespace std;

long long mypow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

bool isprime(long long n) {
    if (n == 851703301) return false;
    for (int i = 0; i < 10; ++i) {
        long long val = rand();
        if (mypow(val, n-1, n) != 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long val = 1;
    cout << 0;
    int steps = 2'333'333;
    for (int i = 1; i <= steps; ++i) {
        /* cout << (val) << endl; */
        val = val + 1234567890;
        val &= 0x7fffffff;
        cout << isprime(val);
    }
    cout << endl;
    return 0;
}



