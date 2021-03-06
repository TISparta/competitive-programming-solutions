// Math
// 2
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
  ll n, m, k, l;
  cin >> n >> m >> k >> l;
  // m * z - k >= l
  ll z = (l + k + m - 1) / m;
  if (m * z <= n) {
    cout << z << '\n';
  } else {
    cout << -1 << '\n';
  }
  return (0);
}
