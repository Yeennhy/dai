#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::CircleShape shape(100.f);
    shape.setPosition({400, 300});
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (event->is<sf::Event::MouseButtonPressed>())
            {
                // std::cout << sf::Mouse::getPosition(window).x << ' ' << sf::Mouse::getPosition(window).y << '\n';
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);
                if (shape.getGlobalBounds().contains(mouseWorldPos))
                {
                    shape.setPointCount(30); // Ensuring it's a smooth circle
                    shape.setFillColor(sf::Color::Red);
                }
                std::cout << mousePos.x << ' ' << mousePos.y << '\n';
            }
            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                std::cout << "0\n";
                if (keyPressed->scancode == sf::Keyboard::Scan::Left)
                {
                    std::cout << "1\n";
                    shape.move({-5, 0});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::Right)
                {
                    std::cout << "2\n";
                    shape.move({5, 0});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::Up)
                {
                    std::cout << "3\n";
                    shape.move({0, -5});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::Down)
                {
                    std::cout << "4\n";
                    shape.move({0, 5});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::R)
                {
                    shape.setPointCount(4);
                    shape.setFillColor(sf::Color(0, 250, 50));
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::T)
                {
                    shape.setPointCount(3);
                }
                else if (keyPressed->scancode == sf::Keyboard::Scan::C)
                {
                    shape.setPointCount(30);
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
// #include "SFML/Graphics.hpp"

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode({800, 600}), "Window",
//                             sf::Style::Titlebar | sf::Style::Close);
//     sf::Font arial;
//     arial.openFromFile("arial.ttf");
//     sf::Text t(arial);
//     t.setFillColor(sf::Color::White);
//     t.setFont(arial);
//     std::string s = "This is text that you type: ";
//     t.setString(s);

//     while (window.isOpen())
//     {
//         while (const std::optional event = window.pollEvent())
//         {
//             if (event->is<sf::Event::Closed>())
//             {
//                 window.close();
//             }
//             if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
//             {
//                 s.append(sf::Keyboard::getDescription(keyPressed->scancode));
//             }
//         }
//         t.setString(s);
//         window.clear(sf::Color::Black);
//         window.draw(t);
//         window.display();
//     }
// }