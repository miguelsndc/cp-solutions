#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>
#define MOD 1000000007

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum;
    cin >> sum;
    vector<ll> count(sum + 1);
    count[0] = 1;
    for (int a = 1; a <= sum; a++) {
        for (auto c : {1, 2, 3, 4, 5, 6}) {
            if(a - c >= 0) {
                count[a] += count[a-c];
                count[a] %= MOD;
            } else {
                break;
            }
        }
    }
    cout << count[sum];
}