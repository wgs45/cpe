#include <iostream>
using namespace std;

long long stepsFromOrigin(long long x, long long y) {
    long long s = x + y;
    return s * (s + 1) / 2 + x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int tc = 1; tc <= n; tc++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case " << tc << ": " << (stepsFromOrigin(x2, y2) - stepsFromOrigin(x1, y1)) << "\n";
    }

    return 0;
}

