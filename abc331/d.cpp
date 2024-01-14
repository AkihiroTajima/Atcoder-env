#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, Q, precalc[1010][1010];

long long g(int H, int W) {
  if (H <= N and W <= N) return precalc[H][W];
  int Hq = H / N, Hr = H % N;
  int Wq = W / N, Wr = W % N;
  long long ret = 0;
  ret += g(N, N) * Hq * Wq;
  ret += g(Hr, N) * Wq;
  ret += g(N, Wr) * Hq;
  ret += g(Hr, Wr);
  return ret;
}

long long f(int A, int B, int C, int D) {
  return g(C, D) - g(A, D) - g(C, B) + g(A, B);
}

int main() {
  cin >> N >> Q;
  vector<string> S(N);
  for (auto& s : S) cin >> s;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      precalc[i][j] += S[i - 1][j - 1] == 'B';
      precalc[i][j] += precalc[i - 1][j];
      precalc[i][j] += precalc[i][j - 1];
      precalc[i][j] -= precalc[i - 1][j - 1];
    }
  }
  while (Q--) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << f(A, B, C + 1, D + 1) << "\n";
  }
}
