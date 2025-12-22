#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;


void Part1() {
    vector<pair<int,int> > v;

    string s;
    while (cin >> s && s != "*") {
        string x = s.substr(0, s.find(',')), y = s.substr((int) s.find(',') + 1);
        int num1 = stoi(x), num2 = stoi(y);

        v.push_back(make_pair(num1, num2));
    }


    int mx = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[j];
            int area = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
            mx = max(mx, area);
        }
    }
    cout << mx << "\n";
    //end of part1
    vector<int> X, Y;
    for (int i = 0; i < v.size(); i++) {
        X.push_back(v[i].first);
        X.push_back(v[i].first + 1);
        Y.push_back(v[i].second);
        Y.push_back(v[i].second + 1);
    }
    sort(X.begin(), X.end());
    X.erase(unique(all(X)), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(all(Y)), Y.end());
    int n = X.size(), m = Y.size();
    vector<vector<bool> > w(n + 1, vector<bool>(m + 1, false));
    vector<vector<bool> > valid(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < v.size(); i++) {
        auto p1 = v[i];
        auto p2 = v[(i + 1) % v.size()];
        int x1 = lower_bound(all(X), p1.first) - X.begin();
        int x2 = lower_bound(all(X), p2.first) - X.begin();
        int y1 = lower_bound(all(Y), p1.second) - Y.begin();
        int y2 = lower_bound(all(Y), p2.second) - Y.begin();
        if (x1 == x2) {
            for (int y = min(y1, y2); y < max(y1, y2); ++y) w[x1][y] = true;
        }
        for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
            for (int y = min(y1, y2); y <= max(y1, y2); ++y)valid[x][y] = true;
        }
    }
    vector<vector<long long> > preSum(n + 1, vector<long long>(m + 1, 0));
    for (int j = 0; j < m - 1; j++) {
        bool in = false;
        for (int i = 0; i < n - 1; i++) {
            if (w[i][j]) in = !in;
            if (in || valid[i][j]) {
                int area = (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
                preSum[i + 1][j + 1] = area;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            preSum[i][j] += preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << preSum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[j];
            int mnx = min(x1, x2), mxx = max(x1, x2);
            int mny = min(y1, y2), mxy = max(y1, y2);
            int area1 = (mxx - mnx + 1) * (mxy - mny + 1);
            int lo1 = lower_bound(all(X), mnx) - X.begin();
            int lo2 = lower_bound(all(X), mxx + 1) - X.begin();
            int lo3 = lower_bound(all(Y), mny) - Y.begin();
            int lo4 = lower_bound(all(Y), mxy + 1) - Y.begin();

            int area2 = preSum[lo2][lo4] - preSum[lo1][lo4] - preSum[lo2][lo3] + preSum[lo1][lo3];
            if (area1 == area2) {
                ans = max(ans, area2);
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
        Part1();
    }
}
