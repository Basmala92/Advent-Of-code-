#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;
int dx[] = {0, 0, 1, -1, -1, 1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

void Part1() {
    vector<string> v;
    string s;
    while (cin >> s && s != "?") {
        v.push_back(s);
    }
    int n = v.size(), m = v[0].size();
    auto in = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '@') {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (in(ni, nj) && v[ni][nj] == '@') {
                        v[ni][nj] = 'x';
                        cnt++;
                    }
                }
                if (cnt <= 3)ans++;
            }
        }
    }
    cout << ans << "\n";
}

void Part2() {
    vector<string> v;
    string s;
    while (cin >> s && s != "?") {
        v.push_back(s);
    }
    int n = v.size(), m = v[0].size();
    auto in = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    int ans = 0, sz = n * m;
    while (sz--) {
        bool f = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '@') {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (in(ni, nj) && v[ni][nj] == '@') {
                            cnt++;
                        }
                    }

                    if (cnt <= 3) {
                        v[i][j] = '.';
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("promote.in","r",stdin);
    // freopen("promote.out","w",stdout);


    int tests = 1;
    //  cin >> tests;
    while (tests--) {
        //Part1();
        Part2();
    }
}
