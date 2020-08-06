#include <SFML/Graphics.hpp>
#include<iostream>
#include"Key.h"
#include<string.h>

Key* Board[8][8];
int playerTurn;
sf::Text infoText;

void putInBoard(Key* Board[8][8],Key &key)
{
    Board[key.currentPosition.x][key.currentPosition.y] = &key;
}

sf::Vector2i getClickedBlockPositon(sf::Vector2i mousePosition)
{
    mousePosition.x /= 100;
    mousePosition.y /= 100;
    return mousePosition;
}

bool movementIsPossible(Key* key, sf::Vector2i firstclickmousePosition, sf::Vector2i secondclickmousePosition)
{
    if (key->isWhite() == playerTurn) {
       
        infoText.setString("Next players turn");
        return false;
    }
    if (Board[secondclickmousePosition.x][secondclickmousePosition.y] != NULL)
    {
        if (key->isWhite() == Board[secondclickmousePosition.x][secondclickmousePosition.y]->isWhite()) {
            infoText.setString("friendly fire is turned off"); 
            
            return false;
        }
    }

    int a = firstclickmousePosition.x - secondclickmousePosition.x;
    int b = firstclickmousePosition.y - secondclickmousePosition.y;

    switch (key->getPieceId())
    {
        
    case 0:

        if (a == 0 || b == 0) {
            if (a == 0) {
                int begin, end;
                if (firstclickmousePosition.y > secondclickmousePosition.y) {
                    end = firstclickmousePosition.y - 1;
                    begin = secondclickmousePosition.y + 1;
                }
                else {
                    begin = firstclickmousePosition.y + 1;
                    end = secondclickmousePosition.y - 1;
                }
                for (int i = begin; i <= end; i++)
                {
                    if (Board[firstclickmousePosition.x][i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
            }
            else {
                int begin, end;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                }
                for (int i = begin; i <= end; i++)
                {
                    if (Board[i][firstclickmousePosition.y] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }

            }

            return true; }
        else if (a == b || a == -b) {
            if (a == b)
            {
                int end, begin,ybegin;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                    ybegin = secondclickmousePosition.y + 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                    ybegin = firstclickmousePosition.y + 1;
                }
                std::cout << std::endl;
                for (int i = begin; i <= end; i++)
                {
                    
                    std::cout << i << " " << ybegin - begin + i <<std:: endl;
                    if (Board[i][ybegin-begin+i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
                std::cout << std::endl;
            }
            else {
                int end, begin, ybegin;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                    ybegin = secondclickmousePosition.y - 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                    ybegin = firstclickmousePosition.y - 1;
                }
                std::cout << std::endl;
                for (int i = begin; i <= end; i++)
                {

                    std::cout << i << " " << ybegin - begin + i << std::endl;
                    if (Board[i][ybegin + begin - i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
                std::cout << std::endl;

            }
            
            return true; }
        return false;
          break;
    case 1:
 
        if ( b <= 1 && b >=-1 &&  a <= 1 && a >= -1)return true;
        return false;
        break;
    case 2:
        // std::cout << a << b << std::endl;
        if (a == b || a == -b) {

            if (a == b)
            {
                int end, begin, ybegin;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                    ybegin = secondclickmousePosition.y + 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                    ybegin = firstclickmousePosition.y + 1;
                }
                std::cout << std::endl;
                for (int i = begin; i <= end; i++)
                {

                    std::cout << i << " " << ybegin - begin + i << std::endl;
                    if (Board[i][ybegin - begin + i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
                std::cout << std::endl;
            }
            else {
                int end, begin, ybegin;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                    ybegin = secondclickmousePosition.y - 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                    ybegin = firstclickmousePosition.y - 1;
                }
                std::cout << std::endl;
                for (int i = begin; i <= end; i++)
                {

                    std::cout << i << " " << ybegin - begin + i << std::endl;
                    if (Board[i][ybegin + begin - i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
                std::cout << std::endl;

                return true;
            }
        }
        else return false;
        break;
    case 3:
        if (a < 0)a = -a;
        if (b < 0)b = -b;
        if (a == b || a > 2 || b > 2||a==0||b==0)return false;
        else return true;
        break;
    case 4:
        if (a == 0 || b == 0) {
            
            if (a == 0) {
                int begin, end;
                if (firstclickmousePosition.y > secondclickmousePosition.y) {
                    end = firstclickmousePosition.y - 1;
                    begin = secondclickmousePosition.y + 1;
                }
                else {
                    begin = firstclickmousePosition.y + 1;
                    end = secondclickmousePosition.y - 1;
                }
                for (int i = begin; i <= end; i++)
                {
                    if (Board[firstclickmousePosition.x][i] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }
            }
            else {
                int begin, end;
                if (firstclickmousePosition.x > secondclickmousePosition.x) {
                    end = firstclickmousePosition.x - 1;
                    begin = secondclickmousePosition.x + 1;
                }
                else {
                    begin = firstclickmousePosition.x + 1;
                    end = secondclickmousePosition.x - 1;
                }
                for (int i = begin; i <= end; i++)
                {
                    if (Board[i][firstclickmousePosition.y] != NULL) {
                        infoText.setString("keys in the way");
                        return false;
                    }
                }

            }
            
            
            return true; }
        else return false;
        break;
    case 5:
        if (key->isWhite()) {
            if (Board[secondclickmousePosition.x][secondclickmousePosition.y] != NULL)
            {
                if ((a == 1 || a == -1) && b == 1)return true;
            }
            if (a == 0 && b == 1 && Board[secondclickmousePosition.x][secondclickmousePosition.y] == NULL)return true;
            else return false;
        }
        else {
            if (Board[secondclickmousePosition.x][secondclickmousePosition.y] != NULL)
            {
                if ((a == 1 || a == -1) && b == -1)return true;
            }
            if (a == 0 && b == -1 && Board[secondclickmousePosition.x][secondclickmousePosition.y] == NULL)return true;
            else return false;

        }
    default:
        return false;
  

    }
   
}

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 920), "Chess");
    sf::RectangleShape chessBoard(sf::Vector2f(800.0f,800.0f));
    sf::RectangleShape GameOverImage(sf::Vector2f(800.0f,500.0f));
    sf::RectangleShape currentSelected(sf::Vector2f(100.0f,100.0f));
    sf::RectangleShape bottomBox(sf::Vector2f(800.0f,300.0f));
    bottomBox.setOrigin(400.0f, 150.0f);
    bottomBox.setPosition(400.0f, 860.0f);
    GameOverImage.setOrigin(400.0f, 250.0f);
    GameOverImage.setPosition(400.0f, 400.0f);
    sf::Texture gameOverTexture;
    sf::Texture boardTexture;
    sf::Texture keyTexture;
    sf::Texture currentSelectedTexture;
    sf::Texture BoxTexture;
    BoxTexture.loadFromFile("box.png");
    currentSelectedTexture.loadFromFile("select.png");
    keyTexture.loadFromFile("keys.png");
    gameOverTexture.loadFromFile("GameOver.png");
    boardTexture.loadFromFile("chessboard.png");
    chessBoard.setTexture(&boardTexture);
    GameOverImage.setTexture(&gameOverTexture);
    currentSelected.setTexture(&currentSelectedTexture);
    bottomBox.setTexture(&BoxTexture);
    sf::Vector2i firstclickmousePositon;

    sf::Font currentPlayerFont;
    currentPlayerFont.loadFromFile("currentPlayer.ttf");
    sf::Text currentPlayerText;
    currentPlayerText.setFont(currentPlayerFont);
    currentPlayerText.setCharacterSize(20);;
    currentPlayerText.setPosition(100.0f, 845.0f);

    infoText.setCharacterSize(15);
    infoText.setFont(currentPlayerFont);
    infoText.setPosition(300.0f, 845.0f);
    infoText.setFillColor(sf::Color::Black);
    infoText.setString("default");


    
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            Board[i][j] = NULL;
   

#pragma region all keys declaration
    Key BLElephant(keyTexture,sf::Vector2u(4,1));
    BLElephant.setPosition(0, 0);
    Key BLHorse(keyTexture, sf::Vector2u(3, 1));
    BLHorse.setPosition(1, 0);
    Key BLCamel(keyTexture, sf::Vector2u(2, 1));
    BLCamel.setPosition(2, 0);
    Key BKing(keyTexture,sf::Vector2u(1,1));
    BKing.setPosition(3,0);
    Key BQueen(keyTexture, sf::Vector2u(0, 1));
    BQueen.setPosition(4, 0);
    Key BRCamel(keyTexture, sf::Vector2u(2, 1));
    BRCamel.setPosition(5, 0);
    Key BRHorse(keyTexture, sf::Vector2u(3, 1));
    BRHorse.setPosition(6, 0);
    Key BRElephant(keyTexture, sf::Vector2u(4, 1));
    BRElephant.setPosition(7, 0);

    Key BSoldier1(keyTexture, sf::Vector2u(5, 1));
    BSoldier1.setPosition(0, 1);
    Key BSoldier2(keyTexture, sf::Vector2u(5, 1));
    BSoldier2.setPosition(1, 1);
    Key BSoldier3(keyTexture, sf::Vector2u(5, 1));
    BSoldier3.setPosition(2, 1);
    Key BSoldier4(keyTexture, sf::Vector2u(5, 1));
    BSoldier4.setPosition(3, 1);
    Key BSoldier5(keyTexture, sf::Vector2u(5, 1));
    BSoldier5.setPosition(4, 1);
    Key BSoldier6(keyTexture, sf::Vector2u(5, 1));
    BSoldier6.setPosition(5, 1);
    Key BSoldier7(keyTexture, sf::Vector2u(5, 1));
    BSoldier7.setPosition(6, 1);
    Key BSoldier8(keyTexture, sf::Vector2u(5, 1));
    BSoldier8.setPosition(7, 1);

    Key WLElephant(keyTexture, sf::Vector2u(4, 0));
    WLElephant.setPosition(0, 7);
    Key WLHorse(keyTexture, sf::Vector2u(3, 0));
    WLHorse.setPosition(1, 7);
    Key WLCamel(keyTexture, sf::Vector2u(2, 0));
    WLCamel.setPosition(2, 7);
    Key WKing(keyTexture, sf::Vector2u(1, 0));
    WKing.setPosition(3, 7);
    Key WQueen(keyTexture, sf::Vector2u(0, 0));
    WQueen.setPosition(4, 7);
    Key WRCamel(keyTexture, sf::Vector2u(2, 0));
    WRCamel.setPosition(5, 7);
    Key WRHorse(keyTexture, sf::Vector2u(3, 0));
    WRHorse.setPosition(6, 7);
    Key WRElephant(keyTexture, sf::Vector2u(4, 0));
    WRElephant.setPosition(7, 7);

    Key WSoldier1(keyTexture, sf::Vector2u(5, 0));
    WSoldier1.setPosition(0, 6);
    Key WSoldier2(keyTexture, sf::Vector2u(5, 0));
    WSoldier2.setPosition(1, 6);
    Key WSoldier3(keyTexture, sf::Vector2u(5, 0));
    WSoldier3.setPosition(2, 6);
    Key WSoldier4(keyTexture, sf::Vector2u(5, 0));
    WSoldier4.setPosition(3, 6);
    Key WSoldier5(keyTexture, sf::Vector2u(5, 0));
    WSoldier5.setPosition(4, 6);
    Key WSoldier6(keyTexture, sf::Vector2u(5, 0));
    WSoldier6.setPosition(5, 6);
    Key WSoldier7(keyTexture, sf::Vector2u(5, 0));
    WSoldier7.setPosition(6, 6);
    Key WSoldier8(keyTexture, sf::Vector2u(5, 0));
    WSoldier8.setPosition(7, 6);
#pragma endregion
 
#pragma region putInBoard all keys
    putInBoard(Board, BKing);
    putInBoard(Board, BQueen);
    putInBoard(Board, BLCamel);
    putInBoard(Board, BLElephant);
    putInBoard(Board, BLHorse);
    putInBoard(Board, BRCamel);
    putInBoard(Board, BRHorse);
    putInBoard(Board, BRElephant);
    putInBoard(Board, BSoldier1);
    putInBoard(Board, BSoldier2);
    putInBoard(Board, BSoldier3);
    putInBoard(Board, BSoldier4);
    putInBoard(Board, BSoldier5);
    putInBoard(Board, BSoldier6);
    putInBoard(Board, BSoldier7);
    putInBoard(Board, BSoldier8);

    putInBoard(Board, WKing);
    putInBoard(Board, WQueen);
    putInBoard(Board, WLCamel);
    putInBoard(Board, WLElephant);
    putInBoard(Board, WLHorse);
    putInBoard(Board, WRCamel);
    putInBoard(Board, WRHorse);
    putInBoard(Board, WRElephant);
    putInBoard(Board, WSoldier1);
    putInBoard(Board, WSoldier2);
    putInBoard(Board, WSoldier3);
    putInBoard(Board, WSoldier4);
    putInBoard(Board, WSoldier5);
    putInBoard(Board, WSoldier6);
    putInBoard(Board, WSoldier7);
    putInBoard(Board, WSoldier8);
#pragma endregion

    playerTurn = 0;
    int click = 0;

    while (window.isOpen())
    {
       //std::cout << Board[3][0]->currentPosition.x<<"\n";
     
        sf::Event e;
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
            {
               
                
                switch (e.key.code)
                {
                case sf::Mouse::Left:
                   // std::cout << working.pointerArray[3][0]->currentPosition.x;
                    if (click == 0) {
                        firstclickmousePositon = sf::Mouse::getPosition(window);
                        firstclickmousePositon = getClickedBlockPositon(firstclickmousePositon);
                        if (Board[firstclickmousePositon.x][firstclickmousePositon.y] == NULL)break;
                        //std::cout << mousePositon.x << " " << mousePositon.y << "\n\n";
                        click = 1;
                        
                       
                        currentSelected.setPosition(firstclickmousePositon.x*100, firstclickmousePositon.y*100);

                    }
                    else {
                        sf::Vector2i secondclickmousePositon = sf::Mouse::getPosition(window);
                        secondclickmousePositon = getClickedBlockPositon(secondclickmousePositon);
                    
                        //std::cout << firstclickmousePositon.x << " " << firstclickmousePositon.y << "\n";
                        //std::cout << secondclickmousePositon.x << " " << secondclickmousePositon.y << "\n";
                        //std::cout << Board[firstclickmousePositon.x][firstclickmousePositon.y]->getPieceId() << "\n";
                        if (firstclickmousePositon.x == secondclickmousePositon.x && firstclickmousePositon.y == secondclickmousePositon.y)
                        {
                            click = 0;
                            break;
                        }
                        if (movementIsPossible(Board[firstclickmousePositon.x][firstclickmousePositon.y], firstclickmousePositon, secondclickmousePositon)) {

                            if (Board[secondclickmousePositon.x][secondclickmousePositon.y] != NULL) { Board[secondclickmousePositon.x][secondclickmousePositon.y]->nullIt(); }
                            Board[secondclickmousePositon.x][secondclickmousePositon.y] = Board[firstclickmousePositon.x][firstclickmousePositon.y];
                            Board[firstclickmousePositon.x][firstclickmousePositon.y] = NULL;
                            Board[secondclickmousePositon.x][secondclickmousePositon.y]->setPosition(secondclickmousePositon.x, secondclickmousePositon.y);
                            playerTurn = (playerTurn + 1) % 2;
                            infoText.setString("");
                            
                        }
                        else {
                            //std::cout << "movement not possible";
                           // infoText.setString("movement not possible");
                        }
                          
                        click = 0;
                    }
                    
                    break;
                }
                break;
            }
            }
            
        }
        
        window.draw(chessBoard);
        
 #pragma region keys drawing
        window.draw(BLElephant.shape);
        window.draw(BLHorse.shape);
        window.draw(BLCamel.shape);
        window.draw(BKing.shape);
        window.draw(BQueen.shape);
        window.draw(BRCamel.shape);
        window.draw(BRHorse.shape);
        window.draw(BRElephant.shape);
        window.draw(BSoldier1.shape);
        window.draw(BSoldier2.shape);
        window.draw(BSoldier3.shape);
        window.draw(BSoldier4.shape);
        window.draw(BSoldier5.shape);
        window.draw(BSoldier6.shape);
        window.draw(BSoldier7.shape);
        window.draw(BSoldier8.shape);

        window.draw(WLElephant.shape);
        window.draw(WLHorse.shape);
        window.draw(WLCamel.shape);
        window.draw(WKing.shape);
        window.draw(WQueen.shape);
        window.draw(WRCamel.shape);
        window.draw(WRHorse.shape);
        window.draw(WRElephant.shape);
        window.draw(WRElephant.shape);
        window.draw(WSoldier1.shape);
        window.draw(WSoldier2.shape);
        window.draw(WSoldier3.shape);
        window.draw(WSoldier4.shape);
        window.draw(WSoldier5.shape);
        window.draw(WSoldier6.shape);
        window.draw(WSoldier7.shape);
        window.draw(WSoldier8.shape);
#pragma endregion
        if (click == 1) {
            window.draw(currentSelected);
        }
        if(BKing.isDead || WKing.isDead)
        window.draw(GameOverImage);
        window.draw(bottomBox);
        if (playerTurn == 0) {
            currentPlayerText.setString("current player \n        white");
            currentPlayerText.setFillColor(sf::Color::White);
        }
        else {
            currentPlayerText.setString("current player \n        black");
            currentPlayerText.setFillColor(sf::Color::Black);

        }

            window.draw(currentPlayerText);
            window.draw(infoText);
        
        window.display(); 
    }

    return 0;
}