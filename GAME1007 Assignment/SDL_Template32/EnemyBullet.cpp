#include <Enemybullet.h>

class Enemy;

class EnemyState
{
public:
	
	virtual void update(Enemy* enemy) = 0;
};

class EnemyStateIdle :public EnemyState
{
	//...stuff...
	void update(Enemy* enemy)
	{
		//do nothing
	}
};

class EnemyStateAttack : public EnemyState
{
private:

public:
	
	void update(Enemy* enemy)
	{
		enemy->shoot();
	}
};

class Enemy
{
private:
	Vector3 position;
	Vector3 direction;
	EnemyState* state;
	static std::set<Enemy*> enemies;

private:
	static EnemyStateIdle idleState;
	static EnemyStateAttack attackState;
public:

	void shoot()
	{
		//offset so the bullet won't appear in the enemy's center
		double offset;
		Bullet* temp = new Bullet(position + offset * direction, direction);
		//...stuff...
	}

	void think()
	{
		//if player in range
		if (state == &idleState)
		{
			state = &attackState;
		}
		//if player is out of range
		if (state == &attackState)
		{
			state = &idleState;
		}
	}