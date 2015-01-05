#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "vtypes.h"

namespace violet
{
    namespace utils
    {
        std::vector<u16> load_program_file(const std::string);
    }
};

#endif // UTILS_H
