#include "All.h"
//选择玩家
//玩家选择牌库
//开始
//载入牌库
//弃牌库
//战场
//手牌
void Game()
{
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
                cout << "a.ok" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << "no player,input again" << endl;
    }

    vector<Follower *> aPlayerLibrary;//a的牌库
    string apath = to_string(aPlayerID) + "Player";
    getAllFileNames(apath);
    string adir;
    cout << "input your card library name:" << endl;
    cin >> adir;
    adir = apath + "\\" + adir + ".txt";
    ReadFollowerLibrary(aPlayerLibrary, adir);

    while (flag)
    {
        cout << "input bPlayer ID" << endl;
        cin >> bPlayerID;
        for (vector<Player *>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++)
        {
            if ((*v)->GetPlayerID() == bPlayerID)
            {
                cout << "b.ok" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << "no player,input again" << endl;
    }

    vector<Follower *> bPlayerLibrary;//b的牌库
    string bpath = to_string(bPlayerID) + "Player";
    getAllFileNames(bpath);
    string bdir;
    cout << "input your card library name:" << endl;
    cin >> bdir;
    bdir = bpath + "\\" + bdir + ".txt";
    ReadFollowerLibrary(aPlayerLibrary, adir);

    //开始比赛

    Follower aBattlefield[7];//a的战场
    Follower bBattlefield[7];//b的战场
    vector<Follower *>aHand;//a的手牌
    vector<Follower *>bHand;//b的手牌
    vector<Follower*>aThrowHandLibrary;//a的弃牌库
    vector<Follower*>bThrowHandLibrary;//b的弃牌库

    



}