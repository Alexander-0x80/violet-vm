#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>

#include "vtypes.h"

#define VIOLET_REGS_N 4

namespace violet
{
    class Vm
    {
        bool running;
        std::vector<u16> program;
        u16  regs[VIOLET_REGS_N];
        u16  pc;

    public:
        Vm(const std::vector<u16>);
        ~Vm();

        u16 fetch();
        void run();
        instruction decode(const int) const;

    private:

    };
}

#endif // VM_H
