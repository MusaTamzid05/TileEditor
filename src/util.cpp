#include "util.h"



std::string get_position_key(int x, int y) {
    return std::to_string(x) + "-" + std::to_string(y);
}

std::vector<std::string> split_string(const std::string& text, char splitter) {
    std::vector<std::string> results;
    std::string temp = "";

    for(char ch : text) {

        if(ch == splitter) {
            results.push_back(temp);
            temp = "";
            continue;
        }

        temp += ch;
    }

    results.push_back(temp);
    return results;

}
