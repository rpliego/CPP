#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog &toCopy);
        Dog &operator=(const Dog &toCopy);

        void    makeSound();
};

#endif