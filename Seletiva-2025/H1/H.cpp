#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        ll cap, m; cin >> cap >> m; cap = cap * 100;
        queue<ll> lq, rq;
        loop(i, 0, m) {
            int length; cin >> length;
            string dir; cin >> dir;
            if (dir == "left") {
                lq.push(length);
            } else {
                rq.push(length);
            }
        }
        bool is_left = true;
        ll turns = 0;
        ll n = 0;
        while(!lq.empty() || !rq.empty()) {
            // enchendo a barca
            if (is_left) {
                while(!lq.empty() && (n + lq.front()) <= cap) {
                    n += lq.front(); lq.pop();
                }
                turns++; n = 0;
            } else {
                while(!rq.empty() && (n + rq.front()) <= cap) {
                    n += rq.front(); rq.pop();
                }
                turns++; n = 0;
            }
            is_left = !is_left;
        }
        cout << turns << '\n';
    }
}