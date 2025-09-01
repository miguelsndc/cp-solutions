#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void solve() {
    int Q; cin >> Q;
    int i = 0;
    vector<int> curr;
    multiset<int> ms;
    multiset<int>::iterator it = ms.begin();
    while(Q--) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            curr.push_back(x);
        }
        if (type == 2) {
            if (it == ms.end()) {
                cout << curr[i++] << '\n';
            } else {
                cout << (*it) << '\n' ;
                auto new_it = it;
                ++it;
                ms.erase(new_it);
            }
        }
        if (type == 3) {
            for (;i < curr.size(); i++) {
                ms.insert(curr[i]);
            }
            it = ms.begin();
        }
    }
}
int main() {
    int T = 1; // cin >> T;
    while(T--) solve();
}