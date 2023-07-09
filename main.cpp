#include<iostream>
#include<string>

using namespace std;

int main() {
	int t, sx, sy, ex, ey;

	cin >> t >> sx >> sy >> ex >> ey;

	int mx = ex - sx;
	int my = ey - sy;

	// NSEW mask
	int mask = 0;
	const int n = 1 << ('N' - 'E');
	const int so = 1 << ('S' - 'E');
	const int e = 1;
	const int w = 1 << ('W' - 'E');
	mask = (mx > 0) * e  + (mx < 0) * w + (my > 0) * n + (my < 0) * so;

	if (abs(mx) + abs(my) > t) {
		cout << -1;
		return 0;
	}

	char c;
	t = 1;
	while (cin >> c) {
		if (mask & (1 << (c - 'E'))) {
			my += - (c == 'N') + (c == 'S');
			mx += - (c == 'E') + (c == 'W');
			
			if (mx == 0 && my == 0) {
				cout << t;
				return 0;
			} else if (mx == 0 || my == 0) {
				mask = (mx > 0) * e  + (mx < 0) * w + (my > 0) * n + (my < 0) * so;
			}
		}
		t++;
	}

	cout << -1;
	return 0;
}
