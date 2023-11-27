#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int temp;
    map<int, int> table;
    for (int i = 0; i < 11; ++i)
        table[i] = 0;
    table[1] = 1;
    table[2] = 2;
    table[3] = 4;
    
    for (int i = 4; i < 11; ++i)
    {
        table[i] = table[i - 1] + table[i - 2] + table[i - 3];
    }
    
    for (int i = 0; i < T; ++i)
    {
        cin >> temp;
        cout << table[temp] << "\n";
    }
    return 0;
}