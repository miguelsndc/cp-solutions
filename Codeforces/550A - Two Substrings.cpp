#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;cin>>s;
    int n = s.size();
    // look for  first ab then any ba
    // look for first ba then any ab  if necessary
    
    bool ab = false, ba = false;
    for (int i = 1; i < n; i++) {
        if (!ab && s[i - 1] == 'A' && s[i] == 'B') {
            ab = true;
            i++;
        } else if (ab && s[i - 1] == 'B' && s[i] == 'A') {
            ba = true;
        }
    }
    if (ab && ba) {cout << "YES"; return 0;}
    ab = ba = false;
    for (int i = 1; i < n; i++) {
        if (!ba && s[i - 1] == 'B' && s[i] == 'A') {
            ba = true;
            i++;
        } else if (ba && s[i - 1] == 'A' && s[i] == 'B') {
            ab = true;
        }
    }
    if (ab && ba) {cout <<"YES";}
    else cout << "NO";
}