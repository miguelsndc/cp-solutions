#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

double f(double k, vi& speed, vi& dist) {
    double maxp = 0;
    double minp = 1e9  + 1;

    for (int i = 0; i < speed.size(); i++) {
        double s = speed[i] * k + dist[i];
        maxp = max(maxp, s);
        minp = min(minp, s);
    }

    return maxp - minp;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vi speed(n);
    vi dist(n); 
    loop(i, 0, n) {
        cin >> speed[i] >> dist[i];
    }

    double l = 0, r = k;
    double eps = 1e-12;
    while(r - l > eps) {
        double m1 = l + ((r - l) / 3);
        double m2 = r - ((r - l) / 3);
        double k1 = f(m1, speed, dist);
        double k2 = f(m2, speed, dist);
        if (k1 < k2) {
            r = m2;
        }
        else{
            l = m1;
        }
    }

    cout << setprecision(6) << fixed;
    cout << f((l + r) / 2.0, speed, dist);
}