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


    u16 Vm::fetch()
    {
        return program.at(pc++);
    }

    int Vm::run()
    {
        running = true;
        instruction instr;

        if (program.empty()) return 1;
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

        return 0;
    }

    std::vector<u16> Vm::dump_regs() const
    {
        std::vector<u16> rdump;
        for (auto r: regs)
        {
            rdump.push_back(r);
        }

        return rdump;
    }

    instruction Vm::decode(const unsigned int opcode) const
    {
        instruction i;
        // Bits 15-12  Instruction number
        // Bits 11-8   Register number
        // Bits 7-0    Immediate value

        i.code = (opcode & 0xF000) >> 12;
        i.r1   = (opcode & 0xF00)  >>  8;
        i.r2   = (opcode & 0xF0)   >>  4;
        i.r3   = (opcode & 0xF);
        i.imm  = (opcode & 0xFF);

        return i;
    }

}

