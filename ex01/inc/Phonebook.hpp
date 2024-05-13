#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Phonebook
{	
public:
	Phonebook();
	~Phonebook();

	void	add();
	void	search();

private:
	Contact _contacts[8];
};

Phonebook::Phonebook() {}

Phonebook::~Phonebook() {}


#endif