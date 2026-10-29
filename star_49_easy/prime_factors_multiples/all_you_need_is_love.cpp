#include <iostream>
#include <string>
using namespace std;

// Euclidean algorithm to find GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};

void solve(int caseNum) {
    string s1, s2;
    cin >> s1 >> s2;

    // Convert binary strings to decimal numbers
    // stoll (string to long long) handles up to 30 characters (max 2^30 - 1)
    long long num1 = stoll(s1, nullptr, 2);
    long long num2 = stoll(s2, nullptr, 2);

    long long g = gcd(num1, num2);

    // If GCD > 1, a valid multi-bit binary string L exists
    if (g > 1) {
        cout << "Pair #" << caseNum << ": All you need is love!\n";
    } else {
        cout << "Pair #" << caseNum << ": Love is not all you need!\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        solve(i);
    }

    return 0;
}

