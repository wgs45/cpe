#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to map char to its numeric value
int getVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    return 0; // For signs or invalid chars
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s) {
        long long sum = 0;
        int max_val = 1; // Minimum digit max implies base to least 2

        for (char c : s) {
            int val = getVal(c);
            sum += val;
            max_val = max(max_val, val);
        }

        int start_base = max_val + 1;
        bool found = false;

        for (int n = start_base; n <= 62; n++) {
            if (sum % (n - 1) == 0) {
                cout << n << "\n";
                found = true;
                break; // Smallest base found, stop early!
            }
        }

        if (!found) {
            cout << "such number is impossible!\n";
        }
    }

    return 0;
}

