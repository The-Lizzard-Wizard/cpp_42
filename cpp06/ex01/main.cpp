#include "class/hpp/Data.hpp"
#include "class/hpp/Serialize.hpp"
#include <iostream>

int main()
{
    Data *data = new Data;
    data->value = 3;
    std::cout << data->value << std::endl;
    uintptr_t ptr = Serializer::serialize(data);

    Data *data2 = Serializer::deserialize(ptr);
    std::cout << data2->value << std::endl;


}