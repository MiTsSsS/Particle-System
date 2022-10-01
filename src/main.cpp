#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Headers/Particle.h"

void drawTrail(sf::RenderWindow& window, std::vector<Particle> particleVec) {
    for (int i = 0; i < particleVec.size(); i++) {
        window.draw(particleVec[i].shape);
        //std::cout << particleVec.size() << std::endl;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Simple Particle System");
    window.setFramerateLimit(60);

    sf::Clock clock;
    float lastTime = 0;

    std::vector<Particle> particleVec;

    sf::Font font;
    if (!font.loadFromFile("assets\\fonts\\game_over.ttf")) {
        return EXIT_FAILURE;

    }

    sf::Text fpsCounter;
    fpsCounter.setFont(font);
    fpsCounter.setCharacterSize(50);
    fpsCounter.setFillColor(sf::Color(sf::Color::White));
    fpsCounter.setPosition(5.0, 0.0);

    sf::Text particleCounter;
    particleCounter.setFont(font);
    particleCounter.setCharacterSize(50);
    particleCounter.setFillColor(sf::Color(sf::Color::White));
    particleCounter.setPosition(5.0, 25.0);

    //Particle testParticle(sf::Vector2f(800, 450), sf::Vector2f(2.5f, 1.0f), sf::Color::Green, 1.0f, 10.0f, 10.0f, 5.0f);

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (int i = 0; i < 150; i++) {
                Particle testParticle(sf::Vector2f(sf::Mouse::getPosition(window)), sf::Vector2f(2.5f, 1.0f), sf::Color::Green, rand() % 361, 10.0f, 10.0f, 3.0);
                particleVec.push_back(testParticle);
            }
        }

        window.clear();
        
        for (int i = 0; i < particleVec.size(); i++) {
            window.draw(particleVec[i].shape);
            particleVec[i].move();
            particleVec[i].update();
        }

        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / (currentTime - lastTime);

        fpsCounter.setString("FPS: " + std::to_string(fps));
        particleCounter.setString("Particle Count: " + std::to_string(particleVec.size()));
        
        drawTrail(window, particleVec);

        window.draw(particleCounter);
        window.draw(fpsCounter);
        window.display();
    }

    return 0;
}