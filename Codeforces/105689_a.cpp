#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    if (s == "0") {
        cout << "New moon";
    } else if (s == "100") {
        cout << "Full moon";
    } else {
        int is_two = (s.size() == 3);
        int num = (int)(s[0] - '0') * (is_two ? 10: 1) + (is_two ? (int)(s[1] - '0'): 0);
        char dir = s.back();
        if (dir == 'R') {
            if (num >= 1 and num <= 49) {
                cout << "Waxing crescent";
            } else if (num == 50) {
                cout << "First quarter";
            } else if (num >= 51 and num <= 99) {
                cout << "Waxing gibbous";
            }
        } else {
            if (num >= 1 and num <= 49) {
                cout << "Waning crescent";
            } else if (num == 50) {
                cout << "Third quarter";
            } else if (num >= 51 and num <= 99) {
                cout << "Waning gibbous";
            }
        }
    }
}
