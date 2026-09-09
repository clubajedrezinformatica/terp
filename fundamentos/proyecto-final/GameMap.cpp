#include "GameMap.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

GameMap::GameMap()
{
    PlayerCell = nullptr;
    LoadMapFromFile();
    isGameOver = false;
}

GameMap::~GameMap()
{

}
void GameMap::DrawIntro() 
{
    string line; 
    int row = 0;
    ifstream MyFile("Intro.txt");
    if (MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }

        cin >> line;

    }else{
        cout << "FATAL ERROR: INTRO COULD NOT BE LOADED" << endl;
    }
}
void GameMap::DrawVictory() 
{
    string line; 
    int row = 0;
    ifstream MyFile("Victory.txt");
    if (MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
    }else{
        cout << "FATAL ERROR: VICTORY SCREEN COULD NOT BE LOADED" << endl;
    }
}
void GameMap::Draw()
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << cells[i][j].id;
        }
        std::cout << std::endl;
    }
}
bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if(PlayerX < 0 || PlayerX >= 10 || PlayerY < 0 || PlayerY >= 15)
    {
        return false;
    }
    if(cells[PlayerY][PlayerX].IsWall() == false)
    {
        if(cells[PlayerY][PlayerX].id == '$')
        {
            DrawVictory();
            exit(0);
        }
        if(PlayerCell != nullptr)
        {
            PlayerCell->id = ' ';
        }
            PlayerCell = &cells[PlayerY][PlayerX];
            PlayerCell->id = '3';
            return true;
            //cout << "Las coordenadas del jugador son: (" << PlayerX << ", " << PlayerY << ")" << endl;
        }
        else
        {
            return false;
        }
}

void GameMap::LoadMapFromFile()
{
    string line; 
    int row = 0;
    ifstream MyFile("Map.txt");
    if (MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(int p = 0; p < line.length(); p++)
            {
                if(line[p] == '0')
                {
                    cells[row][p].id = ' ';
                }else{
                    cells[row][p].id = line[p];
                }
            }
            row++;
        }

    }else{
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED" << endl;
    }
    
}