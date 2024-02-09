#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
struct Player {
    int weapon = 0;
    int armor = 0;
    map <string, bool> accessories;
    int acNum = 0;

    int maxHp = 20;
    int maxExp = 5;
    int hp = 20;
    int exp = 0;
    int def = 2;
    int atk = 2;
    int level = 1;
};
struct Monster {
    string name;
    int atk;
    int def;
    int hp;
    int expReward;
};
struct Item {
    char t;
    int n;
    string ac;
};
int N, M;
string GRID[100];
string COMMAND;
Player player;
Monster monsters[100][100];
Item items[100][100];
int MOSTERNUM;
int ITEMBOXNUM;
int SX, SY;
int playerY, playerX;
string GameExitMsg;
bool GameClear= false;
bool IsDead = false;

//HR : 전투 승리시 체력 3, 최대 체력 고려
//RE : 사망 시 소멸, 최대체력으로 부활, 첫 시작 위치로 돌려보냄
//CO : 모든 전투에서, 첫 공격이 주인공의 공격력(atk + weapon) * 2 로 적용, max(1, 공격력*2 - 몬스터DEF)
//EX : 얻는 경험지 1.2, 소수점 버림
//DX : 가시 함정에 입는 데미지가 1 로 고정 , CO가 세배로 적용
//HU : 보스 전투 돌입 시, 체력 최대 첫 공격에 피가 달지 않음
//CU : 무능력

void DX()
{
    if (player.accessories["DX"])
    {
        player.hp -= 1;
    }
    else
    {
        player.hp -= 5;
    }
}

void HR()
{
    if (!player.accessories["HR"])
        return;
    int nh = player.hp + 3;
    if (nh > player.maxHp)
    {
        nh = player.maxHp;
    }
    player.hp = nh;
}

void RE()
{
    player.accessories["RE"] = 0;
    player.acNum -= 1;
    player.hp = player.maxHp;
    playerY = SY;
    playerX = SX;
}

void GetExp(int exp)
{
    int r = player.exp;
    if (player.accessories["EX"] > 0)
    {
        r += float(exp) * 1.2;
    }
    else
    {
        r += exp;
    }
    if (r >= player.maxExp)
    {
        player.exp = 0;
        player.level++;
        player.maxHp += 5;
        player.maxExp += 5;
        player.atk += 2;
        player.def += 2;
        player.hp = player.maxHp;
    }
    else
    {
        player.exp = r;
    }
}

void PrintResult(int turn)
{
    for (int i = 0; i < N; ++i)
    {
        cout << GRID[i] << "\n";
    }
    cout << "Passed Turns : " << turn << "\n";
    cout << "LV : " << player.level << "\n";
    cout << "HP : " << player.hp << "/" << player.maxHp << "\n";
    cout << "ATT : " << player.atk << "+" << player.weapon << "\n";
    cout << "DEF : " << player.def << "+" << player.armor << "\n";
    cout << "EXP : " << player.exp << "/" << player.maxExp << "\n";
    cout << GameExitMsg;
} 

