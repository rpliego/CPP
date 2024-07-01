#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- MAIN FROM SUBJECT: ---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	
		ICharacter* me = new Character("me");
	
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;
	
		ICharacter* bob = new Character("bob");
	
		me->use(0, *bob);
		me->use(1, *bob);
	
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING DIFFERENT TYPES OF MATERIA: ---" << std::endl;
	    AMateria* m1 = new Ice();
	    AMateria* m2 = new Cure();
	    Cure* c1 = new Cure();
	    Ice* i1 = new Ice();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(m1);
	    di->equip(m2);
	    di->equip(c1);
	    di->equip(i1);

	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

		delete m1;
		delete m2;
		delete c1;
		delete i1;
	    delete di;
	    delete bob;	
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING THE SAME OBJECT AND USING UNEXISTING: ---" << std::endl;
	    AMateria* m1 = new Ice();
	    Cure* c1 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(m1);
	    di->equip(m1);
	    di->equip(c1);
	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(3, *bob);
	    di->use(7, *bob);

		delete m1;
		delete c1;
	    delete di;
	    delete bob;	
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING MORE THAN 4 MATERIAS: ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	    di->equip(c2);
	    di->equip(c3);
	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

		delete i1;
		delete i2;
		delete i3;
		delete c1;
		delete c2;
		delete c3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- UNEQUIPPING AND WRONG UNEQUIPPING: ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    di->unequip(0);
	    di->unequip(2);
	    di->unequip(2);
	    di->unequip(7);

	    di->equip(c2);
	    di->equip(c3);

	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

		delete i1;
		delete i2;
		delete i3;
		delete c1;
		delete c2;
		delete c3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- CHECKING IF CHARACTER'S COPIES ARE DEEP (WITH '='): ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    Character* di = new Character("Di");
	    Character* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    *bob = *di;

	    di->unequip(0);
	    di->unequip(2);
	    di->equip(c2);
	    di->equip(c3);

	    std::cout << "--- use() of di:" << std::endl;
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    std::cout << "--- use() of bob (now his name is also Di):" << std::endl;
	    bob->use(0, *di);
	    bob->use(1, *di);
	    bob->use(2, *di);
	    bob->use(3, *di);

		delete i1;
		delete i2;
		delete i3;
		delete c1;
		delete c2;
		delete c3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- CHECKING IF CHARACTER'S COPIES ARE DEEP (WITH COPY CTOR): ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    Character* di = new Character("Di");
	    
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	   	Character* bob = new Character(*di);

	    di->unequip(0);
	    di->unequip(2);
	    di->equip(c2);
	    di->equip(c3);

	    std::cout << "--- use() of di:" << std::endl;
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    std::cout << "--- use() of bob (now his name is also Di):" << std::endl;
	    bob->use(0, *di);
	    bob->use(1, *di);
	    bob->use(2, *di);
	    bob->use(3, *di);

		delete i1;
		delete i2;
		delete i3;
		delete c1;
		delete c2;
		delete c3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- CHECKING MATERIASOURCE CLASS: ---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		Character* bob = new Character("Bob");
		Ice* i1 = new Ice();
		Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();

		src->learnMateria(i1);
		src->learnMateria(i2);
		src->learnMateria(i3);
		src->learnMateria(c1);
		src->learnMateria(c2);
		src->learnMateria(c3);

		AMateria* tmp;
		tmp = src->createMateria("ice");
		tmp->use(*bob);

		AMateria* tmp1;
		tmp1 = src->createMateria("cure");
		tmp1->use(*bob);
		
		AMateria* tmp2;
		tmp2 = src->createMateria("nonexist");
		if (tmp2)
			tmp2->use(*bob);
		else
			std::cout << "Materia hasnt been created" << std::endl;
		
		delete c2;
		delete c3;
		delete src;
		delete bob;
		delete tmp;
		delete tmp1;
		delete tmp2;
	}
	return (0);
}