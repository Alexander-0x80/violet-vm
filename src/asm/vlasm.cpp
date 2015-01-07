#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "vlasm.h"

namespace violet
{
    namespace vlasm
    {
        std::vector<unsigned int>
        parse_source(const std::vector<std::string> source)
        {
            std::vector<unsigned int> program;

            for (auto line : source)
            {
                if (line[0] == comment) continue;
                std::vector<std::string> tokens = parse_line(line);
                program.push_back(parse_tokens(tokens));

            }

            return program;
        }

        std::vector<std::string>
        parse_line(const std::string line)
        {
            std::istringstream iss(line);
            std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                    std::istream_iterator<std::string>{}};

            return tokens;
        }

        unsigned int parse_tokens(const std::vector<std::string> tokens)
        {
            unsigned int opcode;

            if (tokens[0] == vlasm::i_halt)
            {
               opcode = violet::i_halt;
            }

            else if (tokens[0] == vlasm::i_loadi)
            {
                if (tokens.size() != 3) die("Invalid load operation");
                opcode = (violet::i_loadi      << 12) |
                         (parse_reg(tokens[1]) <<  8) |
                         std::stoi(tokens[2]) ;
            }

            else if (tokens[0] == vlasm::i_add)
            {
                if (tokens.size() != 4) die("Invalid addition operation");
                opcode = (violet::i_add << 12) |
                         (parse_reg(tokens[1]) << 8) |
                         (parse_reg(tokens[2]) << 4) |
                          parse_reg(tokens[3]);
            }

            else
            {
                die("Invalid instruction found");
            }


            return opcode;
        }

        void die(const char *message)
        {
            std::cerr << message << std::endl;
            exit(1);
        }

        unsigned int parse_reg(std::string reg_str)
        {
            std::unordered_map<std::string, unsigned int>::const_iterator
            r = registers.find(reg_str);

            if (r == registers.end()) die("Invalid register");
            return r->second;
        }
    }
}