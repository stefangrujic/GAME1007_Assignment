#ifndef _LEVEL_H
#define _LEVEL_H

#include"Ship.h"
#include"Enemy.h"

using namespace std;

class Level : GameEntity
{
public:
	enum Level_States {Running, finished, gameover };
	
private:
	Timer* mTimer;

	int mStage;
	bool mStageStarted;

	float mLabelTimer;

	Texture* mStageLabel;
	ScoreBoard* mStageNumber;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Player* mPlayer;
	bool mPlayerHit;
	float mPlayerRespawnDelay;
	float mPlayerRespawnTimer;
	float mPlayerRespawnLabelOnScreen;

	Texture* mGameOverLabel;
	bool mGameOver;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;

	Level_STATES mCurrentState;

	Formation* mFormation;

	bool mChallengeStage;

	static const int Max_Enemies = 5;
	int mEnemyCount;

	static const int Max_Boss = 1;
	int mBossCount;

	Enemy* mEnemies[Max_Enemies];
	Boss* mBoss[Max_Boss];

	vector<Enemy*> mEnemies;

	XMLDocument mSpawningPatterns;
	int mCurrentFlyInPriority;
	int mCurrentFlyInIndex;

	bool mSpawningFinished;
	float mSpawnDelay;
	float mSpawnTimer;

	Boss* mDivingBoss;
	bool mCaptureDive;
	bool mSkipFirstBoss;
	float mBossDiveDelay;
	float mBossDiveTimer;

private:
	void StartStage();
	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();

	bool EnemyFlyingIn();

	void HandleEnemySpawning();
	void HandleEnemyFormation();
	void HandleEnemyDiving();

public:
	Level(int stage, PlaySideBar* sideBar, Player* player);
	~Level();

	LEVEL_STATES State();

	void Update();
	void Render();
};


};
#endif 

