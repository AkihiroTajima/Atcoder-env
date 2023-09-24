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

const vi di {1, -1, 0, 0};
const vi dj {0, 0, 1, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vs s(n);
    REP(i, n) cin >> s[i];

    queue<pii> q;
    vector visited(n, vector<bool>(m));
    int ans = 1;
    q.emplace(1, 1);
    visited[1][1] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        REP(i, 4) {
            int ni = now.first;
            int nj = now.second;
            while (s[ni][nj] != '#') {
                ni += di[i];
                nj += dj[i];
                if (s[ni][nj] == '#') break;
                if (!visited[ni][nj]) {
                    ans++;
                    if (s[ni+di[i]][nj+dj[i]] == '#') q.emplace(ni, nj);
                }
                visited[ni][nj] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}