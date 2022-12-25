#include "GameTime.h"

namespace Game
{
	double GameTime::TimeScale = 1;

	double GameTime::DeltaTimeScale()
	{
		return DeltaTime * TimeScale;
	}

	void GameTime::UpdateTime(double time)
	{
		DeltaTime = time - TotalElapsedSeconds;
		TotalElapsedSeconds = time;
	}
}