#include <bits/stdc++.h>
#define int long long
#define allr(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define ld long double
#define INF (int)(1e18)
#define MOD 1000000007
using namespace std;

vector<string> x;
vector<char> sign;

vector<vector<int> > Part1() {
    string num;
    vector<vector<int> > v;
    while (getline(cin, num) && num != "*") {
        x.push_back(num); //for part2
        vector<int> a;
        string s = "";
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != ' ') {
                s += num[i];
            } else {
                int c = 0;
                while (num[i] == ' ') {
                    i++;
                }
                i--;

                int x = 0;
                if (!s.empty()) {
                    x = stoll(s);
                    a.push_back(x);
                }

                s = "";
            }
        }
        if (!s.empty()) {
            int x = stoll(s);
            a.push_back(x);
        }
        if (a.size()) {
            v.push_back(a);
        }
    }


    string sgn;
    while (getline(cin, sgn) && sgn != "-") {
        for (int i = 0; i < sgn.size(); i++) {
            if (sgn[i] == '*') {
                sign.push_back('*');
            } else if (sgn[i] == '+') {
                sign.push_back('+');
            }
        }
    }
    int ans = 0;
    int row = v.size(), col = sign.size();


    for (int i = 0; i < sign.size(); i++) {
        int op = 0;
        for (int j = 0; j < v.size(); j++) {
            if (sign[i] == '*') {
                if (op == 0)op = 1;
                op *= v[j][i];
            } else op += v[j][i];
        }

        ans += op;
    }
    // cout << ans << endl;
    return v;
}

int getPart2Num(vector<string> a, char sign,int sz) {
    vector<int> b;
    int x = 0;
    if (sign == '*')
        x = 1;
    for (int i = 0; i < sz; i++) {
        string s = "";
        for (int j = 0; j < a.size(); j++) {
            if (a[j][i] != ' ')s += a[j][i];
        }

        int num = 0;
        if (s[0] >= '0' && s[0] <= '9')
            num = stoll(s);
        if (sign == '*')
            x *= num;
        else
            x += num;
    }
    return x;
}

vector<int> sz;

vector<int> getmax(vector<vector<int> > v) {
    sz.resize(v[0].size());
    for (int i = 0; i < v[0].size(); i++) {
        int mx = 0;
        for (int j = 0; j < v.size(); j++) {
            string s = to_string(v[j][i]);
            mx = max(mx, (int) s.size());
        }
        sz[i] = mx;
    }
    return sz;
}

void Part2() {
    vector<vector<string> > v;


    for (int k = 0; k < x.size(); k++) {
        vector<string> a;
        string num = x[k];


        string s = "";
        int ind = 0;
        for (int i = 0; i < num.size(); i++) {
            while (i < num.size() && s.size() <= sz[ind]) {
                s += num[i];
                i++;
            }
            ind++;
            i--;
            if (!s.empty()) {
                a.push_back(s);
                s.clear();
            }
        }

        if (a.size()) {
            v.push_back(a);
        }
    }
    //cout << v[0].size() << endl;
    int ans = 0;
    for (int i = 0; i < v[0].size(); i++) {
        vector<string> a;
        for (int j = 0; j < v.size(); j++) {
            a.push_back(v[j][i]);
            //   cout << v[j][i] << " ";
        }


        int b = getPart2Num(a, sign[i], sz[i]);

        ans += b;
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
        sz = getmax(Part1()); // for part2
        Part2();
    }
}
