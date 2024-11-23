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
// 빨 파 초 가 붙어있는 형태
//x가 행, y가 열
//블록은 타일이 12  21 1
//블록을 놓을 위치를 빨강에서 선택하면 초록색 보드로 이동, 파란색보드로 이동
//
int blue[6][4];
int green[6][4];
int score = 0;
int T;
void printBlue();
void printGreen();
void eraseBlock() {
    int endcheck = 0;
    for (int i = 0; i < 6; ++i) {
        if (blue[i][0] && blue[i][1] && blue[i][2] && blue[i][3]) {
            blue[i][0] = 0;
            blue[i][1] = 0;
            blue[i][2] = 0;
            blue[i][3] = 0;
            score++;
            endcheck = 1;
        }
        if (green[i][0] && green[i][1] && green[i][2] && green[i][3]) {
            green[i][0] = 0;
            green[i][1] = 0;
            green[i][2] = 0;
            green[i][3] = 0;
            score++;
            endcheck = 1;
        }
    }
    
    for (int i = 5; i > 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (blue[i][j]) continue;
            
            int blockType = 0;
            for (int h = i - 1; h >= 0; --h) {
                // 점점 올라가다가 blue가 비었으면.
                if (blue[h][j]) {
                    if (j - 1 >= 0 && blue[h][j - 1] == blue[h][j]) break;
                    if (j + 1 < 4 && blue[h][j + 1] == blue[h][j]) {
                        // 두칸블럭
                        for (int hh = h; hh <= i - 1; ++hh) {
                            if (blue[hh + 1][j + 1]) break;
                            blue[hh + 1][j] = blue[hh][j];
                            blue[hh + 1][j + 1] = blue[hh][j + 1];
                            blue[hh][j] = 0;
                            blue[hh][j + 1] = 0;
                        }
                    }
                    else {
                        // 한칸블럭
                        for (int hh = h; hh <= i - 1; ++hh) {
                            blue[hh + 1][j] = blue[hh][j];
                            blue[hh][j] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }

    for (int i = 5; i > 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (green[i][j]) continue;

            int blockType = 0;
            for (int h = i - 1; h >= 0; --h) {
                if (green[h][j]) {
                    if (j - 1 >= 0 && green[h][j - 1] == green[h][j]) break;
                    if (j + 1 < 4 && green[h][j + 1] == green[h][j]) {
                        // 두칸블럭
                        for (int hh = h; hh <= i - 1; ++hh) {
                            if (green[hh + 1][j + 1]) break;
                            green[hh + 1][j] = green[hh][j];
                            green[hh + 1][j + 1] = green[hh][j + 1];
                            green[hh][j] = 0;
                            green[hh][j + 1] = 0;
                        }
                    }
                    else {
                        // 한칸블럭
                        for (int hh = h; hh <= i - 1; ++hh) {
                            green[hh + 1][j] = green[hh][j];
                            green[hh][j] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
    if (endcheck) {
        eraseBlock();
    }
}
void pushBlock() {
    int bcnt = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (blue[i][j]) {
                bcnt++;
                break;
            }
        }
    }
    for (int q = 0; q < bcnt; ++q) {
        for (int j = 5; j >= 1; --j) {
            blue[j][0] = blue[j - 1][0];
            blue[j][1] = blue[j - 1][1];
            blue[j][2] = blue[j - 1][2];
            blue[j][3] = blue[j - 1][3];
        }
        blue[0][0] = 0;
        blue[0][1] = 0;
        blue[0][2] = 0;
        blue[0][3] = 0;
    }

    int gcnt = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (green[i][j]) {
                gcnt++;
                break;
            }
        }
    }
    for (int q = 0; q < gcnt; ++q) {
        for (int j = 5; j >= 1; --j) {
            green[j][0] = green[j - 1][0];
            green[j][1] = green[j - 1][1];
            green[j][2] = green[j - 1][2];
            green[j][3] = green[j - 1][3];
        }
        green[0][0] = 0;
        green[0][1] = 0;
        green[0][2] = 0;
        green[0][3] = 0;
    }
}
void moveBlock(int a, int b, int c, int num) {
    if (a == 1) {
        //b
        //i, b
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                blue[k - 1][b] = num;
                break;
            }
            if (blue[k][b] == 0) continue;
            blue[k - 1][b] = num;
            break;
        }
        //g
        //i, c
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                green[k - 1][c] = num;
                break;
            }
            if (green[k][c] == 0) continue;
            green[k - 1][c] = num;
            break;
        }
    }
    else if (a == 2) {
        //b
        //i, b
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                blue[k - 1][b] = num;
                blue[k - 2][b] = num;
                break;
            }
            if (blue[k][b] == 0) continue;
            blue[k - 1][b] = num;
            blue[k - 2][b] = num;
            break;
        }
        //g
        //i, c, c + 1
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                green[k - 1][c] = num;
                green[k - 1][c + 1] = num;
                break;
            }
            if (green[k][c] == 0 && green[k][c + 1] == 0) continue;
            green[k - 1][c] = num;
            green[k - 1][c + 1] = num;
            break;
        }
    }
    else {
        //b
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                blue[k - 1][b] = num;
                blue[k - 1][b + 1] = num;
                break;
            }
            if (blue[k][b] == 0 && blue[k][b + 1] == 0) continue;
            blue[k - 1][b] = num;
            blue[k - 1][b + 1] = num;
            break;
        }
        //g
        for (int k = 0; k < 7; ++k) {
            if (k == 6) {
                green[k - 1][c] = num;
                green[k - 2][c] = num;
                break;
            }
            if (green[k][c] == 0) continue;
            green[k - 1][c] = num;
            green[k - 2][c] = num;
            break;
        }
    }
}
void printGreen() {
    cout << "\nGreen\n";
    for (int q = 0; q < 6; ++q) {
        for (int p = 0; p < 4; ++p) {
            cout << green[q][p] << " ";
        }
        cout << "\n";
    }
}
void printBlue() {
    cout << "\nBlue!\n";
    for (int q = 0; q < 6; ++q) {
        for (int p = 0; p < 4; ++p) {
            cout << blue[q][p] << " ";
        }
        cout << "\n";
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        moveBlock(a, b, c, i + 1);
        eraseBlock();
        pushBlock();
        //cout << "######" << i + 1 << "\n";
        //printGreen();
        //printBlue();
    }
    int ret = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (green[i][j]) ret++;
            if (blue[i][j]) ret++;
        }
    }
    cout << score << "\n" << ret;
    return 0;
}