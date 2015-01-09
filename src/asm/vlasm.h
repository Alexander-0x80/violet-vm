#ifndef VLASM_H
#define VLASM_H

#include <vector>
#include <string>
#include <unordered_map>

#include "vm/vtypes.h"

namespace violet
{
    namespace vlasm
    {
        const char comment(';');
        const std::string i_halt("halt");
        const std::string i_loadi("loadi");
        const std::string i_add("add");

        const std::unordered_map<std::string, unsigned int>
        registers {
                {"r0", 0},
                {"r1", 1},
                {"r2", 2}
        };

        std::vector<unsigned int> parse_source(const std::vector<std::string>);
        std::vector<std::string> parse_line(const std::string);
        unsigned int parse_tokens(const std::vector<std::string>);
        unsigned int parse_reg(const std::string);
        void die(const char *);
    };

}

#endif // VLASM_H