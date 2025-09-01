#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define debug(x) cout << #x << " is: " << x << '\n'
#define write(x) cout << x << ' '; 
#define writeln(x) cout << x << '\n';
#define se second

const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    vi stack;
    while(n--) {
        string op; cin >> op;
        if (op == "PUSH") {
            int x; cin >> x;
            stack.push_back(x);
            mp[x]++;
        } else if (op == "MIN") {
            if (mp.size() > 0) {
                auto el = mp.lower_bound(0);
                cout << (el->first) << '\n';
            } else {
                cout << "EMPTY\n";
            }
        } else {
            if (mp.size() > 0) {
                mp[stack.back()]--;
                if (mp[stack.back()] == 0) {
                    mp.erase(stack.back());
                }
                stack.pop_back();
            } else {
                cout << "EMPTY\n";
            }
        }
    }
}