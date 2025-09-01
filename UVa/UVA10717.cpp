#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    while (cin >> n >> t) {
        if (n == 0 && t == 0) {
            break;
        }
        vi coins(n);
        for (int i = 0; i < n; i++) cin >> coins[i];
        for (int i = 0; i < t; i++) {
            int v;
            cin >> v;
            int ans_max = INT_MIN, ans_min = INT_MAX;
            for (int i1 = 0; i1 < n; i1++) {
                for (int i2 = i1 + 1; i2 < n; i2++) {
                    for (int i3 = i2 + 1; i3 < n; i3++) {
                        for (int i4 = i3 + 1; i4 < n; i4++) {
                            int lcm_v = lcm(coins[i1], coins[i2]);
                            lcm_v = lcm(lcm_v, coins[i3]);
                            lcm_v = lcm(lcm_v, coins[i4]);
                            int x = (v / lcm_v) * lcm_v;
                            int y = x;
                            if (y < v)
                                y += lcm_v;
                            ans_max = max(ans_max, x);
                            ans_min = min(ans_min, y);
                        }
                    }
                }
            }
            cout << ans_max << ' ' << ans_min << '\n';
        }
    }
    return 0;
}