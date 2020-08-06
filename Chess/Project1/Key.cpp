#include "Key.h"
#include<SFML/Graphics.hpp>
#include<iostream>

Key::Key(sf::Texture& texture, sf::Vector2u position)
{
	
	this->keyTexture = texture;
	this->texturePositon = position;
	shape.setSize(sf::Vector2f(100.0f, 100.0f));
	shape.setTexture(&texture);
	sf::Vector2u textureSize= texture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;
	shape.setTextureRect(sf::IntRect(position.x * textureSize.x, position.y * textureSize.y, textureSize.x, textureSize.y));
	//shape.setOrigin(textureSize.x / 2, textureSize.y / 2);
	
	
}


void Key::setPosition(int x, int y)
{
	this->currentPosition.x = x;
	this->currentPosition.y = y;
	this->shape.setPosition(x*100,y*100);
}

void Key::nullIt()
{
	shape.setTextureRect(sf::IntRect(1000,1000,100,100));
	isDead = true;
}

std::string Key::getPieceName()
{
	switch (this->texturePositon.x)
	{
	case 0:
		return std::string("Queen");
		break;
	case 1:
		return std::string("King");
		break;
	case 2:
		return std::string("Camel");
		break;
	case 3:
		return std::string("Horse");
		break;
	case 4:
		return std::string("Elephant");
		break;
	case 5:
		return std::string("Soldier");
		break;

	}


}

int Key::getPieceId()
{
	return this->texturePositon.x;

}

bool Key::isWhite()
{
	if (this->texturePositon.y == 0)return true;
	else return false;
}

