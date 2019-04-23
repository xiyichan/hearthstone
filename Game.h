#ifndef GAME_H
#define GAME_H


void Game();
void JudgeProfession(string path, Role &role);
void CallFollower(vector<Follower *> &Hand, vector<Follower *> &Battelefield, Role &role);
void AttackFollower(vector<Follower *> &aBattelefield, vector<Follower *> &bBattlefield);
void AttackRole(vector<Follower *> &Battelefield, Role &role);
#endif