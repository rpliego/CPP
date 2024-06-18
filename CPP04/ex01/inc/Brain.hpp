#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
        int index;

    public:
        Brain();
        ~Brain();
        Brain(const Brain& toCopy);
        Brain&   operator=(const Brain& toCopy);
        
       void    setIdea(std::string idea);
       void    printIdeas();

};

#endif