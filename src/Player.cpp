#include "Player.h"

bool Player::trade(int change)
{
	if(money_ + change < 0)
		return false;

	money_ += change;
	return true;
}
