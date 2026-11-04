#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s && s != "0") {
        int sum = 0;

        // Compute the sum of digits from thr string
        for (char c : s) {
            sum += c - '0';
        }

        // Check if its a multiple of 9
        if (sum % 9 != 0) {
            cout << s << " us not a multiple of 9.\n";
        } else {
            // Calculate the 9-degrees recursively
            int degree = 1;
            while (sum != 9) {
                int temp = 0;
                while (sum > 0) {
                    temp += sum % 10;
                    sum /= 10;
                }
                sum = temp;
                degree++;
            }
            cout << s << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        }
    }

    return 0;
}

