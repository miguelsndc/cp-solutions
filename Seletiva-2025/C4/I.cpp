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
    vector<int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    sort(begin(trees), end(trees));
    int l = 0, r = k - 1;
    int mindiff = 1e9 + 1;
    while (r < n) {
        mindiff = min(trees[r] - trees[l], mindiff);
        l++, r++;
    }
    cout << mindiff;
}