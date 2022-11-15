#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "SDL.h"


class Map {
 public:
    Map(int grid_width, int grid_height);
    Map &operator=(Map &&map);

    bool IsMapHitted(SDL_Point current_head_cell);
    int getCellValue(int x, int y) {
        return (*_map.get())[x][y];
    }
 private:
    int wigth, height;
    std::unique_ptr<std::vector<std::vector<int>>> _map;
    void generateMap(); 

};

#endif