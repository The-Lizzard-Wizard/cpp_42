#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "../hpp/Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data *data);
		static Data *deserialize(uintptr_t data);
	private:
		Serializer();
		Serializer(Serializer &src);
		~Serializer();
		Serializer &operator=(Serializer &src);
};

#endif //SERIALIZER_HPP