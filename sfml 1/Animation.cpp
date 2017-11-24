#include "stdafx.h"
#include "Animation.h"

Animation::Animation(float textureWidth, float textureHeight, unsigned short imageCount, float switchTime):
	textureWidth(textureWidth), textureHeight(textureHeight), switchTime(switchTime),imageCount(imageCount), currentImage(0), totalTime(0.f)
{}

void Animation::update(unsigned int direction,sf::Texture &texture, sf::Sprite &player, float &deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;

		if (currentImage > imageCount)
			currentImage = 0;

		player.setTexture(texture);
		player.setTextureRect(sf::IntRect(textureWidth * currentImage, textureHeight * direction, textureWidth, textureHeight));
		
		++currentImage;
	}
}

Animation::~Animation(void)
{}