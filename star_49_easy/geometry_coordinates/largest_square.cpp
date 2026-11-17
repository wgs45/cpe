#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int m, n, q;

        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << "\n";

        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            cin >> grid[i];
        }

        while (q--) {
            int r, c;
            cin >> r >> c;

            char target = grid[r][c];
            int ans = 1; // Side length starts at 1 (radius 0)

            // Try expending radius d = 1, 2, 3
            for (int d = 1; ; d++) {
                // Check if the square at 1 (radius 0)
                if (r - d < 0 || r + d >= m || c - d < 0 || c + d >= n) {
                    break;
                }

                // Check if all characters in the square match target
                bool ok = true;
                for (int i = r - d; i <= r + d && ok; i++) {
                    for (int j = c - d; j <= c + d; j++) {
                        if (grid[i][j] != target) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) ans += 2; // Expand side length by 2 (1 on each side)
                else break;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}

