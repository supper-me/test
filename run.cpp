#include<iostream>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<assert.h>
using namespace std;
const int   N = 1e5+10 ;
#define ll long long long
#define vec vector
int __gcd(int n, int m) {
	return m == 0 ? n : (__gcd(m, n % m));
}
long long a[N] = { 0 }, b[N] = { 0 };
const int M = 2050;
int count(long long n) {
	int cnt = 0;
	while (n != 0) {
		cnt++;
		n /= 10;
	}
	return cnt;
}int cnt[N], ans[N];
#define inf 100000000;
void solve() {
	int n;
	cin >> n;
	vec<int> a(n);

	int zc = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		zc += (a[i] == 0);
	}
	if (zc != 1) {
		cout << "NO" << '\n';
		return;
	}
	a.push_back(0);
	set<int> s;
	s.insert(a[0]);
	for (int i = 1; i < n + 1; i++) {
		assert(s.size() > 0);
		int last = *s.rbegin();
		for (int j = a[i] + 1; j <= last; j++) {
			if (!s.erase(j)) {
				cout << "NO" << '\n';
				return;
			}
		}

		s.insert(a[i]);
	}

	cout << "YES" << '\n';
}
int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}