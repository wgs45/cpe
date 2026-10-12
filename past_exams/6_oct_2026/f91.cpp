#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result;
    while((cin >> n && n > 0)) {
        if (n <= 100) {
            result = 91;
        } else {
            result = n - 10;
        }
        cout << "f91(" << n << ")" << " = " << result << "\n";
    }

    return 0;
}

