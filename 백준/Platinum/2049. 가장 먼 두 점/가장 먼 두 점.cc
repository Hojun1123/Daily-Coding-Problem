#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
struct Dot {
	int x, y;
};
int N;
vector<Dot> input;
stack<Dot> s;
vector<Dot> convexHull;
int cross(Dot& a, Dot& b, Dot& c)
{
	Dot line1 = { b.x - a.x, b.y - a.y };
	Dot line2 = { c.x - b.x, c.y - b.y };
	int r = line1.x * line2.y - line1.y * line2.x;
	if (r < 0) return -1;
	if (r > 0) return 1;
	return 0;
}
int cross2(Dot& a, Dot& b, Dot& c, Dot& d) {
	Dot line1 = { b.x - a.x, b.y - a.y };
	Dot line2 = { d.x - c.x, d.y - c.y };
	int r = line1.x * line2.y - line1.y * line2.x;
	if (r < 0) return -1;
	if (r > 0) return 1;
	return 0;
}
int getDistance(Dot a)
{
	//Dot0과의 distance
	return (input[0].x - a.x) * (input[0].x - a.x) + (input[0].y - a.y) * (input[0].y - a.y);
}
bool cmp(Dot& a, Dot& b) {
	int r = cross(input[0], a, b);
	if (r > 0) return 1;
	if (r == 0) return getDistance(a) < getDistance(b);
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int aaa, bbb, taa, tbb;
	cin >> aaa >> bbb;
	input.push_back({ aaa , bbb });
	for (int i = 1; i < N; ++i) {
		cin >> aaa >> bbb;
		if (aaa < input[0].x) {
			taa = input[0].x;
			tbb = input[0].y;
			input[0] = { aaa, bbb };
			input.push_back({ taa, tbb });
		}
		else if (aaa == input[0].x && bbb < input[0].y) {
			taa = input[0].x;
			tbb = input[0].y;
			input[0] = { aaa, bbb };
			input.push_back({ taa, tbb });
		}
		else {
			input.push_back({ aaa, bbb });
		}
	}
	sort(input.begin() + 1, input.end(), cmp);
	s.push(input[0]);
	s.push(input[1]);
	for (int i = 2; i < input.size(); ++i)
	{
		while (s.size() >= 2) {
			Dot prev = s.top();
			s.pop();
			Dot prev2 = s.top();
			if (cross(prev2, prev, input[i]) > 0) {
				s.push(prev);
				break;
			}
		}
		s.push(input[i]);
	}

	while (!s.empty()) {
		convexHull.push_back(s.top());
		s.pop();
	}

	int index = 1;
	int maxDis = 0;
	int cs = convexHull.size();
	for (int i = 0; i < cs; ++i) {
		while (cross2(convexHull[i], convexHull[(i + 1) % cs], convexHull[index % cs], convexHull[(index + 1) % cs]) < 0) {
			//cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ")" <<
			//	" "<< "(" << convexHull[index % cs].x << ", " << convexHull[index % cs].y << ")" << "\n";

			int currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x)
				+ (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
			if (maxDis < currDis) {
				maxDis = currDis;
			}
			index++;
		}

		//cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ")" <<
		//	" " << "(" << convexHull[index % cs].x << ", " << convexHull[index % cs].y << ")" << "\n";

		int currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x)
			+ (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
		if (maxDis < currDis) {
			maxDis = currDis;
		}
	}
	cout << maxDis;
	return 0;
}