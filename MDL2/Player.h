#pragma once

class Player
{
	
private:
	int* Health;
	int Power;

public:
	/*
		- ConstructNewPlayer (init)
			+ ()
			+ (int initHealth)
			+ (int initHealth, int initPower)
			+ (const Player& other)

		- DestroyExisitingPlayer (clean)
	*/

	// Instance Control
	Player();

	// Public Interface
	void Attack(Player& EnemyPlayer);
	void ApplyDamage(Player& EnemyPlayer, int DamageAmount);
	void OnDamageRecieved(int DamageAmount);

	Player& operator-(Player& EnemyPlayer);
};

