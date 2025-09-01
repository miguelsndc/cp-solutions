#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

int f(int x, int d) {
    return ceil(x + (d / (x + 1.0)));
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int deadline, runtime;
        cin >> deadline >> runtime;
        int l = 0, r = runtime;

        if (runtime <= deadline) {
            cout<<"YES\n";
            continue;
        }

        bool possible = false;
        for (int x = 0; x <= deadline; x++) {
            if (f(x, runtime) <= deadline) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
       
    }
}