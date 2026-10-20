#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

const int inf = 1e9; // Infinite

struct Edge {
    int to, weight;
};

void solve(int mapNum) {
    int nStation;
    if (!(cin >> nStation)) return;

    map<string, int> stationNameToId;
    vector<string> stationIdToName(nStation);
    vector<int> stationCost(nStation);

    for (int i = 0; i < nStation; i++) {
        cin >> stationIdToName[i] >> stationCost[i];
        stationNameToId[stationIdToName[i]] = i;
    }

    int nPath;
    cin >> nPath;
    vector<vector<Edge>> adj(nStation);
    for (int i = 0; i < nPath; i++) {
        string u_name, v_name;
        int dist;
        cin >> u_name >> v_name >> dist;
        int u = stationNameToId[u_name];
        int v = stationNameToId[v_name];
        int cost = dist * 2; // 2 taka per km of oil
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    int nQuery;
    cin >> nQuery;

    cout << "Map #" << mapNum << "\n";
    for (int q = 1; q <= nQuery; q++) {
        string start_name, end_name;
        int passengers;
        cin >> start_name >> end_name >> passengers;

        int start = stationNameToId[start_name];
        int end = stationNameToId[end_name];

        // Djikstra algorithm
        vector<int> dist(nStation, inf);
        vector<int> parent(nStation, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = stationCost[start]; // Include starting station fee
        pq.push({dist[start], start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == end) break;

            for (auto& edge : adj[u]) {
                int v = edge.to;
                // Total cost to reach v = cost to u + edge oil cost + destination station fee
                int next_dist = dist[u] + edge.weight + stationCost[v];

                if (next_dist < dist[v]) {
                    dist[v] = next_dist;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // Reconstruct path
        vector<string> path;
        for (int curr = end; curr != -1; curr = parent[curr]) {
            path.push_back(stationIdToName[curr]);
        }
        reverse(path.begin(), path.end());

        cout << "Query #" << q << "\n";

        // Print path
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i + 1 == path.size() ? "" : " ");
        }
        cout << "\n";

        // Calculate final passengers fare: Total cost + 1.10 / passengers
        double total_cost = dist[end];
        double fare = (total_cost * 1.10) / passengers;

        cout << fixed << setprecision(2);
        cout << "Each passengers has to pay: " << fare << " taka\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(i);
            cout << "\n";
        }
    }

    return 0;
}

