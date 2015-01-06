#include "utils.h"

namespace violet
{

    namespace utils
    {
        std::vector<u16>
        load_program_file(const std::string filename)
        {
            u16 instr;
            u8  bytes[2];
            std::vector<u16> result;

            std::ifstream file(filename, std::ios::binary);
            if (file.fail())
            {
                std::cerr << "Could not load program" << std::endl;
                return result;
            }

            while(file.read((char*)bytes, 2))
            {
                instr = bytes[1] | bytes[0] << 8;
                result.push_back(instr);
            }

            return result;
        }

        std::vector<std::string>
        load_source_file(const std::string filename)
        {
            std::string line;
            std::vector<std::string> result;

            std::ifstream file(filename);
            if (file.fail())
            {
                std::cerr << "Could not load source" << std::endl;
                return result;
            }

            while(std::getline(file, line))
            {
                result.push_back(line);
            }

            return result;
        }
    }

}
