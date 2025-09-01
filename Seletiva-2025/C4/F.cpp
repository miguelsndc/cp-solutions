#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        sum += x;
        pq.push(x);
        while(sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size();
}