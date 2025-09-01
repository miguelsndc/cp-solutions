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
    int n; cin >> n;

    if (n == 1) {
        int x; cin >> x;
        cout << x;
        return 0;
    }

    vi a(n), b(n);
    loop(i, 0, n) cin >> a[i];
    loop(i, 0, n - 1) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int j = 0, c = 0, minbox = b[0];
    loop(i, 0, n) {
        while(j < n && a[j] > b[i]) {
            minbox = a[j];
            c++; j++;
        }
        j++;
    }
    if(c > 1) {
        cout << -1;
    } else {
        cout << minbox;
    }
}