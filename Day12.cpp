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

    vector<int> cnt(10, 0);
    vector<pair<vector<int>, pair<int,int> > > set;

    int c = 0, ind = -1;
    while (getline(cin, s) && s != "*") {
        stringstream ss(s);

        string t, x;
        ss >> t;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#')c++;
        }
        if (t[0] >= '0' && t[0] <= '9') {
            if (ind != -1 && ind < 10) {
                cnt[ind] = c;
                //cout << ind << " " << c << "\n";
            }

            ind++;
            c = 0;
        }
        int f = t.find("x");
        if (f != -1) {
            vector<int> a;
            int n = stoll(t.substr(0, f));
            int f2 = t.find(":");
            int m = stoll(t.substr(f + 1, f2));;

            while (ss >> t) {
                a.push_back(stoll(t));
            }
            //cout << n << " " << m << endl;
            set.push_back({a, {n, m}});
        }
    }

    int ans = 0;
    for (int i = 0; i < set.size(); i++) {
        vector<int> a = set[i].first;
        auto [n,m] = set[i].second;

        int cnt_ = 0, sum = 0;
        for (int j = 0; j < a.size(); j++) {
            cnt_ += (a[j] * cnt[j]);
        }
        cout << endl;


        if (cnt_ < n * m) {
            ans++;
        }
    }
    cout << ans << "\n";
}


void Part2() {
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
        //Part2();
    }
}