void Game()
{
    int i = 0;
    for (i = 0; i < COMMAND.size(); ++i)
    {
        if (GameClear)break;
        if (IsDead) break;
        char currCMD = COMMAND[i];
        int y = playerY;
        int x = playerX;
        if(currCMD == 'U')
            y -= 1;
        else if(currCMD == 'R')
            x += 1;
        else if(currCMD == 'D')
            y += 1;
        else
            x -= 1;
        
        if (y < 0 || x < 0 || y >= N || x >= M || GRID[y][x] == '#')
        {
            y = playerY;
            x = playerX;
        }
        
        if (GRID[y][x] == '.')
        {
            playerY = y;
            playerX = x;
        }
        else if (GRID[y][x] == '^')
        {
            DX();
            if (player.hp <= 0)
            {
                if (player.accessories["RE"])
                {
                    RE();
                }
                else
                {
                    GameExitMsg = "YOU HAVE BEEN KILLED BY SPIKE TRAP..";
                    IsDead = true;
                }
            }
            else
            {
                playerY = y;
                playerX = x;
            }
        }
        else if (GRID[y][x] == 'B')
        {
            if (items[y][x].t == 'O')
            {
                //악세서리인 경우
                if (player.acNum < 4 && player.accessories[items[y][x].ac] == false)
                {
                    player.acNum++;
                    player.accessories[items[y][x].ac] = true;
                }
            }
            else if(items[y][x].t == 'A')
            {
                //방어구
                player.armor = items[y][x].n;
                
            }
            else {
                //무기
                player.weapon = items[y][x].n;
            }
            GRID[y][x] = '.';
            playerY = y;
            playerX = x;
        }
        else if (GRID[y][x] == '&')
        {
            //선방
            Monster currMonster = monsters[y][x];
            if (player.accessories["CO"] > 0)
            {
                if (player.accessories["DX"] > 0)
                {
                    //3배
                    currMonster.hp -= max(1, (player.weapon + player.atk) * 3 - currMonster.def);
                }
                else
                {
                    //2배
                    currMonster.hp -= max(1, (player.weapon + player.atk) * 2 - currMonster.def);
                }
            }
            else
            {
                currMonster.hp -= max(1, (player.weapon + player.atk) - currMonster.def);
            }
            if (currMonster.hp <= 0)
            {
                GetExp(currMonster.expReward);
                HR();
                GRID[y][x] = '.';
                playerY = y;
                playerX = x;
            }
            else
            {
                while (true)
                {
                    player.hp -= max(1, currMonster.atk - (player.armor + player.def));
                    if (player.hp <= 0)
                    {
                        player.hp = 0;
                        if (player.accessories["RE"])
                        {
                            RE();
                        }
                        else
                        {
                            GameExitMsg = "YOU HAVE BEEN KILLED BY " + currMonster.name + "..";
                            IsDead = true;
                        }
                        break;
                    }
                    currMonster.hp -= max(1, (player.weapon + player.atk) - currMonster.def);
                    if (currMonster.hp <= 0)
                    {
                        GetExp(currMonster.expReward);
                        HR();
                        GRID[y][x] = '.';
                        playerY = y;
                        playerX = x;
                        break;
                    }
                }
            }
        }
        else
        {
            Monster boss = monsters[y][x];
            bool shield = false;
            if (player.accessories["HU"])
            {
                player.hp = player.maxHp;
                shield = true;
            }
            if (player.accessories["CO"] > 0)
            {
                if (player.accessories["DX"] > 0)
                {
                    //3배
                    boss.hp -= max(1, (player.weapon + player.atk) * 3 - boss.def);
                }
                else
                {
                    //2배
                    boss.hp -= max(1, (player.weapon + player.atk) * 2 - boss.def);
                }
            }
            else
            {
                boss.hp -= max(1, (player.weapon + player.atk) - boss.def);
            }
            if (boss.hp <= 0)
            {
                GetExp(boss.expReward);
                HR();
                GRID[y][x] = '.';
                playerY = y;
                playerX = x;
                GameExitMsg = "YOU WIN!";
                GameClear = true;
            }
            else
            {
                while (true)
                {
                    if (shield)
                    {
                        shield = false;
                    }
                    else
                    {
                        player.hp -= max(1, boss.atk - (player.armor + player.def));
                        if (player.hp <= 0)
                        {
                            player.hp = 0;
                            if (player.accessories["RE"])
                            {
                                RE();
                            }
                            else
                            {
                                GameExitMsg = "YOU HAVE BEEN KILLED BY " + boss.name + "..";
                                IsDead = true;
                            }
                            break;
                        }
                    }
                    boss.hp -= max(1, (player.weapon + player.atk) - boss.def);
                    if (boss.hp <= 0)
                    {
                        GetExp(boss.expReward);
                        HR();
                        GRID[y][x] = '.';
                        playerY = y;
                        playerX = x;
                        GameExitMsg = "YOU WIN!";
                        GameClear = true;
                        break;
                    }
                }
            }
        }
    }
    if (GameExitMsg == "")
    {
        GameExitMsg = "Press any key to continue.";
        GRID[playerY][playerX] = '@';
        PrintResult(i);
    }
    else
    {
        if (GameClear)
        {
            GRID[playerY][playerX] = '@';
        }
        PrintResult(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> GRID[i];
        for (int j = 0; j < M; ++j)
        {
            if (GRID[i][j] == 'B')
            {
                ITEMBOXNUM++;
            }
            else if (GRID[i][j] == '&' || GRID[i][j] == 'M')
            {
                MOSTERNUM++;
            }
            else if (GRID[i][j] == '@')
            {
                playerY = i;
                playerX = j;
                SY = i;
                SX = j;
                GRID[i][j] = '.';
            }
        }
    }
    cin >> COMMAND;
    for (int i = 0; i < MOSTERNUM; ++i)
    {
        int y, x, a, b, c, d;
        string name;
        cin >> y >> x >> name >> a >> b >> c >> d;
        monsters[y - 1][x - 1] = { name, a, b, c, d };
    }
    for (int i = 0; i < ITEMBOXNUM; ++i)
    {
        int y, x;
        char t;
        cin >> y >> x >> t;
        if (t == 'O')
        {
            string a;
            cin >> a;
            items[y - 1][x - 1] = {t, 0, a};
        }
        else
        {
            int a;
            cin >> a;
            items[y - 1][x - 1] = {t, a, ""};
        }
    }
    
    Game();

    return 0;
}