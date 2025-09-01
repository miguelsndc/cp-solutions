#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    multiset<ll> seq;
    for (int i = 0; i < q; i++) {
        int qu, k;
        unsigned long long x;
        cin >> qu;
        if (qu == 1) {
            cin >> x;
            seq.insert(x);
        } else if (qu == 2) {
            cin >> x >> k;
            auto it = seq.upper_bound(x);
            int valid = true;
            for (int j = 1; j <= k; j++) {
                if (it == seq.begin()) {
                    valid = false;
                    break;
                }
                it--;
            }
            cout << ((valid) ? *it : -1) << '\n';

        } else {
            cin >> x >> k;
            auto it = seq.lower_bound(x);
            int valid = true;
            for (int j = 1; j < k; j++) {
                if (it == seq.end()) {
                    valid = false;
                    break;
                }
                it++;
            }
            cout << ((!valid || it == seq.end()) ? -1 : *it) << '\n';
        }
    }
    return 0;
}