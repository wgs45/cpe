#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        // Edge case: if n = 1, nothing is discarded
        if (n == 1) {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
            break;
        }

        queue<int> deck;
        for (int i = 1; i <= n; i++) {
            deck.push(i);
        }

        vector<int> discarded;

        // Simulate until only 1 card remains
        while(deck.size() >= 2) {
            // Throw away the top card
            discarded.push_back(deck.front());
            deck.pop();

            // Move the new top card to the bottom
            int top_card = deck.front();
            deck.pop();
            deck.push(top_card);
        }

        cout << "Discarded cards: ";
        for (size_t i = 0; i < discarded.size(); i++) {
            if (i == 0) cout << " ";
            else cout << ", ";
            cout << discarded[i];
        }
        cout << "\n";

        cout << "Rrmaining card: " << deck.front() << "\n";
    }

    return 0;
}

