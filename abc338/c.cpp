#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
// #define int long long

template <class T>
bool INRANGE(T x, T a, T b) { return a <= x && x <= b; }
template <class T>
inline bool chmin(T &a, T b) {if (a > b) {a = b; return true; } return false;}
template <class T>
inline bool chmax(T &a, T b) {if (a < b) {a = b; return true; } return false;}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "[";
    for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    os << "]";
    return os;
}

template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "{";
    for (typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if(itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if(itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define debug(x) cerr << #x << " = " << (x) << endl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi q(n), a(n), b(n);
    REP(i, n) cin >> q[i];
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    int num_a = 2e6;
    REP(i, n) if (a[i] != 0) num_a = min(num_a, q[i]/a[i]);
    REP(i, n) q[i] -= a[i]*num_a;

    auto num_make_b = [&]() {
        int num_b = 2e6;
        REP(i, n) if (b[i] != 0) num_b = min(num_b, q[i]/b[i]);
        return num_b;
    };

    int num_b = num_make_b();
    REP(i, n) q[i] -= b[i]*num_b;
    int ans = num_a + num_b;

    int tmp = ans;
    REP(_, num_a) {
        REP(i, n) q[i] += a[i];
        tmp--;
        int num_b = num_make_b();
        REP(i, n) q[i] -= b[i]*num_b;
        tmp += num_b;

        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}