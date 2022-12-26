#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Race");
    window.setFramerateLimit(60);

    // Создание машины
    sf::RectangleShape car1(sf::Vector2f(100, 50));
    car1.setPosition(120, 100);
    sf::Texture texcar;
    texcar.loadFromFile("assets/car1.png");
    car1.setTexture(&texcar);

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

    int speed = 10;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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

        window.clear();
        window.draw(grass);
        window.draw(road1);
        window.draw(road2);
        window.draw(road3);
        window.draw(road4);
        window.draw(car1);
        window.display();
    }

    return 0;
}