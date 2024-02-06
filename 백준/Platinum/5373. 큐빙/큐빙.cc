#include <iostream>
#include <sstream>
using namespace std;
// + 시계, - 반시계
// U위, D아래, F앞, B뒤, L왼, R오
int T, N;
int main()
{
    int box[6][4] = {
        {2, 5, 3, 4}, {2, 4, 3, 5}, {0, 4, 1, 5}, {0, 5, 1, 4}, {0, 3, 1, 2}, {0, 2, 1, 3}
    };

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        cin >> N;
        string cube[6][3] = {
    {"www", "www", "www"},
    {"yyy", "yyy", "yyy"},
    {"rrr", "rrr", "rrr"},
    {"ooo", "ooo", "ooo"},
    {"ggg", "ggg", "ggg"},
    {"bbb", "bbb", "bbb"}
        };
        for (int q = 0; q < N; ++q)
        {
            char p, dir;
            cin >> p >> dir;
            string tmp;
            string tmp2 = "";
            int index = 0;
            switch (p)
            {
            case 'U':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[0][i];
                }
                if (dir == '+')
                {
                    tmp = cube[box[0][0]][0];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[0][i]][0] = cube[box[0][i + 1]][0];
                    }
                    cube[box[0][3]][0] = tmp;

                    for (int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[0][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    tmp = cube[box[1][0]][0];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[1][i]][0] = cube[box[1][i + 1]][0];
                    }
                    cube[box[1][3]][0] = tmp;

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[0][i][j] = tmp2[index++];
                        }
                    }
                }
                break;
            case 'D':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[1][i];
                }
                if (dir == '+')
                {
                    tmp = cube[box[1][0]][2];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[1][i]][2] = cube[box[1][i + 1]][2];
                    }
                    cube[box[1][3]][2] = tmp;

                    for (int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[1][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    tmp = cube[box[0][0]][2];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[0][i]][2] = cube[box[0][i + 1]][2];
                    }
                    cube[box[0][3]][2] = tmp;

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[1][i][j] = tmp2[index++];
                        }
                    }
                }
                break;
            case 'F':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[2][i];
                }
                if (dir == '+')
                {
                    tmp = cube[box[2][0]][2];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][0]][2][i] = cube[box[2][1]][2- i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][1]][i][2] = cube[box[2][2]][0][i];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][2]][0][i] = cube[box[2][3]][2 - i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][3]][i][0] = tmp[i];
                    }


                    for (int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[2][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    tmp = cube[box[3][0]][2];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][0]][2][i] = cube[box[3][1]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][1]][2 - i][0] = cube[box[3][2]][0][i];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][2]][0][i] = cube[box[3][3]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][3]][i][2] = tmp[2 - i];
                    }

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[2][i][j] = tmp2[index++];
                        }
                    }
                }

                break;
            case 'B':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[3][i];
                }
                if (dir == '+')
                {
                    tmp = cube[box[3][0]][0];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][0]][0][i] = cube[box[3][1]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][1]][i][2] = cube[box[3][2]][2][2 - i];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][2]][2][i] = cube[box[3][3]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[3][3]][i][0] = tmp[2 - i];
                    }


                    for (int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[3][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    tmp = cube[box[2][0]][0];
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][0]][0][2 - i] = cube[box[2][1]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][1]][i][0] = cube[box[2][2]][2][i];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][2]][2][i] = cube[box[2][3]][2 - i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[2][3]][i][2] = tmp[i];
                    }

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[3][i][j] = tmp2[index++];
                        }
                    }
                }


                break;
            case 'L':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[4][i];
                }
                if (dir == '+')
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        tmp += cube[box[4][0]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][0]][i][0] = cube[box[4][1]][2 - i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][1]][i][2] = cube[box[4][2]][2 - i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][2]][i][0] = cube[box[4][3]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][3]][i][0] = tmp[i];
                    }

                    for (int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[4][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        tmp += cube[box[5][0]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][0]][i][0] = cube[box[5][1]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][1]][i][0] = cube[box[5][2]][i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][2]][i][0] = cube[box[5][3]][2 - i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][3]][2 - i][2] = tmp[i];
                    }

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[4][i][j] = tmp2[index++];
                        }
                    }
                }
                break;
            case 'R':
                for (int i = 0; i < 3; ++i)
                {
                    tmp2 += cube[5][i];
                }
                if (dir == '+')
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        tmp += cube[box[5][0]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][0]][i][2] = cube[box[5][1]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][1]][i][2] = cube[box[5][2]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][2]][i][2] = cube[box[5][3]][2 - i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[5][3]][2 - i][0] = tmp[i];
                    }
                   

                    for(int j = 2; j >= 0; --j)
                    {
                        for (int i = 0; i < 3; ++i)
                        {
                            cube[5][i][j] = tmp2[index++];
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 3; ++i)
                    {
                        tmp += cube[box[4][0]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][0]][i][2] = cube[box[4][1]][2 - i][0];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][1]][i][0] = cube[box[4][2]][2 - i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][2]][i][2] = cube[box[4][3]][i][2];
                    }
                    for (int i = 0; i < 3; ++i)
                    {
                        cube[box[4][3]][i][2] = tmp[i];
                    }

                    for (int j = 0; j < 3; ++j)
                    {
                        for (int i = 2; i >= 0; --i)
                        {
                            cube[5][i][j] = tmp2[index++];
                        }
                    }
                }
                break;

            default:
                break;
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            cout << cube[0][i] << "\n";
        }
    }
    return 0;
}