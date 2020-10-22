#pragma once

#include <cstdint>
#include <iostream>
#include <exception>
#include <vector>

namespace BF
{
    class Machine
    {
    public:
        using pointer = std::vector<std::uint8_t>::iterator;
        using const_pointer = std::vector<std::uint8_t>::const_iterator;

        Machine() = default;
        Machine(std::ostream& output, std::istream& input) : 
            m_output{output}, m_input{input} {}

        void Execute(std::string code);

    private:
        void ExecuteOperator(char o);

        std::ostream& m_output = std::cout;
        std::istream& m_input  = std::cin;

        std::vector<std::uint8_t> m_memory;
        std::vector<std::string::iterator> m_stack;
        pointer m_pointer;
    };
}