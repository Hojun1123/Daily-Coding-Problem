#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
double gradient(vector<int> l1, vector<int> l2);
int solution(vector<vector<int>> dots) {
    double temp;
    vector<double> result;
    vector<vector<int>> m =
    {
        {0, 1, 2, 3},
        {0, 2, 1, 3},
        {0, 3, 1, 2}
    };
    for(vector<vector<int>>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if(gradient(dots[(*iter)[0]], dots[(*iter)[1]]) == gradient(dots[(*iter)[2]], dots[(*iter)[3]]))
            return 1;
    }
    return 0;
}

double gradient(vector<int> l1, vector<int> l2)
{
    double g;
    return double(l1[0] - l2[0]) / (l1[1] - l2[1]);
}