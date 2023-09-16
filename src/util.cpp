#include "util.h"



std::string get_position_key(int x, int y) {
    return std::to_string(x) + "-" + std::to_string(y);
}
