#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

// - 1o passo sempre pra direita ou pra baixo/
// - ultimo passo sempre pra baixo ou pra esquerda
// - se chegar no target antes eantao nao tem como
// - se bater numa parede ou num quadrado ja visitado e tiver como virar pra esquerda/direita ou cima/baixo entao n tem como tb

vector<vi> vis(7, vi(7));

bool isvalid(int i, int j) {
    return (i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j]);
}

ll c = 0;
void solve(int i, int row, int col, string& s) {
    if (i == 48) {
        if (row == 6 && col == 0) {
            c++;
        } 
        return;
    }

    bool up = isvalid(row - 1, col);
    bool down =  isvalid(row + 1, col);
    bool right = isvalid(row, col + 1);
    bool left = isvalid(row,col - 1);

    if (vis[6][0]) return;
    if (!right && !left && up && down) return;
    if (!down && !up && left && right) return;

    vis[row][col] = true;
    if ((s[i] == 'D' || s[i] == '?') && down) solve(i + 1, row + 1, col, s);
    if ((s[i] == 'L' || s[i] == '?') && left) solve(i + 1, row, col - 1, s);
    if ((s[i] == 'R' || s[i] == '?') && right) solve(i + 1, row, col + 1, s);
    if ((s[i] == 'U' || s[i] == '?') && up) solve(i + 1, row - 1, col, s);
    vis[row][col] = false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    solve(0, 0, 0, s);
    cout << c;
}