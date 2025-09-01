#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), amnt(n); 
    for (int &x: a) cin >> x;
    amnt[0]++;
    ll ps = 0, cnt = 0;
    for (int x: a) {
        ps = ((ps + x) % n + n) % n;
        cnt += amnt[ps];
        amnt[ps]++;
    }
    cout << cnt << endl;
}
