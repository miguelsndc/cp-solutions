#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define PI 3.14159265359
#define loop(x, s, n) for(int x = s; x < n; x++)

double f(double x, double b, double c) {
    return (x * x + b * x + c) / sin(x);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    cout << setprecision(10) << fixed;
    while(tt--) {
        double b, c; cin >> b >> c;
        double l = 0, r = (PI/2);
        double eps = 1e-8;
        while(r - l > eps) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (f(m1, b, c) < f(m2, b, c)) {
                r = m2;
            } else {
                l = m1;
            }
        }

        cout << f((l + r) / 2, b, c) << '\n';
    }
}