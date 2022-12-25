#pragma once
#include "Game.h"
#include "../Input/Input.h"
#include <iostream>

using namespace std;

namespace Game
{
	class TemplateGame :
		public Game
	{
	public:
		TemplateGame(string gameTitle)
			: Game(gameTitle)
		{
		
		}

		void Render();
		void LateUpdate();
		void Close();

		void LoadContent();
		void Init();
		void Update();
	};
}

