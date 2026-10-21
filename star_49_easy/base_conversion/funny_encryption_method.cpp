#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        while (n--) {
            int m;
            cin >> m;

            // b1: Number of 1s in decimal value binary representation
            int b1 = __builtin_popcount(m);

            // b2: interpret digits of m as hexadecimal
            int temp = m, hex_val = 0, base = 1;
            while (temp > 0) {
                hex_val += (temp % 10) * base;
                base *= 16;
                temp /= 10;
            }

            int b2 = __builtin_popcount(hex_val);

            cout << b1 << " " << b2 << "\n";
        }
    }

    return 0;
}

