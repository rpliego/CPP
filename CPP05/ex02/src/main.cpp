#include "Bureaucrat.hpp"

int main(void)
{
    AForm f("form", 1, 1);
    Bureaucrat a("bob", 2);

    try
    {
        a.signForm(f);
        std::cout << f << std::endl;
        a.signForm(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bureaucrat "<< a.getName() << " couldnt sign " 
        << f.getName() << " because " << e.what() << '\n';
    }
    

    return (0);
}
