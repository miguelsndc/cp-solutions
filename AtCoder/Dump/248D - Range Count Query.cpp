#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, l, r, x, q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<vi> id(n + 1);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        id[t].push_back(i);
        // id[t] contains the indexes where t shows up
        // how many indexes of id[t] are between l and r ? that's the answer.
    }
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        cout << lower_bound(id[x].begin(), id[x].end(), r) - lower_bound(id[x].begin(), id[x].end(), l - 1) << '\n';
    }

    return 0;
}
