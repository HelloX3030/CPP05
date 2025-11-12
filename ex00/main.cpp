#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat("Smart af", -100);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat("Dumb af", 100000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
