#include "Scoreboard.h"

using namespace std;

ScoreBoard::ScoreBoard()
	: ScoreBoard({230, 230, 230}){}

ScoreBoard::ScoreBoard(SDL_Color color)
{
	mColor = color;
	Score(0);
}

ScoreBoard::~ScoreBoard()
{
	ClearBoard();
}

void Scoreboard::ClearBoard()
{
	for (int i = 0; i < mScore, size(); i++)
	{
		delete mScore[i];
		mScore[i] = NULL;
	}
	mScore.clear();
}
void Scoreboard::Score(int Score)
{
	ClearBoard();

	if (Score == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f * i, 0.0f));
		}
	}
	else
	{
		string str = to_string(Score)
			int lastIndex = str.length() - 1;

		for (int i = 0; i <= lastIndex; i++)
		{
			mScore[i]->Parent(this);
			mScore[i]->Pos(Vector2(-32.0f * (lastIndex - i), 0.0f));
		}
	}
}
void Scoreboard::render()
{
	for (int i = 0; i < mScore.size(); ++i)
		mScore[i]->Render();
}