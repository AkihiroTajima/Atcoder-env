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

int N, P[2009], A[2009];
int dp[2009][2009];

int main() {
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];

	// 動的計画法（LEN は r-l の値）
	dp[1][N] = 0;
	for (int LEN = N - 2; LEN >= 0; LEN--) {
		for (int l = 1; l <= N - LEN; l++) {
			int r = l + LEN;

			// score1 の値（l-1 番目のブロックを取り除くときの得点）を求める
			int score1 = 0;
			if (l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];

			// score2 の値（r+1 番目のブロックを取り除くときの得点）を求める
			int score2 = 0;
			if (l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

			// dp[l][r] を求める
			if (l == 1) {
				dp[l][r] = dp[l][r + 1] + score2;
			}
			else if (r == N) {
				dp[l][r] = dp[l - 1][r] + score1;
			}
			else {
				dp[l][r] = max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);
			}
		}
	}

	// 出力
	int Answer = 0;
	for (int i = 1; i <= N; i++) Answer = max(Answer, dp[i][i]);
	cout << Answer << endl;
	return 0;
}