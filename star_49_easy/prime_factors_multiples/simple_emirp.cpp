#include <iostream>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long reverseNum(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    while (cin >> n) {
        if (!isPrime(n)) {
            cout << n << " is not prime.\n";
        } else {
            long long rev = reverseNum(n);
            // Must be prime and different from the original number
            if (rev != n && isPrime(rev)) {
                cout << n << " is emirp.\n";
            } else {
                cout << n << " is prime.\n";
            }
        }
    }

    return 0;
}

