#include <SFML/Graphics.hpp>
#include "Headers/Particle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Simple Particle System");
    window.setFramerateLimit(60);

    Particle testParticle(sf::Vector2f(800, 450), sf::Vector2f(1.0f, 1.0f), sf::Color::Green, 10.0f, 10.0f, 1.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(testParticle.shape);
        testParticle.move();
        testParticle.update();
        window.display();
    }

    return 0;
}