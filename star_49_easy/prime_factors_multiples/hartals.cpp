#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<int> hartals(p);
    for (int i = 0; i < p; i++) {
        cin >> hartals[i];
    }

    int lost_days_count = 0;

    // Check each day from 1 to N
    for (int day = 1; day <= n; day++) {
        // Skip weekends: Saturday (day % 7 == 0) and Friday (day % 7 == 6)
        int weekends = day % 7;
        if (weekends == 0 || weekends == 6) {
            continue;
        }

        // Check if any party has a hartal on this day
        bool is_hartal = false;
        for (int i = 0; i < p; i++) {
            if (day % hartals[i] == 0) {
                is_hartal = true;
                break; // Found one strike, no need to check other parties for this days
            }
        }

        if (is_hartal) {
            lost_days_count++;
        }
    }

    cout << lost_days_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

