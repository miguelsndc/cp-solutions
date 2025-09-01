#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int months, m;
    double down, loan, dep_records, dep_amount;
    while (cin >> months && months > 0) {
        cin >> down >> loan >> dep_records;
        cin >> m >> dep_amount;
        vector<double> dep(13, -1);
        double car_worth = loan;
        dep[0] = dep_amount;
        car_worth = (car_worth + down) - (car_worth + down) * dep_amount;
        for (int i = 1; i < dep_records; i++) {
            int a;
            double b;
            cin >> a >> b;
            dep[a] = b;
        }
        double curr_dep = dep[0];
        int c = 0;
        while (loan > car_worth) {
            if (dep[min(c + 1, 12)] != -1) curr_dep = dep[c + 1];
            loan -= down;
            car_worth -= (car_worth + down) * curr_dep;
            c++;
        }

        cout << c << " months" << "\n";
    }

    return 0;
}