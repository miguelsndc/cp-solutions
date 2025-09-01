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
    int t; cin >> t;
    while(t--) {
        int n, s1 = 0, s2 = 0, s3 = 0; cin >> n;
        map<string, array<int, 3>> mp;
        string s;
        loop(i, 0, n) {
            cin >> s; mp[s][0]++;
        }
        loop(i, 0, n) {
            cin >> s; mp[s][1]++;
        }
        loop(i, 0, n) {
            cin >> s; mp[s][2]++;
        }
        for (auto [_, triple]: mp) {
            auto [a, b, c] = triple;
            if (a == 1 && b == 1 && c == 1) continue;

            if (a == b && b && c == 0) {
                s1++; s2++;
            }
            if (a == c && b == 0) {
                s1++; s3++;
            }
            if (c == b && a == 0) {
                s2++; s3++;
            }
            if (a + b + c == a) s1 += 3;
            if (a + b + c == b) s2 += 3;
            if (a + b + c == c) s3 += 3;
        }
        cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
    }
}