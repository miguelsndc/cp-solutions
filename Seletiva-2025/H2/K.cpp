#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

ll n, k, ans = 0;
void dfs(int row, int col, int cnt, bool*diag1, bool *diag2) {
    if (cnt == k) {
        ++ans;
        return;
    } else if (row == n) {
        return;
    } else if (col == n) {
        return dfs(row + 1, 0, cnt, diag1, diag2);
    }

    if (!diag1[row - col + n - 1] && !diag2[row + col]) {
        diag1[row - col + n - 1] = true; 
        diag2[row + col] = true;
        dfs(row, col + 1, cnt + 1, diag1, diag2);
        diag1[row - col + n - 1] = false; 
        diag2[row + col] = false;
    }

    dfs(row, col + 1, cnt, diag1, diag2);
}

vector<vector<int>> table = {
{1, 1, 0},
{1 ,4 ,4 ,0, 0 },
{1, 9 ,26 ,26 ,8 ,0 ,0 },
{1 ,16 ,92, 232 ,260 ,112, 16 ,0 ,0 },
{1 ,25 ,240 ,1124 ,2728, 3368 ,1960 ,440 ,32 ,0 ,0 },
{1 ,36, 520 ,3896 ,16428 ,39680 ,53744, 38368 ,12944 ,1600, 64 ,0 ,0 },
{1 ,49 ,994 ,10894 ,70792 ,282248 ,692320 ,1022320, 867328 ,389312 ,81184 ,5792, 128 ,0 ,0 },
{1 ,64, 1736 ,26192 ,242856 ,1444928 ,5599888, 14082528 ,22522960 ,22057472, 12448832, 3672448, 489536 ,20224 ,256 ,0 ,0 },
};

int main() 
{
    ios_base::sync_with_stdio(0);
    // precomputation 
    // for (int i = 1; i <= 8; i++) {
    //     n = i;
    //     for (int j = 0; j <= 2 * i; j++) {
    //         k = j;
    //         bool diag1[n], diag2[2 * n];
    //         memset(diag1, 0, sizeof(diag1));
    //         memset(diag2, 0, sizeof(diag2));
    //         dfs(0, 0, 0, diag1, diag2);
    //         cout << ans << ' ' << flush;
    //         ans = 0;
    //     }
    //     cout << '\n';
    // }

    while((cin >> n >> k), n || k) {
        if (k > 2 * n) {
            k = 2 * n;
        }
        cout << table[n - 1][k] << '\n';
    }
}