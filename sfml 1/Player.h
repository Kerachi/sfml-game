#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture, float, float);

	void addWalkingTexutre(sf::Texture);

	void const update(float, std::list<sf::RectangleShape *> &);
	void const draw(sf::RenderWindow &) const;

	sf::RectangleShape collisionRect;

	enum directions { RIGHT, UP, UP_RIGHT, UP_LEFT, DOWN, DOWN_RIGHT, DOWN_LEFT, LEFT };
	directions direction;
	
	sf::Sprite getSprite();

	~Player(void);
private:
	sf::Sprite player;
	sf::Texture stopped_Texture;
	sf::Texture walking_Texture;

	unsigned short textureWidth;
	unsigned short textureHeight;

	float speed;
	bool moving;
	const float SQRT_2 = std::sqrt(2.f);

	Animation animation;
};
