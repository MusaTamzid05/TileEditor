#include "tile_io.h"
#include "output_canvas.h"
#include "tile_selector.h"
#include "cell.h"
#include <iostream>
#include <fstream>
#include "util.h"


TileIO::TileIO(const std::string& tile_file_name, 
        OutputCanvas* output_canvas,
        TileSelector* tile_selector,
        const sf::Texture& texture,
        int screen_width,
        int screen_height,
        int tile_width,
        int tile_height,
        const std::string& output_file_name
        ):
    tile_file_name(tile_file_name), 
    output_canvas(output_canvas), 
    tile_selector(tile_selector),
    screen_width(screen_width),
    screen_height(screen_height),
    tile_width(tile_width),
    tile_height(tile_height),
    output_file_name(output_file_name) {

        this->texture = texture;

        std::ifstream input_file(output_file_name + ".data");
        std::string line;

        int row = 0;
        int col = 0;


        while(std::getline(input_file, line)) {
            col = 0;
            std::vector<std::string> results = split_string(line, ',');

            for(std::string item : results) {
                if(item != "-1")  {
                    for(auto cell_item : output_canvas->cell_map) {
                        Cell* cell = cell_item.second;

                        if(cell->row == row && cell->col == col) {

                            for(Cell* tile_cell : tile_selector->cells) {
                                if(tile_cell->row == row && tile_cell->col == col) {
                                    sf::IntRect rect = sf::IntRect(
                                            tile_cell->x,
                                            tile_cell->y,
                                            tile_cell->width,
                                            tile_cell->height);

                                    cell->set_texture(texture, rect);
                                    cell->id = tile_cell->id;
                                    std::cout << cell->sprite.getPosition().x << " " << cell->sprite.getPosition().y << "\n";

                                }
                            }

                        }
                    }

                }
                col += 1;
            }

            row += 1;

        }
}

void TileIO::save() {

    int half = screen_width / 2;

    int cols = half / tile_width;
    int rows = screen_height  / tile_height;

    std::cout << "rows " << rows << " cols " << cols << "\n";
    int map[rows][cols];


    for(auto cell_item : output_canvas->cell_map) {
        Cell* cell = cell_item.second;

        int pos_x = cell->x - half;
        int pos_y = cell->y;



        int col = pos_x / tile_width;
        int row = pos_y / tile_height;



        if(row < rows && col < cols)
            map[row][col] = cell->id;

    }


    std::ofstream out_file(output_file_name + ".data");
    std::string output_string = "";


    for(int row  = 0; row < rows; row += 1) {

        for(int col = 0; col < cols; col += 1) {
            output_string += std::to_string(map[row][col]);

            if(col != cols - 1)
                output_string += ",";
        }

        output_string += "\n";
    }

    out_file << output_string;
    out_file.close();




    /*

    int cols = (map_height / 2) / tile_height;
    int rows = (map_width / 2) / tile_width;

    int map[map_width / tile_width][map_height / tile_height];




    for(auto cell_item : output_canvas->cell_map) {
        Cell* cell = cell_item.second;

        int pos_x = cell->x - half;
        int pos_y = cell->y;


        int col = pos_x / tile_width;
        int row = pos_y / tile_height;

        map[row][col] = cell->id;

    }


    std::ofstream out_file(output_file_name + ".data");

    for(int row  = 0; row < rows; row += 1) {
        std::string output_string = "";

        for(int col = 0; col < cols; col += 1) {
            output_string += std::to_string(map[row][col]);

            if(col != cols - 1)
                output_string += ",";
        }

        output_string += "\n";
        out_file << output_string;
    }

    out_file.close();

    */


}

