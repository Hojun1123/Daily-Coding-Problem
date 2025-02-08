#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
struct Input {
	long long x, y, dx, dy;
};
vector<Input> stars;
struct Dot {
	long long x, y;
};
int N, T;
vector<Dot> input;
stack<Dot> s;
vector<Dot> convexHull;
int cross(Dot& a, Dot& b, Dot& c)
{
	Dot line1 = { b.x - a.x, b.y - a.y };
	Dot line2 = { c.x - b.x, c.y - b.y };
	long long r = line1.x * line2.y - line1.y * line2.x;
	if (r < 0) return -1;
	if (r > 0) return 1;
	return 0;
}
int cross2(Dot& a, Dot& b, Dot& c, Dot& d) {
	Dot line1 = { b.x - a.x, b.y - a.y };
	Dot line2 = { d.x - c.x, d.y - c.y };
	long long r = line1.x * line2.y - line1.y * line2.x;
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
long long sim(int day)
{
	input.clear();
	convexHull.clear();
	// 현재 시간에 별들의 위치 정보 계산
	for (int i = 0; i < stars.size(); ++i) {
		input.push_back({
			stars[i].x + stars[i].dx * day,
			stars[i].y + stars[i].dy * day,
		});
	}

	// convex hull 계산
	Dot temp;
	for (int i = 1; i < input.size(); ++i) {
		if (input[i].x < input[0].x) {
			temp = input[0];
			input[0] = input[i];
			input[i] = temp;
		}
		else if (input[i].x == input[0].x && input[i].y < input[0].y) {
			temp = input[0];
			input[0] = input[i];
			input[i] = temp;
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


	// 캘리퍼스 계산
	while (!s.empty()) {
		convexHull.push_back(s.top());
		s.pop();
	}

	int index = 1;
	long long maxDis = 0;
	int cs = convexHull.size();
	for (int i = 0; i < cs; ++i) {
		while (cross2(convexHull[i], convexHull[(i + 1) % cs], convexHull[index % cs], convexHull[(index + 1) % cs]) < 0) {
			long long currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x)
				+ (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
			if (maxDis < currDis) {
				maxDis = currDis;
			}
			index++;
		}
		long long currDis = (convexHull[i].x - convexHull[index % cs].x) * (convexHull[i].x - convexHull[index % cs].x)
			+ (convexHull[i].y - convexHull[index % cs].y) * (convexHull[i].y - convexHull[index % cs].y);
		if (maxDis < currDis) {
			maxDis = currDis;
		}
	}
	//maxDis.
	//cout << "maxDis: " << maxDis << "\n";
	return maxDis;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> T;
	int x, y, dx, dy;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> dx >> dy;
		stars.push_back({ x, y, dx, dy });
	}


	long long shortestDistance = 8000000000000000000;
	int shortestDay = 0;
	if (N == 2) {
		for (int i = 0; i <= T; ++i) {
			Dot star1 = { stars[0].x + stars[0].dx * i, stars[0].y + stars[0].dy * i };
			Dot star2 = { stars[1].x + stars[1].dx * i, stars[1].y + stars[1].dy * i };

			long long currDis = (star1.x - star2.x) * (star1.x - star2.x)
				+ (star1.y - star2.y) * (star1.y - star2.y);
			//cout << currDis << "\n";
			if (currDis < shortestDistance) {
				shortestDistance = currDis;
				shortestDay = i;
			}
		}
		cout << shortestDay << "\n" << shortestDistance;
	}
	else {
		if (T < 5) {
			for (int i = 0; i <= T; ++i) {
				long long ret = sim(i);
				if (ret < shortestDistance) {
					shortestDistance = ret;
					shortestDay = i;
				}
			}
			cout << shortestDay << "\n" << shortestDistance;
		}
		else {
			//삼분
			int left = 0;
			int right = T;
			while (left - right >= 3) {
				int lm = (left * 2 + right) / 3;
				int rm = (right * 2 + left) / 3;
				if (sim(lm) < sim(rm)) {
					right = rm;
				}
				else{
					left = lm;
				}
			}

			for (int i = 0; i < 3; ++i) {
				long long ret = sim(left + i);
				if (ret < shortestDistance) {
					shortestDistance = ret;
					shortestDay = i + left;
				}
			}
			cout << shortestDay << "\n" << shortestDistance;
		}
	}
	return 0;
}