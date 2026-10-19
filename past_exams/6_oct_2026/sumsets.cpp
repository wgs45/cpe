#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        // Sort the array
        sort(s.begin(), s.end());

        int ans = -1;
        bool found = false;

        // Loop d from largest to smallest to get the max d first
        for (int d = n - 1; d >= 0 && !found; d--) {
            for (int c = 0; c < n && !found; c++) {
                if (c == d) continue;

                // Two-pointer technique for a + b = d - c
                int a = 0, b = n - 1;
                while (a < b) {
                    if (a == c || a == d) { a++; continue; }
                    if (b == c || b == d) { b--; continue; }

                    long long sum = (long long) s[a] + s[b];
                    long long target = (long long) s[d] - s[c];

                    if (sum == target) {
                        ans = s[d];
                        found = true;
                        break;
                    } else if (sum < target) {
                        a++;
                    } else {
                        b--;
                    }
                }
            }
        }

        if (found) {
            cout << ans << "\n";
        } else {
            cout << "No solution\n";
        }
    }

    return 0;
}

