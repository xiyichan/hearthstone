#include "All.h"
using namespace std;
//选择玩家
//玩家选择牌库
//开始
//载入牌库
//弃牌库
//战场
//手牌
void Game()
{
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

    vector<Follower *> aPlayerLibrary; //a的牌库
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

    vector<Follower *> bPlayerLibrary; //b的牌库
    string bpath = to_string(bPlayerID) + "Player";
    getAllFileNames(bpath);
    string bdir;
    cout << "input your card library name:" << endl;
    cin >> bdir;
    bdir = bpath + "\\" + bdir + ".txt";
    JudgeProfession(bdir, bRole);
    cout << bRole.GetRoleProfession() << endl;
    ReadFollowerLibrary(bPlayerLibrary, bdir);

    //开始比赛

    //   Follower aBattlefield[7];             //a的战场
    // Follower bBattlefield[7];             //b的战场
    vector<Follower *> aBattlefiled;
    vector<Follower *> bBattlefiled;
    vector<Follower *> aHand;             //a的手牌
    vector<Follower *> bHand;             //b的手牌
    vector<Follower *> aThrowHandLibrary; //a的弃牌库
    vector<Follower *> bThrowHandLibrary; //b的弃牌库

    int i = 0;
    for (vector<Follower *>::iterator v = aPlayerLibrary.begin(); v != aPlayerLibrary.end(); v++)
    {
        // aBattlefield[0]=*(*v);
        aHand.push_back(*v);
        i++;
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
        if (i == 4)
            break;
    }

    int huihe = 0, aStatusl = 0, bStatusl = 0;
    while (aRole.GetRoleHealth() <= 0 && bRole.GetRoleHealth() <= 0)
    {
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
        cout << "ahand" << endl;
        ShowFollowerLibrary(aHand);
        cout << "aBattlefield" << endl;
        ShowFollowerLibrary(aBattlefiled);
        cout << "bBattlefiled" << endl;
        ShowFollowerLibrary(bBattlefiled);
        ShowRole(aRole);
        char achoose = '1';
        while (achoose != '0')
        {
            do
            {
                cout << "1.call Follower" << endl;
                cout<<"0.end"<<endl;
                cout << "achoose:" << endl;
                cin >> achoose;
                fflush(stdin);
            } while (!(achoose >= '0'));
            if (achoose == '1')
            {
                CallFollower(aHand, aBattlefiled, aRole);
                // ShowFollowerLibrary(aBattlefiled);
                //system("pause");
            }
        }
        char bchoose = '1';
        while (bchoose != '0')
        {
            do
            {
                cout << "call Follower" << endl;
                cout << "bchoose:" << endl;
                cin >> achoose;
                fflush(stdin);
            } while (!(bchoose >= '0'));
            if (bchoose == '1')
            {
                if (bHand.size() > 0)
                {

                    CallFollower(bHand, bBattlefiled, bRole);
                }
                // ShowFollowerLibrary(aBattlefiled);
                //system("pause");
                else
                {
                    cout << "hand no card" << endl;
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
            if ((*v)->GetFollowerStatus() <= role.GetRoleStatusl())
            {
                ShowFollowerLibrary(Battelefield);
                cout << Battelefield.size() << endl;
                if (Battelefield.size() == 0)
                {
                    Battelefield.push_back(*v);
                }
                else
                {
                    cout << "fang zai na ge wei zhi " << endl;
                    int where;
                    cin >> where;
                    Battelefield.insert(Battelefield.begin() + where, (*v));
                }
                cout << "success" << endl;
               // Statusl = Statusl - (*v)->GetFollowerStatus();
               role.SetRoleStatusl(role.GetRoleStatusl()-(*v)->GetFollowerStatus());
                Hand.erase(v);
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

void AttackFollower(vector<Follower *> &aBattelefield, vector<Follower *> &bBattlefield)
{
}
void AttackRole(vector<Follower *> &Battelefield, Role &role)
{
}

void DrawCard(vector<Follower *> &Hand, vector<Follower *> &PlayerCardLibrary)
{
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

            if ((*v)->GetRoleProfession() == 2)
            {
                role = *(*v);
                break;
            }
    }
}
