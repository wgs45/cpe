#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Turtle {
    int weight, strength;
};

// Custom sort: sort by strength ascending
// If strengths are equal, sort by weight ascending
bool compareTurtles (const Turtle& a, const Turtle& b) {
    if (a.strength != b.strength) {
        return a. strength < b.strength;
    }
    return a.weight < b.weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Turtle> turtles;
    int w, s;
    while (cin >> w >> s) {
        turtles.push_back({w, s});
    }

    int n = turtles.size();
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Sort by strength
    sort(turtles.begin(), turtles.end(), compareTurtles);

    // DP Table
    // dp[i] represents the min weight required to form a stack of i turtles
    // Initalize with infinity (large number like 2 billions)
    const long long INF = 2e18;
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    int max_turtles {0};

    // Process each turtle
    for (int i = 0; i < n; i++) {
        int weight = turtles[i].weight;
        int strength = turtles[i].strength;

        // Iterate backwards to ensure each turtle is used at most once per stack size
        for (int j = max_turtles + 1; j >= 1; j--) {
            // If we can form a stack of j - 1 turtles, and adding this turtle
            // doesn't exceed its strength, update dp[j]
            if (dp[j - 1] + weight <= strength) {
                if (dp[j - 1] + weight < dp[j]) {
                    dp[j] = dp[j - 1] + weight;
                    if (j > max_turtles) {
                        max_turtles = j;
                    }
                }
            }
        }
    }

    cout << max_turtles << "\n";

    return 0;
}
