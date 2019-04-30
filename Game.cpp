#include "All.h"
using namespace std;
//选择玩家
//玩家选择牌库
//开�??
//载入牌库
//弃牌�??
//战场
//手牌
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

    vector<Follower *> aPlayerLibrary; //a的牌�??
    string apath = to_string(aPlayerID) + "Player";
    getAllFileNames(apath);
    string adir;
    cout << "input your card library name:" << endl;
    cin >> adir; //路径包括职业

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

    vector<Follower *> bPlayerLibrary; //b的牌�??
    string bpath = to_string(bPlayerID) + "Player";
    getAllFileNames(bpath);
    string bdir;
    cout << "input your card library name:" << endl;
    cin >> bdir;
    bdir = bpath + "\\" + bdir + ".txt";
    JudgeProfession(bdir, bRole);
    cout << bRole.GetRoleProfession() << endl;
    ReadFollowerLibrary(bPlayerLibrary, bdir);

    //开始比�??

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
        DrawCard(aHand, aPlayerLibrary); //�鿨
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
                cout << "1.�ٻ����" << endl;
                cout << "2.ѡ��һ����ӹ����з����" << endl;
                cout << "3.ѡ��һ����ӹ����з���ɫ" << endl;

                cout << "0.��������غ�" << endl;
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
                    cout << "û������" << endl;
                }
            }
            else if (achoose == '2')
            {
                system("cls");
                if (aBattlefiled.size() > 0 && bBattlefiled.size() > 0)
                    AttackFollower(aBattlefiled, bBattlefiled, aThrowHandLibrary, bThrowHandLibrary);
                else
                {
                    cout << "û�����" << endl;
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
                    cout << "û�����" << endl;
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
        DrawCard(bHand, bPlayerLibrary); //�鿨
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
                cout << "1.�ٻ����" << endl;
                cout << "2.ѡ��һ����ӹ����з����" << endl;
                cout << "3.ѡ��һ����ӹ����з���ɫ" << endl;

                cout << "0.��������غ�" << endl;
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
                    cout << "û�����" << endl;
                }
            }
            else if (achoose == '2')
            {
                system("cls");
                if (aBattlefiled.size() > 0 && bBattlefiled.size() > 0)
                    AttackFollower(bBattlefiled, aBattlefiled, bThrowHandLibrary, aThrowHandLibrary);
                else
                {
                    cout << "û�����" << endl;
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
                    cout << "û�����" << endl;
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
                    cout << "ѡ��λ��" << endl;
                    int where;
                    cin >> where;
                    Battelefield.insert(Battelefield.begin() + where, (*v));
                }
                cout << "�ٻ��ɹ�" << endl;
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
    cout << "�ҷ�ս��" << endl;
    ShowFollowerLibrary(beiBattlefield);
    cout << "�з�ս��" << endl;
    ShowFollowerLibrary(zhuBattelefield);
    int i, j;
    cout << "ѡ���ҷ�һ����ӣ�λ��" << endl;
    cin >> i;
    vector<Follower *>::iterator v;
    vector<Follower *>::iterator f;
    for (v = zhuBattelefield.begin(); v != zhuBattelefield.end(); v++)
    {
        if (i == vcount && (*v)->GetFollowerStatus() == 1)
        {
            cout << "ѡ��з�һ�����" << endl;
            cin >> j;
            for (f = beiBattlefield.begin(); f != beiBattlefield.end(); f++) ///////////////////写什么时候可以攻�??
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
                    cout << "�ҷ�ս��" << endl;
                    ShowFollowerLibrary(beiBattlefield);
                    cout << "�з�ս��" << endl;
                    ShowFollowerLibrary(zhuBattelefield);
                    break;
                }
                fcount++;
            }
            break;
        }
        else{
        vcount++;
        cout<<"������޷�����"<<endl;
        }
    }
}
void AttackRole(vector<Follower *> &Battelefield, Role &role)
{
    int count = 1;
    cout << "�ҷ�ս��" << endl;
    ShowFollowerLibrary(Battelefield);
    int i;
    cout << "ѡ��һ�����" << endl;
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
            cout<<"������޷�����"<<endl;
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
        cout << "��������," << bPlayer.GetPlayerName() << "ʤ��" << endl;
        return true;
    }
    else if (bRole.GetRoleHealth() <= 0)
    {
        aPlayer.SetPlayerVictory(aPlayer.GetPlayerVictory() + 1);
        bPlayer.SetPlayerDefeat(bPlayer.GetPlayerDefeat() + 1);
        cout << "��������," << aPlayer.GetPlayerName() << "ʤ��" << endl;
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
