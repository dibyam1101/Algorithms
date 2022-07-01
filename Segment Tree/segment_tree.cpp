#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n, t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }

  int tm = (tr + tl) / 2;
  build(a, 2 * v, tl, tm);
  build(a, 2 * v + 1, tm + 1, tr);
  t[v] = t[2 * v] + t[2 * v + 1];
}

int sum(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;

  if (l == tl && r == tr)
    return t[v];

  int tm = (tr + tl) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
    return;
  }

  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(2 * v, tl, tm, pos, val);
  else
    update(2 * v + 1, tm + 1, tr, pos, val);

  t[v] = t[2 * v] + t[2 * v + 1];
};
int main() {
  return 0;
}