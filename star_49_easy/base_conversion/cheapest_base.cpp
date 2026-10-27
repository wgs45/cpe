#include <iostream>
#include <vector>

using namespace std;

void solve(int caseNum) {
    int cost[36];
    for (int i = 0; i < 36; i++) {
        cin >> cost[i];
    }

    int q;
    cin >> q;

    // Print a blank line between cases
    if (caseNum > 1) cout << "\n";
    cout << "Case " << caseNum << ":" << endl;

    while (q--) {
        long long num;
        cin >> num;

        vector<int> cheapestBases;
        long long minCost = -1;

        for (int base = 2; base <= 36; base++) {
            long long currentCost = 0;
            long long temp = num;

            if (temp == 0) {
                currentCost = cost[0];
            } else {
                while (temp > 0) {
                    int digit = temp % base;
                    currentCost += cost[digit];
                    temp /= base;
                }
            }

            if (minCost == -1 || currentCost < minCost) {
                minCost = currentCost;
                cheapestBases.clear();
                cheapestBases.push_back(base);
            } else if (currentCost == minCost) {
                cheapestBases.push_back(base);
            }
        }

        cout << "Cheapest base(s) for number " << num << " :";
        for (size_t i = 0; i < cheapestBases.size(); i++) {
            cout << " " << cheapestBases[i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }
    return 0;
}

