#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void answer(int x) {
    cout << "YES\n";
    cout << x << '\n';
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = (int)(s[i] - '0');
        if (x % 8 == 0) {
            answer(x);
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = (int)(s[i] - '0');
            int y = (int)(s[j] - '0');
            int num = x * 10 + y;
            if (num % 8 == 0) {
                answer(num);
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int x = (int)(s[i] - '0');
                int y = (int)(s[j] - '0');
                int z = (int)(s[k] - '0');
                int num = x * 100 + y * 10 + z;
                if (num % 8 == 0) {
                    answer(num);
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;  // cin >> T;
    while (T--) solve();
}