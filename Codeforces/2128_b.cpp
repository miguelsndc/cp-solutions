#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        deque<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        string ans = "";
        bool big = true;
        while(!p.empty()) {
            if (big) {
                if (p.front() > p.back()) {
                    p.pop_front();
                    ans += "L";
                } else {
                    p.pop_back();
                    ans += "R";
                }
            } else {
                if (p.front() < p.back()) {
                    p.pop_front();
                    ans += "L";
                } else {
                    p.pop_back();
                    ans += "R";
                }
            }

            big ^= 1;
        }

        cout << ans << '\n';
    }
}
