#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(string &S) {
    vector<int> R(S.size());
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i - j >= 0 && i + j < S.size() && S[i - j] == S[i + j]) ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && k + R[i - k] < j) R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }
    return R;
}

int main() {
    string s;
    cin >> s;
    string ms = "$";
    for (auto &nx : s) {
        ms.push_back(nx);
        ms.push_back('$');
    }
    auto r = manacher(ms);
    int k = 0;
    for (int i = s.size();; i++) {
        if (r[i] >= s.size() - k) {
            break;
        }
        k++;
    }

    cout << s;
    for (int i = 0; i < k; i++) {
        cout << s[k - 1 - i];
    }
    cout << "\n";
    return 0;
}
