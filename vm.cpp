#include "vm.h"

namespace violet
{

    Vm::Vm(const std::vector<u16> program):
        running(false),
        program(program),
        pc(0)
    {

    }

    Vm::~Vm()
    {

    }

    void Vm::run()
    {
        running = true;
        instruction instr;

        while(running)
        {
            instr = decode(fetch());
            switch(instr.code)
            {
                case i_halt:
                    running = false;
                    std::cout << "Halt" << std::endl;
                    break;

                case i_loadi:
                    std::cout << "Loadi" << std::endl;
                    regs[instr.r1] = instr.imm;
                    break;

                case i_add:
                    std::cout << "Add" << std::endl;
                    regs[instr.r1] = regs[instr.r2] + regs[instr.r3];
                    break;
            }
        }
        std::cout << instr.code << std::endl;

    }

    u16 Vm::fetch()
    {
        return program.at(pc++);
    }

    instruction Vm::decode(const int instr) const
    {
        instruction decoded;
        // Bits 15-12  Instruction number
        // Bits 11-8   Register number
        // Bits 7-0    Immediate value

        decoded.code = (instr & 0xF000) >> 12;
        decoded.r1   = (instr & 0xF00)  >>  8;
        decoded.r2   = (instr & 0xF0)   >>  4;
        decoded.r3   = (instr & 0xF);
        decoded.imm  = (instr & 0xFF);

        return decoded;
    }
}

