#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
string a;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> a;
	regex pattern("((100+1+)|(01))+");
    cout << (regex_match(a, pattern) ? "SUBMARINE" : "NOISE");
    return 0;
}