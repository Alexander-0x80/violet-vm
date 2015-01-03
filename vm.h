#ifndef VM_H
#define VM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define REGS_N 4

#define IHALT  0
#define ILOADI 1
#define IADD   2

typedef unsigned char  u8;
typedef unsigned short u16;

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
    std::vector<u16> program;
    bool running;
    u16  regs[REGS_N];
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

#endif // VM_H
