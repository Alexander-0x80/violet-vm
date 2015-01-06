#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vm/vtypes.h"

namespace violet
{

    namespace utils
    {
        std::vector<u16> load_program_file(const std::string);
        std::vector<std::string> load_source_file(const std::string filename);
    }

};

#endif // UTILS_H
