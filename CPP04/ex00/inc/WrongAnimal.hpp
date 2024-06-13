#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &toCopy);
        WrongAnimal  &operator=(const WrongAnimal &toCopy);

        WrongAnimal(std::string type);


        void            setType(const std::string newType);
        std::string     getType() const;

        virtual void    makeSound() const;
};

#endif