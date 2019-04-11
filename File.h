#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<vector>
#include"Follower.h"
#include"Player.h"
#include"Role.h"
void WriteFollowerLibrary(vector<Follower *>::iterator v,string path);
void ReadFollowerLibrary(vector<Follower *> &FollowerLibrary,string path);

void WritePlayerLibrary(vector<Player *>::iterator v);
void ReadPlayerLibrary(vector<Player *> &PlayerLibrary);

void WriteRoleLibrary(vector <Role*>::iterator v);
void ReadRoleLibrary(vector<Role *> &RoleLibrary);

void  WriteFollowerID(int &FollowerID);
void ReadFollowerID(int &FollowerID);

void  WritePlayerID(int &PlayerID);
void ReadPlayerID(int &PlayerID);

void WriteRoleID(int &RoleID);
void ReadRoleID(int &RoleID);

void getAllFileNames(const string& folder_path);
#endif // !FILE_H
