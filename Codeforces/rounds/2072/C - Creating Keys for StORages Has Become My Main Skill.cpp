#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n, x; cin >> n >> x;
    if (x % 2 == 0) {
        for (int i = 0; i < n - 1; i++) {
            cout << 0 << ' ';
        }
        cout << x << '\n';
    } else {
        vector<int> s;
        if (n == 1) s.push_back(x);
        else s.push_back(0);

        int acc = 0;
        for (int i = 1; i < n; i++) {
            if ((i | x) == x) {
                s.push_back(i);
                acc |= i;
            }
        }

        if (acc != x) {
            if (s.size() == n) {
                s.pop_back();
            }
            s.push_back(x);
        }

        while(s.size() < n) {
            s.push_back(0);
        }
        for (int x: s) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}