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
        int n;
        priority_queue<int> lpq;
        priority_queue<int, vector<int>, greater<int>> rpq;
        while((cin >> n) && n) {
                if (n == -1) {
                cout << lpq.top() << '\n';
                lpq.pop();
            }
            else {
                if (lpq.empty() || n < lpq.top()) {
                    lpq.push(n);
                } else {
                    rpq.push(n);
                }
            }
            if (lpq.size() > rpq.size() + 1) {
                rpq.push(lpq.top());
                lpq.pop();
            }
            else if (rpq.size() > lpq.size()) {
                lpq.push(rpq.top());
                rpq.pop();
            }
    }
}
}