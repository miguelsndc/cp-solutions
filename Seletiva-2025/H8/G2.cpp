#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int maxn = 4e5 + 5;
vector<ll> bit(maxn + 1);

void add(int pos, int val) {
	++pos; 
	while (pos <= maxn) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> num = v;
    vector<array<int , 3>> queries;
    for (int i = 0; i < q; i++) {
        char type; cin >> type;
        int a, b; cin >> a >> b;
        if (type == '!') num.push_back(b);
        queries.push_back({(type == '!'), a, b});
    }

    sort(begin(num), end(num));
    num.resize(unique(begin(num), end(num)) - begin(num));

    for (int x: v) {
        int idx = upper_bound(begin(num), end(num), x) - begin(num);
        add(idx, 1);
    }

    for (auto &[type, x, y]:queries) {
        x -= 1; // 0-based
        if (type == 1) {
            // mudar o valor da pos x pra y
            int posx = upper_bound(begin(num),end(num), v[x]) - begin(num);
            add(posx, -1);
            v[x] = y;
            int posy = upper_bound(begin(num),end(num), y) - begin(num);
            add(posy, 1);
        } else {
            int l = upper_bound(begin(num), end(num), x) - begin(num);
            int r = upper_bound(begin(num), end(num), y) - begin(num);
            cout << query(r) - query(l) << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}