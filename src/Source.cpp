#include <Header.h>

namespace mt
{
	Race::~Race()
	{
		if (m_window != nullptr)
		{
			delete m_window;
		}
	}

	void Race::SetCaption(const std::string& caption)
	{
		m_caption = caption;
	}

	void Race::SetResolution(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void Race::Setup()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
	}

	void Race::Run()
	{
        // Подключение вертикальной синхронизации для оптимального значения кадров в секунду
        m_window->setVerticalSyncEnabled(true);

        // Создание машины
        sf::RectangleShape car1(sf::Vector2f(100, 100));
        car1.setPosition(120, 100);
        sf::Texture texcar;
        texcar.loadFromFile("assets/car1.png");
        car1.setTexture(&texcar);
        car1.setOrigin(10, 10);

        // Трава
        sf::RectangleShape grass(sf::Vector2f(1600, 900));
        grass.setFillColor(sf::Color(10, 200, 80));
        grass.setPosition(0, 0);

        // Дорога(в 4 этапа)
        sf::RectangleShape road1(sf::Vector2f(1400, 100));
        road1.setFillColor(sf::Color::Black);
        road1.setPosition(100, 100);

        sf::RectangleShape road2(sf::Vector2f(100, 700));
        road2.setFillColor(sf::Color::Black);
        road2.setPosition(100, 100);

        sf::RectangleShape road3(sf::Vector2f(100, 700));
        road3.setFillColor(sf::Color::Black);
        road3.setPosition(1400, 100);

        sf::RectangleShape road4(sf::Vector2f(1400, 100));
        road4.setFillColor(sf::Color::Black);
        road4.setPosition(100, 700);

        int speed = 5;

        sf::Clock clock;

        while (m_window->isOpen())
        {

            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
            {
                car1.move(-speed, 0);
                car1.setRotation(180.0f);
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
            {
                car1.move(speed, 0);
                car1.setRotation(360.0f);
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
            {
                car1.move(0, -speed);
                car1.setRotation(270.0f);
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
            {
                car1.move(0, speed);
                car1.setRotation(90.0f);
            }

            m_window->clear();
            m_window->draw(grass);
            m_window->draw(road1);
            m_window->draw(road2);
            m_window->draw(road3);
            m_window->draw(road4);
            m_window->draw(car1);
            m_window->display();
        }
	}
}