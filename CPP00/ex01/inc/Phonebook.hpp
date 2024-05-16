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
	int		_index;
	int		_counter;
};



#endif