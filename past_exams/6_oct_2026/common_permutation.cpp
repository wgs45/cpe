#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        vector<int> count_a(26, 0);
        vector<int> count_b(26, 0);

        // Count characters in string a
        for (char c : a) {
            if (c >= 'a' && c <= 'z') {
                count_a[c - 'a']++;
            }
        }

        // Count characters in string b
        for (char c : b) {
            if (c >= 'a' && c <= 'z') {
                count_b[c - 'a']++;
            }
        }

        // Build and print the result alphabetically
        string result = "";
        for (int i = 0; i <= 26; i++) {
            int common_count = min(count_a[i], count_b[i]);
            // Append the character common_count times
            result.append(common_count, (char)('a' + i));
        }
        cout << result << "\n";
    }

    return 0;
}

