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
    ll n; cin >> n;
    vector<ll> A(n); loop(i, 0, n) cin >> A[i];
    ll local_max = 0;
    ll global_max = INT_MIN;
    loop(i, 0, n)
    {
        local_max = max(A[i], A[i] + local_max);
        global_max = max(global_max, local_max);
    }
    cout << global_max;
}