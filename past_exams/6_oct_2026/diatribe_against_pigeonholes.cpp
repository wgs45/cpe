#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Worker {
    char name;
    int count;
};

// Custom sorting: fewer parcels first, then alphabetical by name for ties
bool compareWorkers(const Worker& a, const Worker& b) {
    if (a.count != b.count)
        return a.count < b.count;
    return a.name < b.name;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    string s;
    cin >> s;

    vector<Worker> workers(N);
    for (int i = 0; i < N; ++i) {
        workers[i] = { (char)('A' + i), 0 };
    }

    // Count parcels
    for (char c : s) {
        if (c == '#') break;
        if (c >= 'A' && c < 'A' + N) {
            workers[c - 'A'].count++;
        }
    }

    // Sort based on rules
    sort(workers.begin(), workers.end(), compareWorkers);

    // Place into pigeonholes from center outward
    vector<char> pigeonholes(N);
    vector<int> counts(N);

    int mid = (N - 1) / 2;

    // Center gets the lightest
    pigeonholes[mid] = workers[0].name;
    counts[mid] = workers[0].count;

    int left = mid;
    int right = mid;

    // Alternate placing to right and left outward
    for (int i = 1; i < N; ++i) {
        if (i % 2 == 1) {
            // Place on the right side
            right++;
            pigeonholes[right] = workers[i].name;
            counts[right] = workers[i].count;
        } else {
            // Place on the left side
            left--;
            pigeonholes[left] = workers[i].name;
            counts[left] = workers[i].count;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << pigeonholes[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
    for (int i = 0; i < N; ++i) {
        cout << counts[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (cin >> M) {
        while (M--) {
            solve();
        }
    }
    return 0;
}

