#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

#include "vm.h"

int main(int argc, char *argv[])
{
    Vm *vm = new Vm("t.s");
    vm->run();

    return 0;
}
