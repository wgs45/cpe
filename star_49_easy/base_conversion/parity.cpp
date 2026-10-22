#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    while (cin >> i && i != 0) {
        // Convert number to its binary representation string
        int temp = i;
        string binary_str = "";
        while (temp > 0) {
            binary_str = to_string(temp % 2) + binary_str;
            temp /= 2;
        }

        // Gee total number of 1s
        int p = __builtin_popcount(i);

        cout << "The parity of " << binary_str << " is " << p << " (mod 2).\n";
    }

    return 0;
}

