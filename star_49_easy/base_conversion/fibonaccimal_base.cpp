#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Precalculate Fibonnaci numbers up to ~100,000,000
    // F[0] = 1, F[1] = 2, F[2] = 3, F[3] = 5...
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    while (true) {
        int next_fib = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next_fib > 100000000) break;
        fib.push_back(next_fib);
    }

    int n;
    if (cin >> n) {
        while (n--) {
            int num;
            cin >> num;
            cout << num << " = ";

            // 2. Find the largest Fibonnaci number <= num
            int start_idx = 0;
            for (int i = fib.size() - 1; i >= 0; i--) {
                if (fib[i] <= num) {
                    start_idx = i;
                    break;
                }
            }

            // 3. Greedy substraction loop
            int temp = num;
            for (int i = start_idx; i >= 0; i--) {
                if (temp >= fib[i]) {
                    cout << '1';
                    temp -= fib[i];
                } else {
                    cout << '0';
                }
            }
            cout << " (fib)\n";
        }
    }

    return 0;
}

