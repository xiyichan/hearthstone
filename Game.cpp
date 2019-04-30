#include "All.h"
using namespace std;
//閫夋嫨鐜╁
//鐜╁閫夋嫨鐗屽簱
//寮�锟??
//杞藉叆鐗屽簱
//寮冪墝锟??
//鎴樺満
//鎵嬬墝
void Game()
{
    bool GameOver = false;
    //vector<Role *> RoleLibrary;
    Role aRole, bRole;
    Player aPlayer, bPlayer;
    int aPlayerID, bPlayerID;
    vector<Player *> PlayerLibrary;
    ReadPlayerLibrary(PlayerLibrary);
    bool flag = true;
    while (flag)
    {
        cout << "input aPlayer ID" << endl;
        cin >> aPlayerID;
        for (vector<Player *>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++)
        {
            if ((*v)->GetPlayerID() == aPlayerID)
            {
                aPlayer = *(*v);
                cout << "a.ok" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << "no player,input again" << endl;
    }

    vector<Follower *> aPlayerLibrary; //a鐨勭墝锟??
    string apath = to_string(aPlayerID) + "Player";
    getAllFileNames(apath);
    string adir;
    cout << "input your card library name:" << endl;
    cin >> adir; //璺緞鍖呮嫭鑱屼笟

    adir = apath + "\\" + adir + ".txt";
    JudgeProfession(adir, aRole);
    cout << aRole.GetRoleProfession() << endl;
    ReadFollowerLibrary(aPlayerLibrary, adir);

    flag = true;
    while (flag)
    {
        cout << "input bPlayer ID" << endl;
        cin >> bPlayerID;
        for (vector<Player *>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++)
        {
            if ((*v)->GetPlayerID() == bPlayerID)
            {
                bPlayer = *(*v);
                cout << "b.ok" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << "no player,input again" << endl;
    }

    vector<Follower *> bPlayerLibrary; //b鐨勭墝锟??
    string bpath = to_string(bPlayerID) + "Player";
    getAllFileNames(bpath);
    string bdir;
    cout << "input your card library name:" << endl;
    cin >> bdir;
    bdir = bpath + "\\" + bdir + ".txt";
    JudgeProfession(bdir, bRole);
    cout << bRole.GetRoleProfession() << endl;
    ReadFollowerLibrary(bPlayerLibrary, bdir);

    //寮�濮嬫瘮锟??

    //   Follower aBattlefield[7];
    // Follower bBattlefield[7];
    vector<Follower *> aBattlefiled;
    vector<Follower *> bBattlefiled;
    vector<Follower *> aHand;
    vector<Follower *> bHand;
    vector<Follower *> aThrowHandLibrary;
    vector<Follower *> bThrowHandLibrary;

    int i = 0;
    for (vector<Follower *>::iterator v = aPlayerLibrary.begin(); v != aPlayerLibrary.end(); v++)
    {
        // aBattlefield[0]=*(*v);

        aHand.push_back(*v);
        i++;
        aPlayerLibrary.erase(v);
        if (i == 3)
            break;
    }
    // vector<Follower *>::iterator a = aHand.begin();
    //aHand.insert(a,&aBattlefield[0]);
    //ShowFollowerLibrary(aHand);
    //system("pause");
    i = 0;
    for (vector<Follower *>::iterator v = bPlayerLibrary.begin(); v != bPlayerLibrary.end(); v++)
    {
        //bBattlefield[1]=*(*v);
        //cout<<bBattlefield[1].GetFollowerID()<<endl;

        bHand.push_back(*v);
        i++;
        bPlayerLibrary.erase(v);
        if (i == 4)
            break;
    }

    int huihe = 0, aStatusl = 0, bStatusl = 0;
    while (true)
    {
        if (GameOver)
        {
            break;
        }

        huihe++;
        if (aStatusl < 10)
        {
            aStatusl++;
            aRole.SetRoleStatusl(aStatusl);
        }
        else
        {
            aRole.SetRoleStatusl(10);
        }

        cout << "time to a" << endl;
        DrawCard(aHand, aPlayerLibrary); //抽卡
        cout << "bBattlefiled" << endl;
        ShowFollowerLibrary(bBattlefiled);
        cout << "aBattlefield" << endl;
        ShowFollowerLibrary(aBattlefiled);
        cout << "ahand" << endl;
        ShowFollowerLibrary(aHand);
        for (vector<Follower *>::iterator c = aBattlefiled.begin(); c != aBattlefiled.end(); c++)
        {
            (*c)->SetFollowerStatus(1);
        }
        ShowRole(aRole);
        char achoose = '1';
        while (achoose != '0')
        {
            if (GameOver)
            {
                break;
            }
            do
            {
                if (GameOver)
                {
                    break;
                }
                cout << "1.召唤随从" << endl;
                cout << "2.选择一个随从攻击敌方随从" << endl;
                cout << "3.选择一个随从攻击敌方角色" << endl;

                cout << "0.结束这个回合" << endl;
                cout << "achoose:" << endl;
                cin >> achoose;
                fflush(stdin);
            } while (!(achoose >= '0'));
            if (achoose == '1')
            {
                if (aHand.size() > 0)
                {
                    CallFollower(aHand, aBattlefiled, aRole);
                }
                else
                {
                    cout << "没有手牌" << endl;
                }
            }
            else if (achoose == '2')
            {
                system("cls");
                if (aBattlefiled.size() > 0 && bBattlefiled.size() > 0)
                    AttackFollower(aBattlefiled, bBattlefiled, aThrowHandLibrary, bThrowHandLibrary);
                else
                {
                    cout << "没有随从" << endl;
                }
            }
            else if (achoose == '3')
            {
                system("cls");
                if (aBattlefiled.size() > 0)
                {
                    AttackRole(aBattlefiled, bRole);
                    GameOver = judgeRoleHealth(aRole, bRole, aPlayer, bPlayer);
                }
                else
                {
                    cout << "没有随从" << endl;
                }
            }
        }
if (GameOver)
                {
                    break;
                }
        if (bStatusl < 10)
        {
            bStatusl++;
            bRole.SetRoleStatusl(bStatusl);
        }
        else
        {
            bRole.SetRoleStatusl(10);
        }
        cout << "time to b" << endl;
        DrawCard(bHand, bPlayerLibrary); //抽卡
        cout << "aBattlefield" << endl;
        ShowFollowerLibrary(aBattlefiled);
        cout << "bBattlefiled" << endl;
        ShowFollowerLibrary(bBattlefiled);
        cout << "bhand" << endl;
        ShowFollowerLibrary(bHand);
        for (vector<Follower *>::iterator c = bBattlefiled.begin(); c != bBattlefiled.end(); c++)
        {
            (*c)->SetFollowerStatus(1);
        }
        ShowRole(bRole);

        char bchoose = '1';
        while (bchoose != '0')
        {
            if (GameOver)
            {
                break;
            }
            do
            {
                if (GameOver)
                {
                    break;
                }
                cout << "1.召唤随从" << endl;
                cout << "2.选择一个随从攻击敌方随从" << endl;
                cout << "3.选择一个随从攻击敌方角色" << endl;

                cout << "0.结束这个回合" << endl;
                cout << "bchoose:" << endl;
                cin >> bchoose;
                fflush(stdin);
            } while (!(bchoose >= '0'));
            if (bchoose == '1')
            {
                if (bHand.size() > 0)
                {
                    CallFollower(bHand, bBattlefiled, bRole);
                }
                else
                {
                    cout << "没有随从" << endl;
                }
            }
            else if (achoose == '2')
            {
                system("cls");
                if (aBattlefiled.size() > 0 && bBattlefiled.size() > 0)
                    AttackFollower(bBattlefiled, aBattlefiled, bThrowHandLibrary, aThrowHandLibrary);
                else
                {
                    cout << "没有随从" << endl;
                }
            }
            else if (achoose == '3')
            {
                system("cls");
                if (aBattlefiled.size() > 0)
                {
                    AttackRole(bBattlefiled, aRole);
                    GameOver = judgeRoleHealth(aRole, bRole, aPlayer, bPlayer);
                }
                else
                {
                    cout << "没有随从" << endl;
                }
            }
        }
    }
}

void CallFollower(vector<Follower *> &Hand, vector<Follower *> &Battelefield, Role &role)
{
    //int Statusl = role.GetRoleStatusl();
    ShowFollowerLibrary(Hand);
    cout << "Statusl:" << role.GetRoleStatusl() << endl;
    cout << "choose a follower:" << endl;
    int id = 0;
    cin >> id;
    vector<Follower *>::iterator vb = Battelefield.begin();
    for (vector<Follower *>::iterator v = Hand.begin(); v != Hand.end(); v++)
    {
        if (id == (*v)->GetFollowerID())
        {
            if ((*v)->GetFollowCostcystal() <= role.GetRoleStatusl())
            {

                // cout << Battelefield.size() << endl;
                if (Battelefield.size() == 0)
                {
                    Battelefield.push_back(*v);
                }
                else
                {
                    cout << "选择位置" << endl;
                    int where;
                    cin >> where;
                    Battelefield.insert(Battelefield.begin() + where, (*v));
                }
                cout << "召唤成功" << endl;
                // Statusl = Statusl - (*v)->GetFollowerStatus();
                role.SetRoleStatusl(role.GetRoleStatusl() - (*v)->GetFollowCostcystal());
                Hand.erase(v);
                cout << endl
                     << "aBattelefield" << endl;
                ShowFollowerLibrary(Battelefield);
                // cout << endl<<"hand" << endl;

                break;
            }
            else
            {
                cout << "no enough Statusl" << endl;
                break;
            }
        }
        else
        {
            cout << "no,choose again" << endl;
        }
    }
}

void AttackFollower(vector<Follower *> &zhuBattelefield, vector<Follower *> &beiBattlefield, vector<Follower *> &zhuThrowLibrary, vector<Follower *> &beiThrowLibrary)
{
    int vcount = 1;
    int fcount = 1;
    cout << "我方战场" << endl;
    ShowFollowerLibrary(beiBattlefield);
    cout << "敌方战场" << endl;
    ShowFollowerLibrary(zhuBattelefield);
    int i, j;
    cout << "选择我方一个随从，位置" << endl;
    cin >> i;
    vector<Follower *>::iterator v;
    vector<Follower *>::iterator f;
    for (v = zhuBattelefield.begin(); v != zhuBattelefield.end(); v++)
    {
        if (i == vcount && (*v)->GetFollowerStatus() == 1)
        {
            cout << "选择敌方一个随从" << endl;
            cin >> j;
            for (f = beiBattlefield.begin(); f != beiBattlefield.end(); f++) ///////////////////鍐欎粈涔堟椂鍊欏彲浠ユ敾锟??
            {
                if (j == fcount)
                {
                    (*v)->SetFollowerHealth(((*v)->GetFollowerHealth() - (*f)->GetFollowerAttack()));
                    (*f)->SetFollowerHealth(((*f)->GetFollowerHealth() - (*v)->GetFollowerAttack()));
                    (*v)->SetFollowerStatus(0);
                    if ((*v)->GetFollowerHealth() <= 0)
                    {
                        zhuThrowLibrary.push_back(*v);
                        zhuBattelefield.erase(v);
                    }
                    if ((*f)->GetFollowerHealth() <= 0)
                    {
                        beiBattlefield.push_back(*f);
                        beiBattlefield.erase(f);
                    }
                    cout << "我方战场" << endl;
                    ShowFollowerLibrary(beiBattlefield);
                    cout << "敌方战场" << endl;
                    ShowFollowerLibrary(zhuBattelefield);
                    break;
                }
                fcount++;
            }
            break;
        }
        else{
        vcount++;
        cout<<"该随从无法攻击"<<endl;
        }
    }
}
void AttackRole(vector<Follower *> &Battelefield, Role &role)
{
    int count = 1;
    cout << "我方战场" << endl;
    ShowFollowerLibrary(Battelefield);
    int i;
    cout << "选择一个随从" << endl;
    cin >> i;
    vector<Follower *>::iterator v;
    for (v = Battelefield.begin(); v != Battelefield.end(); v++)
    {
        if (i == count && (*v)->GetFollowerStatus() == 1)
        {
            role.SetRoleHealth(role.GetRoleHealth() - (*v)->GetFollowerAttack());
            (*v)->SetFollowerStatus(0);
            ShowRole(role);
            cout << "attack success" << endl;
            break;
        }
        else{
            count++;
            cout<<"该随从无法攻击"<<endl;
        }
    }
}

void DrawCard(vector<Follower *> &Hand, vector<Follower *> &PlayerCardLibrary)
{
    vector<Follower *>::iterator v = PlayerCardLibrary.begin();
    Hand.push_back(*v);
    PlayerCardLibrary.erase(v);
}

bool judgeRoleHealth(Role &aRole, Role &bRole, Player &aPlayer, Player &bPlayer)
{
    if (aRole.GetRoleHealth() <= 0 && bRole.GetRoleHealth() <= 0)
    {
        return true;
    }
    else if (aRole.GetRoleHealth() <= 0)
    {
        bPlayer.SetPlayerVictory(bPlayer.GetPlayerVictory() + 1);
        aPlayer.SetPlayerDefeat(aPlayer.GetPlayerDefeat() + 1);
        cout << "比赛结束," << bPlayer.GetPlayerName() << "胜利" << endl;
        return true;
    }
    else if (bRole.GetRoleHealth() <= 0)
    {
        aPlayer.SetPlayerVictory(aPlayer.GetPlayerVictory() + 1);
        bPlayer.SetPlayerDefeat(bPlayer.GetPlayerDefeat() + 1);
        cout << "比赛结束," << aPlayer.GetPlayerName() << "胜利" << endl;
        return true;
    }
    return false;
}

void JudgeProfession(string path, Role &role)
{
    vector<Role *> RoleLibrary;
    ReadRoleLibrary(RoleLibrary);

    if (path.find("_Mage") != -1)
    {
        for (vector<Role *>::iterator v = RoleLibrary.begin(); v != RoleLibrary.end(); v++)

            if ((*v)->GetRoleProfession() == 1)
            {
                role = *(*v);
                break;
            }
    }

    else if (path.find("_Hunter") != -1)
    {
        for (vector<Role *>::iterator v = RoleLibrary.begin(); v != RoleLibrary.end(); v++)
        {
            if ((*v)->GetRoleProfession() == 2)
            {
                role = *(*v);
                break;
            }
        }
    }
}
