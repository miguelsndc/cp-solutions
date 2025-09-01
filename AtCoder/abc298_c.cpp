#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
const int mxn = 2e5 + 10;
vector<multiset<int>> boxes(mxn);
vector<set<int>> cards(mxn);
void solve() {
    int N, Q; cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int x, y; cin >> x >> y;
            boxes[y].insert(x);
            cards[x].insert(y);
        }
        if (type == 2) {
            int x; cin >> x;
            for (int i: boxes[x]) {
                cout << i << ' ';
            }
            cout << '\n';
        }
        if (type == 3) {
            int x; cin >> x;
            for (int i: cards[x]) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}