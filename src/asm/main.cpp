#include <vector>

#include <etc/utils.h>
#include "vlasm.h"

using namespace violet;

int main(int argc, char *argv[])
{
    std::ofstream out(argv[2], std::ios::binary);
    std::vector<unsigned int>::iterator it;
    const std::vector<std::string> source = utils::load_source_file(argv[1]);
    const std::vector<unsigned int> program = vlasm::parse_source(source);

    
    return 0;
}
