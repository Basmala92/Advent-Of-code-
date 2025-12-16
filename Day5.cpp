#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;


void Part1() {
    string s;
    vector<pair<int, int> > v;
    while (cin >> s && s != "-") {
        string x = "", y = "";
        int ind = s.find("-");
        x = s.substr(0, ind);
        y = s.substr(ind + 1);
        int num1 = stoll(x), num2 = stoll(y);
        v.push_back({num1, num2});
    }

    int num, cnt = 0;
    while (cin >> num && num != -1) {
        for (auto [l,r]: v) {
            if (num >= l && num <= r) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << "\n";
}

void Part2() {
    string s;
    vector<pair<int, int> > v;
    while (cin >> s && s != "-") {
        string x = "", y = "";
        int ind = s.find("-");
        x = s.substr(0, ind);
        y = s.substr(ind + 1);
        int num1 = stoll(x), num2 = stoll(y);
        v.push_back({num1, num2});
    }

    int num;
    while (cin >> num && num != -1) {
    }
    sort(v.begin(), v.end());
    int ans = 0, l = v[0].first, r = v[0].second;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first <= r) {
            l = min(l, v[i].first);
            r = max(r, v[i].second);
        } else {
            ans += r - l + 1;
            //cout << l << " " << r << "\n";
            l = v[i].first;
            r = v[i].second;
        }
    }
    ans += r - l + 1;
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
