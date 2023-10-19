#pragma once
#include <SFML/Graphics.hpp>

class Particle {

public:

	Particle(sf::Vector2f velocity, sf::Vector2f position, sf::Color color, float radius, double angle, double lifetime, double speed);
	double getLifetime() const;
	bool getIsActive() const;

	sf::CircleShape getShape() const;
	sf::Vector2f getPosition() const;

	void setIsActive(bool active);
	void reset();
	void move();
	void update();

private:
	sf::CircleShape m_shape;
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Clock m_clock;
	sf::Time m_time;

	bool m_isActive {false};
	bool m_shouldFlipDirection {false};

	float m_directionChange {1.0f};
	float m_radius;
	double m_angle;
	double m_lifetime;
	double m_speed;
};