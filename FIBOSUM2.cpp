#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

long long mypow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

struct Mat {
    long long a, b, c, d;
};
Mat I{1,0,0,1};
Mat F{1,1,1,0};

ostream & operator << (ostream &out, const Mat &x) {
    return out << x.a << " " << x.b << "\n" << x.c << " " << x.d << "\n";
}

Mat normalized(Mat x) {
    return {x.a%mod, x.b%mod, x.c%mod, x.d%mod};
}

Mat operator*(Mat x, long long b) {
    return {x.a*b%mod, x.b*b%mod, x.c*b%mod, x.d*b%mod};
}

Mat operator/(Mat a, long long b) {
    return a * mypow(b, mod-2,mod);
}

Mat operator*(Mat x, Mat y) {
    Mat res;
    res.a = x.a * y.a + x.b * y.c;
    res.b = x.a * y.b + x.b * y.d;
    res.c = x.c * y.a + x.d * y.c;
    res.d = x.c * y.b + x.d * y.d;

    return normalized(res);
}

inline long long deter(Mat x) {
    return (x.a * x.d - x.b * x.c+ mod) % mod;
}

Mat mat_inv(Mat x) {
    Mat res{x.d, mod-x.b, mod-x.c, x.a};
    return res / deter(x);
}

Mat operator/(Mat a, Mat b) {
    return a * mat_inv(b);
}

Mat operator^(Mat a, long long b) {
    Mat res = I;
    while (b) {
        if (b % 2) res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

Mat operator+(Mat x, Mat y) {
    Mat res{x.a+y.a, x.b+y.b, x.c+y.c, x.d+y.d};
    return normalized(res);
}

Mat operator-(Mat x, Mat y) {
    Mat res{x.a-y.a+mod, x.b-y.b+mod, x.c-y.c+mod, x.d-y.d+mod};
    return normalized(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        long long c, k, n; cin >> c >> k >> n;
        Mat res = (F ^ (c + k)) * ((((F ^ k) ^ n) - I) / ((F ^ k) - I));
        cout << (res.b % mod + mod) % mod << "\n";
    }
}


