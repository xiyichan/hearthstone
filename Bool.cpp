#include"Follower.h"
#include"Player.h"
#include"Role.h"
bool BoolFollowerID(Follower *f, int FollowerID) {
	if (f->GetFollowerID() == FollowerID)
		return true;
	else {
		return false;
	}
}

bool BoolPlayerID(Player *p, int PlayerID) {
	if (p->GetPlayerID() == PlayerID)
		return true;
	else {
		return false;
	}
}

bool BoolRoleID(Role *r, int RoleID) {
	if (r->GetRoleID()==RoleID)
		return true;
	else {
		return false;
	}
}