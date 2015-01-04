#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define VIOLET_REGS_N 4

typedef unsigned char  u8;
typedef unsigned short u16;

namespace violet
{
    const unsigned int i_halt  {0};
    const unsigned int i_loadi {0x1};
    const unsigned int i_add   {0x2};

    struct instruction
    {
        int code;
        int r1;
        int r2;
        int r3;
        int imm;
    };

    class Vm
    {
        bool running;
        std::vector<u16> program;
        u16  regs[VIOLET_REGS_N];
        u16  pc;

    public:
        Vm(const std::string&);
        ~Vm();

        u16 fetch();
        void run();
        instruction decode(const int) const;

    private:
        std::vector<u16> loadProgram(const std::string) const;
    };
}

#endif // VM_H
