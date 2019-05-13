#ifndef GAME_H
#define GAME_H


void Game();
void JudgeProfession(string path, Role &role);
void CallFollower(vector<Follower *> &Hand, vector<Follower *> &Battelefield, Role &role);
void AttackFollower(vector<Follower *> &zhuBattelefield, vector<Follower *> &beiBattlefield, vector<Follower *> &zhuThrowLibrary, vector<Follower *> &beiThrowLibrary);
void AttackRole(vector<Follower *> &Battelefield, Role &role);
void DrawCard(vector<Follower *> & Hand, vector<Follower *> & PlayerCardLibrary);
bool judgeRoleHealth(Role &aRole, Role &bRole, Player &aPlayer, Player &bPlayer,vector<Player *>PlayerLibrary);
#endif