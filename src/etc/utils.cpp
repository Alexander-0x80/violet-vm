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

            while(file.read(reinterpret_cast<char*>(bytes), 2))
            {
                // Little endian
                instr = bytes[0] | bytes[1] << 8;
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

        int write_program_file(
                const std::string filename,
                const std::vector<unsigned int> program)
        {
            std::ofstream out(filename, std::ios::trunc | std::ios::binary);
            if (out.fail())
            {
                std::cerr << "Could not write program file" << std::endl;
                return 1;
            }

            for (auto i : program)
            {
                out.write(reinterpret_cast<const char *>(&i), sizeof(u16));
            }

            return 0;
        }
    }

}
