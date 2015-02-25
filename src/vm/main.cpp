#include <vector>

#include "vm/vm.h"
#include "etc/utils.h"

using namespace violet;

int main(int argc, char *argv[])
{
    int vm_res;
    const std::vector<u16> program = utils::load_program_file(argv[1]);
    Vm vm(program);
    vm_res = vm.run();

    for (auto r : vm.dump_regs())
    {
        std::cout << r << " ";
    }   std::cout << std::endl;

    return vm_res;
}
