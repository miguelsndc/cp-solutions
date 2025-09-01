#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool f(int d, vector<array<int, 2>> &coords, int n) {
    vector<int> g[n];

    for (int i = 0; i < n - 1; i++) {
        auto [x1, y1] = coords[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = coords[j];
            int dist = (x1 - x2) * (x1 - x2) + (y1-y2) * (y1-y2);
            if (dist <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    queue<int> q;
    q.push(0);
    vector<bool> visited(n);
    visited[0] = true;
    int vis = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        vis++;
        for (int neighbour: g[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return vis == n;
}

int main() 
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    vector<array<int, 2>> coords(n);

    for(int i = 0; i < n; i++) {
        cin >> coords[i][0] >> coords[i][1];
    }

    int maxd = -1;
    for (int i = 0; i < n - 1; i++) {
        auto [x1, y1] = coords[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = coords[j];
            int d = (x1 - x2) * (x1 - x2) + (y1-y2) * (y1-y2);
            maxd = max(maxd, d);
        }
    }

    int l = 0, r = maxd;

    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m, coords, n)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;
}   