#include <vector>

#include "vm.h"
#include "utils.h"

using namespace violet;

int main(int argc, char *argv[])
{
    const std::vector<u16> program = utils::load_program_file("t.s");
    Vm *vm = new Vm(program);
    vm->run();

    return 0;
}
