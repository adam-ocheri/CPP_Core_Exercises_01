#include "Player.h"

Player::Player()
{
	Health = new int(100);
}

void Player::Attack(Player& EnemyPlayer)
{
	this->ApplyDamage(EnemyPlayer, Power);
}
