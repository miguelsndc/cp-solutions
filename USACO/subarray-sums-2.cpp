#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> s(n); for(int i = 0; i < n; i++) cin >> s[i];

    map<ll, ll> mp; ll psum = 0, res = 0;
    for (int i = 0; i < n; i++) {
        psum += s[i];
        if (psum == k) res++; // trivial case
        if (mp.find(psum - k) != mp.end()) { 
            res += mp[psum - k]; // look for ocmplement in map
            // this means that there are mp[psum - k] subarrays with complementary sum
            // add them all to the count
        }
        mp[psum]++;
    }
    cout << res;
}