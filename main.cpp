#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::CircleShape shape(100.f);
    shape.setPosition({800,600});
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        shape.move({-0.1f,-0.1f});

        window.display();
    }

    return 0;
}