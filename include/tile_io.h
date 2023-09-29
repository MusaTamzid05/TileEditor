#ifndef TILE_IO_H
#define TILE_IO_H

#include <string>
#include <SFML/Graphics.hpp>

struct OutputCanvas;
struct TileSelector;


struct TileIO {
    TileIO(
            const std::string& tile_file_name,
            OutputCanvas* output_canvas,
            TileSelector* tile_selector,
            const sf::Texture& texture,
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

    TileSelector* tile_selector;

    sf::Texture texture;
};

#endif
