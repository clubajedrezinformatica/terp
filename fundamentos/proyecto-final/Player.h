#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player
{
public:
    Player();
    ~Player();
    int x, y;
    int lastX, lastY;
    void CallInput();
    void ResetToLastPosition();
protected: 
  
private:

};

#endif