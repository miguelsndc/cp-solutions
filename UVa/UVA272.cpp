#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    int opened = true;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '"') {
                opened ? line.replace(i, 1, "``") : line.replace(i, 1, "''");
                opened = !opened;
            }
        }
        cout << line << '\n';
    }
    return 0;
}
