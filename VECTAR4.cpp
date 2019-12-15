#include <bits/stdc++.h>

using namespace std;

void fastscan(long long &number) 
{ 
	register int c; 

	number = 0; 

	// extract current character from buffer 
	c = getchar(); 

	// Keep on extracting characters if they are integers 
	// i.e ASCII Value lies from '0'(48) to '9' (57) 
	for (; (c>47 && c<58); c=getchar()) 
		number = number *10 + c - 48; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t; fastscan(t);
    while (t--) {
        long long n; fastscan(n);
        long long root = sqrt(n);
        if (root * (root + 1) < n) cout << 2 * root + 1 << "\n";
        else if (root * root < n) cout << 2 * root << "\n";
        else cout << 2 * root - 1 << "\n";
    }
}
