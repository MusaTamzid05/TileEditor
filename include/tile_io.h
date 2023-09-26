#ifndef TILE_IO_H
#define TILE_IO_H

#include <string>

struct OutputCanvas;


struct TileIO {
    TileIO(
            const std::string& tile_file_name,
            OutputCanvas* output_canvas,
            int screen_width,
            int screen_height,
            int tile_width,
            int tile_height,
            const std::string& output_file_name="result"

            );

    void save();

    std::string tile_file_name;
    OutputCanvas* output_canvas;

    int screen_width;
    int screen_height;

    int tile_width;
    int tile_height;

    std::string output_file_name;
};

#endif
