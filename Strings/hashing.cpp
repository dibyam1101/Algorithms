#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
const int mod = 1e9 + 7;
const int base = 33;

int add(int a, int b, int mod) {
  int res = ((a + b) % mod + mod) % mod;
  return res;
}

int mult(int a, int b, int mod) {
  int res = (a * 1LL * b) % mod;
  if (res < 0)
    res += mod;
  return res;
}

int power(int a, int b, int mod) {
  int res = 1;
  while (b) {
    if (b & 1)
      res = mult(res, a, mod);
    a = mult(a, a, mod);
    b >>= 1;
  }

  return res;
}

class StringHashmap {
  const static int N = 1e3;
  const int static mod = 1e9 + 7;
  const int static base = 33;

  int powers[N];
  int inverses[N];
  int hash[N];

  void precalc() {
    powers[0] = 1;
    for (int i = 1; i < N; i++)
      powers[i] = mult(powers[i - 1], base, mod);

    int pw_inv = power(base, mod - 2, mod);
    inverses[0] = 1;
    for (int i = 1; i < N; i++)
      inverses[i] = mult(inverses[i - 1], pw_inv, mod);
  }

 public:
  void build(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++)
      hash[i] = add(i == 0 ? 0 : hash[i - 1], mult(powers[i], s[i] - 'a' + 1, mod), mod);
  }

  int getHash(int x, int y) {
    int res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], mod);
    res = mult(res, inverses[x], mod);
    return res;
  }

  void preCompute() {
    precalc();
  }
  
};

int main() {
  string s;
  cin >> s;
  StringHashmap *mp = new StringHashmap();
  mp->preCompute();
  mp->build(s);
  cout << mp->getHash(0, 2);
  return 0;
}