#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> sl(n + 1);
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        sl[--a]++;
        sl[--b + 1]--;
    }

    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + sl[i];
    } 
    ps[0] = -1;
    sort(begin(ps), end(ps));
    cout << ps[(n + 1 / 2)]; 
}