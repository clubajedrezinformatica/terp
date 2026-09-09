#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

#pragma once

class GameMap
{
public:
    GameMap();
    ~GameMap();

    MapCell cells[15][10];
    MapCell* PlayerCell;

    void Draw();
    void DrawIntro();
    void DrawVictory();
    bool SetPlayerCell(int PlayerX, int PlayerY);
    bool isGameOver; 


protected: 
    void LoadMapFromFile();
private:

};

#endif