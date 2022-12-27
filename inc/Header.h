#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace mt
{
	class Race
	{
	private:
		int m_width, m_height;
		std::string m_caption;
		sf::RenderWindow* m_window = nullptr;

	public:
		Race()
		{
		}

		~Race();

		void SetCaption(const std::string& caption);
		void SetResolution(int width, int height);
		void Setup();
		void Run();
	};
}