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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
// const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

vi di {-1, 0, 1, 0};
vi dj {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vs s(h);
    REP(i, h) cin >> s[i];

    UnionFind uf(h*w);

    mint ans = 0;
    vector<pii> reds;
    ll c_now = 0;
    auto dfs = [&](auto f, int i, int j) -> void {
        s[i][j] = '0';
        REP(d, 4) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (!INRANGE(ni, 0, h-1)) continue;;
            if (!INRANGE(nj, 0, w-1)) continue;
            if (s[ni][nj] != '#') continue;
            uf.unite(i*w+j, ni*w+nj);
            f(f, ni, nj);
        }
        return;
    };
    REP(i, h) REP(j, w) {
        if (s[i][j] == '.') reds.emplace_back(i, j);
        else if (s[i][j] == '#') {
            dfs(dfs, i, j);
            c_now++;
        }
    }

    //debug(c_now)

    for (auto [i, j] : reds) {
        bool all_red = true;
        REP(d, 4) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (!INRANGE(ni, 0, h-1)) continue;
            if (!INRANGE(nj, 0, w-1)) continue;
            if (s[ni][nj] != '.') all_red = false;
        }
        if (all_red) {
            ans += c_now + 1; //debug(c_now + 1)
        } else  {
            set<ll> st;
            REP(d, 4) FOR(d2, d+1, 4) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (!INRANGE(ni, 0, h-1)) continue;
                if (!INRANGE(nj, 0, w-1)) continue;
                if (s[ni][nj] == '.') continue;
                int ni2 = i + di[d2];
                int nj2 = j + dj[d2];
                if (!INRANGE(ni2, 0, h-1)) continue;
                if (!INRANGE(nj2, 0, w-1)) continue;
                if (s[ni2][nj2] == '.') continue;
                st.emplace(uf.find(ni*w+nj));
                st.emplace(uf.find(ni2*w+nj2));
            }
            int n_type = max((int)st.size()-1, 0);
            ans += c_now - n_type; //debug(c_now - n_type)
        }
    }

    cout << ans/reds.size() << endl;;
    return 0;
}