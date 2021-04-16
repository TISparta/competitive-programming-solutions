// Constructive Algorithms
// 3
// 05-04-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vpii> ans(n + 1);
  vector <vi> g(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[min(a, b)].pb(max(a, b));
  }
  int row = 1;
  for (int c = 1; c <= n; c++) {
    ans[c].emplace_back(row++, c);
    for (int d: g[c]) {
      ans[c].emplace_back(row, c);
      ans[d].emplace_back(row, d);
      row += 1;
    }
  }
  for (int c = 1; c <= n; c++) {
    cout << sz(ans[c]) << '\n';
    for (auto [x, y]: ans[c]) {
      cout << x << ' ' << y << '\n';
    }
  }
  return (0);
}
