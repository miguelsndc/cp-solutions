#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    string r;
    for (auto c: s) {
        r.push_back(c);
        if(r.size() >= 3 && r.substr(r.size() - 3) == "ABC") {
            for (int i = 0; i < 3; i++) {
                r.pop_back();
            }
        }
    }
    cout << r;
}