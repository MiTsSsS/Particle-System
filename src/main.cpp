#include <SFML/Graphics.hpp>
#include <vector>
#include "Headers/Particle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Simple Particle System");
    window.setFramerateLimit(60);

    std::vector<Particle> particleVec;

    Particle testParticle(sf::Vector2f(800, 450), sf::Vector2f(2.5f, 1.0f), sf::Color::Green, 1.0f, 10.0f, 10.0f, 1.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        window.draw(testParticle.shape);
        testParticle.move();
        Particle testParticle1(sf::Vector2f(testParticle.position.x, testParticle.position.y), sf::Vector2f(0, 0), sf::Color::Red, 0, 0, 0, 0);
        particleVec.push_back(testParticle1);

        for (int i = 0; i < particleVec.size(); i++) {
            window.draw(particleVec[i].shape);
        }

        testParticle.update();
        window.draw(testParticle.shape);
        window.display();
    }

    return 0;
}