#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, m;

    while (cin >> n >> m) {
        // Edge case: m must be >= 2, and n must be >= 1
        if (m < 2 || n < 1) {
            cout << "Boring!\n";
            continue;
        }

        vector<long long> seq;
        seq.push_back(n);

        bool is_valid = true;
        while (n > 1) {
            // Check if n is cleanly divisible by m
            if (n % m != 0) {
                is_valid = false;
                break;
            }
            n /= m;
            seq.push_back(n);
        }

        // If it didn't end cleanly at 1 or violated division rules
        if (!is_valid || n != 1) {
            cout << "Boring!\n";
        } else {
            for (size_t i = 0; i < seq.size(); ++i) {
                cout << seq[i] << (i + 1 == seq.size() ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

