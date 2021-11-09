#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	// count the "face" strings that can be formed in every four cells of the 2D-array
	// we can do this by sorting the formed string into "acef" to make sure that all
	// the needed characters are present
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && j + 1 < m) {
				string temp = "";
				for (int k = j; k < j + 2; k++) {
					temp += string(1, a[i][k]);
				}
				for (int k = j; k < j + 2; k++) {
					temp += string(1, a[i + 1][k]);
				}
				sort(temp.begin(), temp.end());
				cnt += (temp == "acef");
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
