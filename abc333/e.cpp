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
    // os << "[";
    for (int i = 0; i<vec.size(); i++) os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    // os << "]";
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

    vi t(n), x(n);
    REP(i, n) cin >> t[i] >> x[i];

    map<int, int> cnt;
    int k_min = 0, k_now = 0;
    vi ans;
    RREP(i, n-1) {
        if (t[i] == 1) {
            if (cnt[x[i]] > 0) {
                cnt[x[i]]--;
                ans.emplace_back(1);
                k_now--;
            } else {
                ans.emplace_back(0);
            }
        }

        if (t[i] == 2) {
            cnt[x[i]]++;
            k_now++;
        }
        k_min = max(k_min, k_now);
    }

    if (k_now > 0) cout << -1 << endl;
    else {
        reverse(ALL(ans));
        cout << k_min << endl;
        cout << ans << endl;
    }
    return 0;
}