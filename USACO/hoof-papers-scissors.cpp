#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<char> moves(n);
    for (int i = 0; i < n; i++) cin >> moves[i];
    vector<int> h(n + 1), p(n + 1), s(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (moves[i] == 'H');
        s[i + 1] = s[i] + (moves[i] == 'P'); 
        h[i + 1] = h[i] + (moves[i] == 'S');
    }

    int max_wins = 0;
    for (int i = 1; i <= n; i++) {
        int pre = max(h[i], max(p[i], s[i]));
        int suf = max(h[n] - h[i], max(p[n] - p[i], s[n] - s[i]));
        max_wins = max(max_wins, pre + suf);
    }
    cout << max_wins;
}