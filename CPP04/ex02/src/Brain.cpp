#include "Brain.hpp"
#include <cstdio>
Brain::Brain()  : _index(0)
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

    this->_index = toCopy._index;
    while (i < 100)
    {
        this->_ideas[i] = toCopy._ideas[i];
        i++;
    }
    return *this;
}

void    Brain::setIdea(std::string  idea)
{
    if (this->_index == 100)
        this->_index = 0;
    this->_ideas[_index] = idea;
    ++this->_index;
}

void    Brain::printIdeas()
{
    int i = 0;

    while (this->_ideas[i] != "Empty mind" && i < 100)
    {
        std::cout << this->_ideas[i] << std::endl;
        i++;
    }
}