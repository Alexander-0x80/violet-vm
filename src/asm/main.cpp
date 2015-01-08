#include <vector>

#include <etc/utils.h>
#include "vlasm.h"

using namespace violet;

int main(int argc, char *argv[])
{
    const std::vector<std::string> source = utils::load_source_file(argv[1]);
    const std::vector<unsigned int> program = vlasm::parse_source(source);

    return utils::write_program_file(argv[2], program);
}
