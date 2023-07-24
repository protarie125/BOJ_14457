#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vector<string> cows;
pii pos;

bool isOne() {
	auto ret = bool{ false };
	pos = { -1, -1 };
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			if ('1' == cows[i][j]) {
				pos = { i,j };
				ret = true;
			}
		}
	}

	return ret;
}

void toggle() {
	for (auto i = 0; i <= pos.first; ++i) {
		for (auto j = 0; j <= pos.second; ++j) {
			if ('0' == cows[i][j]) {
				cows[i][j] = '1';
			}
			else {
				cows[i][j] = '0';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	cows = vector<string>(n);
	for (auto&& r : cows) {
		cin >> r;
	}

	auto ans = int{ 0 };
	while (isOne()) {
		toggle();
		++ans;
	}

	cout << ans;

	return 0;
}