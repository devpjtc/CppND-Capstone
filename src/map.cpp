#include "map.h"
#include <fstream>
#include <string>
#include <random>
#include <memory>

Map::Map(int grid_width, int grid_height): wigth(grid_width), height(grid_height) {
        _map = std::make_unique<std::vector<std::vector<int>>>();
        for (int i=0; i < grid_width; i++) {
            std::vector<int> x_vector;
            for (int j=0; j < grid_height; j++) {
                x_vector.push_back(0);
            }
            (*_map).push_back(x_vector);
        }
        generateMap();
    }

Map &Map::operator=(Map &&map)
{
    if (this == &map)
        return *this;

    wigth = map.wigth;
    height = map.height;
    _map = std::move(map._map);

    map._map = nullptr;

    return *this;

}


bool Map::IsMapHitted(SDL_Point current_cell) {
    return (*_map.get())[current_cell.x][current_cell.y];
}

void Map::generateMap() {

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> getRandom(1, 3);
    int map_number = getRandom(eng);
    std::string filename = "../resources/map" + std::to_string(map_number) + ".txt";
    std::ifstream map_file(filename);
    std::string line;
     if (map_file.is_open()) {
        int a = 1;
     }
    for (int i = 0; i < wigth; i++) {
        std::getline(map_file, line);
        for (int j = 0; j < height; j++) {
            (*_map.get())[i][j] = (int)line[j] - 48;
        }
    }
}