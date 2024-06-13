#include "Brain.hpp"

Brain::Brain()  : index(0)
{
    std::cout << "Brain Default Constructor called" << std::endl;

    int i = 0;

    while (i < 100)
    {
        this->_ideas[i] = "Empty mind";
        i++;
    }
}

Brain::~Brain() {std::cout << "Brain Default Destructor called" << std::endl;}

Brain::Brain(const Brain& toCopy)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    *this = toCopy;
}

Brain&  Brain::operator=(const Brain& toCopy)
{
    int i = 0;

    this->index = toCopy.index;
    while (i < 100)
    {
        this->_ideas[i] = toCopy._ideas[i];
        i++;
    }
    return *this;
}

void    Brain::setIdea(std::string  idea)
{
    if (this->index == 100)
        this->index = 0;
    this->_ideas[index] = idea;
    ++this->index;
}

void    Brain::printIdeas()
{
    int i = 0;

    do
    {
        std::cout << this->_ideas[i] << std::endl;
        i++;
    } while (this->_ideas[i] != "Empty mind");
}