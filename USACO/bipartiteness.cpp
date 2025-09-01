#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll black = 0, white = 0;
vector<int> tree[100005];

void dfs(int node, int parent, int color) {
    color ? black++ : white++;
    for (auto neighbour: tree[node]) {
        if (neighbour != parent) dfs(neighbour, node, 1 - color);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0, 0);

    cout << (black * white) - (n - 1);
}