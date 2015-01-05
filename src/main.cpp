#include <vector>

#include "vm/vm.h"
#include "utils.h"

using namespace violet;

int main(int argc, char *argv[])
{
    int vm_res;
    const std::vector<u16> program = utils::load_program_file(argv[1]);
    Vm *vm = new Vm(program);
    vm_res = vm->run();

    return vm_res;
}
