#include <iostream> 
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

int main(){

    GameMap Map;
    Player Hero; 
    Map.DrawIntro();
    Map.Draw();
    while(Map.isGameOver == false)
    {
        //Este es el infinite loop del juego
        cout << "Ingrese un comando (w/a/s/d) para mover al jugador: ";

        Hero.CallInput();

        //Update de la posición del jugador en el mapa
        if(Map.SetPlayerCell(Hero.x, Hero.y)){
            Map.Draw();
        }else{
            Hero.ResetToLastPosition();
            Map.Draw();
        }
    }
    return 0;
}