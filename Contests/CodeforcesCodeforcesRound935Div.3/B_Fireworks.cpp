/**
 * Author: C0ldSmi1e
 * Created Time: 03/19/2024 07:47:18 AM
**/

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1945/problem/B
#include <bits/stdc++.h>

using namespace std;

#ifdef DANIEL_DEBUG_TEMPLATE
#include "../debug.h"
#else
#define debug(...) 42
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while (T--) {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << m / a + 1 + m / b + 1 << '\n';
  }
  return 0;
}
