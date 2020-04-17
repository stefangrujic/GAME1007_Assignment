#include "Level.h"


Level::Level(int stage, PlaySideBar* sideBar, Player* player)
{
	mTimer = Timer::Instance();
	mPlaySideBar = sideBar;
	mPlaySideBar->SetLevel(stage);
	mStars = BackgroundStars::Instance();

	mCurrentState = running;

	mEnemyCount = 0;
	mBossCount = 0;

	string fullPath = SDL_GetBasePath();
	mSpawningPatterns.LoadFile(fullPath.c_str());

	mChallengeStage = mSpawningPatterns.FirstChildElement("Level")->FirstChildElement()->BoolAttribute("value");

	if (!mChallengeStage)
	{
		mFormation = new Formation();
		mFormation->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.38f, 150.0f));
		Enemy::SetFormation(mFormation);

		for (int i = 0; i < MAX_Enemies; ++i)
		{
			mFormationEnemies[i] = NULL;
		}


		for (int i = 0; i < MAX_Boss; ++i)
		{
			mFormationBoss[i] = NULL;
		}

		mCurrentFlyInPriority = 0;
		mCurrentFlyInIndex = 0;
		mSpawningFinished = false;
		mSpawnDelay = 0.2f;
		mSpawnTimer = 0.0f;

		mDivingEnemy = NULL;
		mSkipFirstEnemy = false;
		mEnemyDiveDelay = 1.0f;
		mEnemyDiveTime = 0.0f;

		mDivingBoss = NULL;
		mCaptureDive = true;
		mSkipBoss = true;
		mBossDiveDelay = 5.0f;
		mBossDiveTimer = 0.0f;

		Enemy::CurrentPlayer(mPlayer);

