#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

std::string get_position_key(int x, int y);
std::vector<std::string> split_string(const std::string& text, char splitter=' ');

#endif
