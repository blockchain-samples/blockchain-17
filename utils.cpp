#include "utils.h"

bool exists(const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}
