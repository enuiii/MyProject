#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace mt // Вводим пространство имён, чтобы наши классы или функции не пересекались с уже существующими
{
	class Race
	{
	private:
		int m_width, m_height;
		std::string m_caption;
		sf::RenderWindow* m_window = nullptr;

	public:
		Race() // Конструктор
		{
		}

		~Race(); // Деструктор

		void SetCaption(const std::string& caption); // Заголовок экрана
		void SetResolution(int width, int height); // Разрешение экрана
		void Setup(); // В нём хранится окно и параметры окна
		void Run(); // В нём происходит весь игровой процесс
	};
}