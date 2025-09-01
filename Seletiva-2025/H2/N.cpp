#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int px, py;
int ax, ay;
int bx, by;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool circle_intersects(double w) {
    return dist(ax, ay, bx, by) <= (w + w);
}

bool circle_contains_p(double cx, double cy, double x, double y, double w) {
    return (((x - cx) * (x - cx)) + ((y - cy) * (y - cy))) <= w*w;
}

bool ok(double w) {
    bool a_contains_p = circle_contains_p(ax, ay, px, py, w);
    bool a_contains_or = circle_contains_p(ax, ay, 0,0, w);
    bool b_contains_p = circle_contains_p(bx, by, px, py, w);
    bool b_contains_or = circle_contains_p(bx, by, 0, 0, w);
    bool intersect = circle_intersects(w);

    if (a_contains_or && a_contains_p) {
        return true;
    } else if (b_contains_p && b_contains_or) {
        return true;
    } else if (a_contains_or && b_contains_p && intersect) {
        return true;
    } else if (b_contains_or && a_contains_p && intersect) {
        return true;
    }


    return false;
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) {
        cin >> px >> py;
        cin >> ax >> ay;
        cin >> bx >> by;

        double da = dist(ax, ay, px, py);
        double db = dist(bx, by, px, py);
        double da_or = dist(ax, ay, 0, 0);
        double db_or = dist(bx, by, 0, 0);
        
        vector<double> s = {da, db, db_or, da_or};

        double z = *max_element(begin(s), end(s));

        double x = 0;
        for (double b = z; b >= 1e-12; b/=2.0) {
            while(!ok(x + b)) x += b;
        }

        cout << setprecision(10) << fixed;
        cout << x << '\n';
    }
}