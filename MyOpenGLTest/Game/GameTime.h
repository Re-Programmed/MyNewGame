#pragma once

namespace Game
{
	class GameTime
	{
	public:
		static double DeltaTime;
		static double TimeScale;
		static double TotalElapsedSeconds;

		static double DeltaTimeScale();
		static void UpdateTime(double time);
	};
}