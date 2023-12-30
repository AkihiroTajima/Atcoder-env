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

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int cnt_1 = 0;
    int cnt_2 = 0;
    int ans = 0;
    for (char c : s) {
        if (c == '0') {
            ans = max(ans, max(0, cnt_1-m)+cnt_2);
            cnt_1 = 0;
            cnt_2 = 0;
        } else if (c == '1') cnt_1++;
        else if (c == '2') cnt_2++;
    }

    cout << max(ans, max(0, cnt_1-m)+cnt_2) << endl;
    return 0;
}