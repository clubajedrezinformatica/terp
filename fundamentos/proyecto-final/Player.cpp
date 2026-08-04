#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    x = 1; 
    y = 1;
    lastX = 1;
    lastY = 1;
}

Player::~Player()
{

}

void Player::CallInput()
{
    char UserInput;
    cin >> UserInput;

    lastX = x;
    lastY = y;

    switch(UserInput)
    {
        case 'w':
            lastY = y;
            y--;
            break;
        case 's':
            lastY = y;
            y++;
            break;  
        case 'a':
            lastX = x;
            x--;
            break;
        case 'd':
            lastX = x;
            x++;
            break;
    }
}
void Player::ResetToLastPosition()
{
    x = lastX;
    y = lastY;
}