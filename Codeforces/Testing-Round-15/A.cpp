// Implementation
// 2
// 10-11-2020

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
  int k;
  cin >> k;
  string ans = "";
  int cur = 1;
  while (sz(ans) < k) {
    ans += to_string(cur);
    cur += 1;
  }
  cout << ans[k - 1] << '\n';
  return (0);
}
