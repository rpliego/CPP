#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &toCopy);
        Animal  &operator=(const Animal &toCopy);

        Animal(std::string type);


        void            setType(const std::string newType);
        std::string     getType() const;

        virtual void    makeSound() const;
};

#endif