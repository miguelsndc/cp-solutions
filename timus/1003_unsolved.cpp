#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    while((cin >> t) && t != -1) {
        int n; cin >> n;
        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; i++) {
            int x1, y1; string p;
            cin >> x1 >> y1 >> p;
            v[i] = {x1, y1, (p == "odd")};
        }

        int val = 0, found = false, c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((max(v[i][0], v[j][0]) <= min(v[i][1], v[j][1])) && v[i][2] != v[j][2]) {
                    val = i;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        cout << val << '\n';
    }
}