#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;

struct DSU {
    DSU(int n) {
        init(n);
    }

    DSU() {
    }

    vector<int> par, sz;

    void init(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int mx = 0;
    int find(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] > sz[v])
            swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        mx = max(mx, sz[v]);
        return true;
    }

    int getMax3() {
        vector<int> mx;
        for (int i = 0; i < sz.size(); i++) {
            //    cout << sz[i] << " ";
            mx.push_back(sz[i]);
        }
        sort(allr(mx));
        return mx[0] * mx[1] * mx[2];
    }

    int get_fullyconnected() {
        return mx;
    }
};

ld get_dest(array<ld, 3> a, array<ld, 3> b) {
    auto [x1,y1,z1] = a;
    auto [x2,y2,z2] = b;
    ld x = (x1 - x2) * (x1 - x2), y = (y1 - y2) * (y1 - y2), z = (z1 - z2) * (z1 - z2);
    ld dist = x + y + z;
    return sqrtl(dist);
}

void Part1() {
    string s;
    vector<array<ld, 3> > v;
    while (getline(cin, s) && s != "*") {
        ld x = 0, y = 0, z = 0;
        string num = "";

        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ',')
                num += s[i];
            else if (s[i] == ',' || i == s.size() - 1) {
                ld n = stoll(num);
                if (cnt == 0)x = n;
                else if (cnt == 1)y = n;
                else if (cnt == 2)z = n;
                num = "";
                cnt++;
            }
        }
        if (!num.empty()) {
            z = stoll(num);
        }

        v.push_back({x, y, z});
    }
    vector<pair<ld, pair<int,int> > > all;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            ld dist = get_dest(v[i], v[j]);
            all.push_back({dist, {i, j}});
        }
    }
    sort(all.begin(), all.end());
    // cout << all.size() << endl;
    // cout << v.size() << endl;
    DSU dsu((int) v.size());
    for (int i = 0; i < all.size(); i++) {
        auto [w,x] = all[i];
        dsu.merge(x.first, x.second);
        if (dsu.get_fullyconnected() == v.size()) {
            // this is the part 2
            int ind1 = x.first, ind2 = x.second;
            cout << (int) (v[ind1][0] * v[ind2][0]) << endl;
            break;
        }
    }
    cout << dsu.getMax3() << "\n";
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
