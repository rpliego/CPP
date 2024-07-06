#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    PresidentialPardonForm a;
    Bureaucrat bob("bob", 1);

    bob.signForm(a);
    bob.executeForm(a);

    return (0);
}
