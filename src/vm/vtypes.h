#ifndef VTYPES_H
#define VTYPES_H

using u8  = unsigned char;    // At least 8-bits
using u16 = unsigned short;   // At least 16-bits   -  (Usually)

namespace violet
{

    const unsigned int REGS_N  {3};

    // Instructions
    const unsigned int i_halt  {0};
    const unsigned int i_loadi {0x1};
    const unsigned int i_add   {0x2};

    struct instruction
    {
        unsigned int code;
        unsigned int r0;
        unsigned int r1;
        unsigned int r2;
        int imm;
    };

}
#endif // VTYPES_H

