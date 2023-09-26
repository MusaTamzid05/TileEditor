#include "tile_io.h"
#include "output_canvas.h"
#include "cell.h"
#include <iostream>
#include <fstream>


TileIO::TileIO(const std::string& tile_file_name, 
        OutputCanvas* output_canvas,
            int screen_width,
            int screen_height,
            int tile_width,
            int tile_height,
            const std::string& output_file_name

        ):
    tile_file_name(tile_file_name), 
    output_canvas(output_canvas), 
    screen_width(screen_width),
    screen_height(screen_height),
    tile_width(tile_width),
    tile_height(tile_height),
    output_file_name(output_file_name) {
        std::cout << "Total - " << output_canvas->cell_map.size() << "\n";
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
