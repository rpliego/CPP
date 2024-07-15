#include "Serializer.hpp"
#include "Data.hpp"
#include <cstring>



void initializeData(struct Data* dat) {

    dat->a = 3;
    dat->b = 54.24f;
    strcpy(dat->c, "hola");
}

int main()
{
    Data* dat = new Data;
    initializeData(dat);
	
    uintptr_t dataptr = Serializer::serialize(dat);
    std::cout << "The ptr of data is " << std::showbase << std::hex << dataptr << std::endl;

    Data* newdata = Serializer::deserialize(dataptr);

    std::cout << "The objects of newdata ptr:" << std::endl;
    std::cout << "newdata->a = " << std::dec << newdata->a << std::endl;
    std::cout << "newdata->b = " << newdata->b << std::endl;
	std::cout << "newdata->c = " << newdata->c << std::endl;

	delete dat;
    return 0;
}