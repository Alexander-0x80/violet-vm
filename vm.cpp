#include "vm.h"

Vm::Vm(const std::string& filename):
    program(loadProgram(filename)), pc(0)
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
            case IHALT:
                running = false;
                std::cout << "Halt" << std::endl;
                break;

            case ILOADI:
                std::cout << "Loadi" << std::endl;
                regs[instr.r1] = instr.imm;
                break;

            case IADD:
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

std::vector<u16> Vm::loadProgram(const std::string filename) const
{
    u16 instr;
    u8  bytes[2];
    std::vector<u16> result;

    std::ifstream file(filename, std::ios::binary);
    if (file.fail())
    {
        std::cerr << "Could not load program" << std::endl;
    }

    while(file.read((char*)bytes, 2))
    {
        instr = bytes[1] | bytes[0] << 8;
        result.push_back(instr);
    }

    return result;
}

