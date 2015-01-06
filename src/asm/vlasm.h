#ifndef VLASM_H
#define VLASM_H

#include <vector>
#include <string>

#include "vm/vtypes.h"

namespace violet
{
    namespace vlasm
    {
        class Asm
        {
           std::vector<std::string> source;

        public:
           Asm(const std::vector<std::string>);
           ~Asm();

        };
    }

}


#endif // VLASM_H