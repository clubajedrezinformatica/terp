#include "MapCell.h"

MapCell::MapCell()
{
    id = 0;
}

MapCell::~MapCell()
{

}
bool MapCell::IsWall()
{
    if(id == '1')
    {
        return true;
    }else{
        return false;
    }
}