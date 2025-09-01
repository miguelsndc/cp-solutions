#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

// each spot in a wrong position must be connected to its original position via edges of with at least w
int n, m; 
int main() 
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        perm[i] = --a;
    }

    vector<array<int, 2>> g[n];
    int maxw = -1;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[--a].push_back({--b, w});
        g[b].push_back({a, w});
        maxw = max(w, maxw);
    }

    int l = 0, r = maxw + 1, valid = -1;

    while(l <= r) {
        int m = l + (r - l) / 2;

        int curr = 0;
        vector<int> component(n, -1);
        for (int i = 0; i < n; i++) {
            if (component[i] != -1) continue;
            vector<int> q{i};
            component[i] = curr;
            while(!q.empty()) {
                int front = q.back();
				q.pop_back();
				component[front] = curr;
				for (const auto &[n, w] : g[front]) {
					if (component[n] == -1 && w >= m) { q.push_back(n); }
				}
            }
            curr++;
        }
        bool can_sort = true;
        for (int i = 0; i < n; i++) {
            if (component[i] != component[perm[i]]) {
                can_sort = false;
                break;
        }

        if (can_sort) {
            valid = m;
            l = m + 1;
        } else {
            r = m - 1;
        }

    }
    cout << ((valid == maxw + 1) ? -1 : valid);
}