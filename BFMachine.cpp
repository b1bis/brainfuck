#include "BFMachine.hpp"

namespace BF
{
    void Machine::Execute(std::string code)
    {
        m_memory.clear();
        m_memory.resize(30000);
        m_pointer = m_memory.begin();
        for(auto it = code.begin(); it != code.end(); ++it)
        {
            switch(*it)
            {
                case '>':
                    if(m_pointer == m_memory.end() - 1) m_pointer = m_memory.begin();
                    else ++m_pointer;
                    break;
                case '<':
                    if(m_pointer == m_memory.begin()) m_pointer = m_memory.end();
                    --m_pointer;
                    break;
                case '+':
                    ++(*m_pointer);
                    break;
                case '-':
                    --(*m_pointer);
                    break;
                case '.':
                    m_output << static_cast<char>(*m_pointer);
                    break;
                case ',':
                    char i; 
                    if(m_input.read(&i, 1)) *m_pointer = i;
                    else *m_pointer = 0;
                    break;
                case '[':
                    if(*m_pointer == 0)
                    {
                        int counter = 0;
                        while(it != code.end())
                        {
                            if(*it == '[')
                            {
                                counter++;
                            }
                            else if(*it == ']')
                            {
                                counter--;
                                if(counter == 0)
                                {
                                    break;
                                }
                            }
                            ++it;
                        }
                    }
                    else
                    {
                        m_stack.push_back(it);
                    }
                    
                    break;
                case ']':
                    if(*m_pointer == 0)
                    {
                        m_stack.pop_back();
                    }
                    else
                    {
                        it = m_stack.back();
                    }
                    break;
                default:
                    break;
            }
        }
    }
}