#include <iostream>
#include <numeric> // For std::gcd

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read N until N is 0
    while (cin >> N && N != 0) {
        int G = 0;

        // Compute the sum of GCDs for all pairs (i, j)
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += std::gcd(i, j);
            }
        }

        cout << G << "\n";
    }

    return 0;
}

