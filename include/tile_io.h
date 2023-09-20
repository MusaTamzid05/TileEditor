#ifndef TILE_IO_H
#define TILE_IO_H

#include <string>

struct OutputCanvas;


struct TileIO {
    TileIO(
            const std::string& tile_file_name,
            OutputCanvas* output_canvas,
            int map_width,
            int map_height,
            int tile_width,
            int tile_height

            );

    void save();

    std::string tile_file_name;
    OutputCanvas* output_canvas;

    int map_width;
    int map_height;

    int tile_width;
    int tile_height;
};

#endif
