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
    vi y(n);
    loop(i, 0, n) cin >> y[i];
    stack<int> s;
    int maxsq = 1;
    y.push_back(0);
    for (int i = 0; i < y.size(); ++i) {
        while(s.size() && y[i] < y[s.top()]) {
            int height = y[s.top()];
            s.pop();
            int left = s.size() ? s.top() : -1;
            maxsq = max(maxsq, min(i - left - 1, height));
        }
        s.push(i);
    }
    cout << maxsq;
}