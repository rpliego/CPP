#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _brain;

    public:
        Cat();
        ~Cat();
        Cat(const Cat &toCopy);
        Cat &operator=(const Cat &toCopy);

        void    makeSound() const;

        void    setIdea(std::string idea);
        void    printIdeas();
};

#endif