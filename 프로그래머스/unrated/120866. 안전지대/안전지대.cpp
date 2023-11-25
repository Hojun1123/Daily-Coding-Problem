#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    int arr[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    int y, x;
    vector<vector<bool>> result;
    for(int i = 0; i < size + 2; ++ i)
    {
        vector<bool> temp;
        for(int j = 0; j < size + 2; ++ j)
        {
            temp.push_back(false);
        }
        result.push_back(temp);
    }
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(board[i][j] == 1)
            {
                result[i + 1][j + 1] = true;
                for(int k = 0; k < 8; ++k){
                    result[arr[k][0] + i + 1][arr[k][1] + j + 1] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= size; ++i)
    {   for(int j = 1; j <= size; ++j)
            answer += result[i][j] ? 0 : 1;
    }   
    return answer;
}