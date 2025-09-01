#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin>>n;
        set<int> s;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                s.insert(i);
                n /= i;
                break;
            }
        }
        for (int i = 2; i * i <= n; i++) {
            if (!s.count(i) && n % i == 0) {
                s.insert(i);
                n /= i;
                break;
            }
        }
        if (s.size() < 2 || s.count(n) || n == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            s.insert(n);
            for (int x: s) {
                cout << x << ' ';
            }
            cout << "\n";
        }
    }
}