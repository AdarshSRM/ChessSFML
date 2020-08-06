#ifndef KEY_H
#define KEY_H
#include<SFML/Graphics.hpp>
#include<string.h>

class Key
{
public:
	Key(sf::Texture& texture, sf::Vector2u texturePosition);

	void setPosition(int x,int y);
	void nullIt();

	
	std::string getPieceName();
	int getPieceId();
	bool isWhite();
	bool isDead = false;
	sf::Texture keyTexture;
	sf::Vector2u texturePositon;
	sf::Vector2u currentPosition;
	sf::RectangleShape shape;
	


};

#endif

