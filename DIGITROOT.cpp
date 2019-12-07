#include <bits/stdc++.h>

using namespace std;

int power(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    int base = 0, exp = 0;
    for (auto c: a) base += c - '0';
    base %= 9;
    if (base && (base % 3 == 0)) {
        if (b.length() == 1 && b[0] == '1') cout << base << endl;
        else cout << 9 << endl;
        return 0;
    }

    for (auto c: b) exp += c - '0';
    exp %= 3;

    if (exp % 2 != (b[b.length() - 1] - '0') % 2) {
        exp += 3;
    }
    if (!exp) exp = 6;

    int res = power(base, exp, 9);
    if (!res) res = 9;

    cout << res << endl;
}
