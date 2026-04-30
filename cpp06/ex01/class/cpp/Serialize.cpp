#include "../hpp/Serialize.hpp"
#include <stdint.h>

Serializer::Serializer()
{}

Serializer::Serializer(Serializer &src)
{
	(void)src;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(Serializer &src)
{
	(void)src;
	return (*this);
}


uintptr_t Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize(uintptr_t data)
{
	return (reinterpret_cast<Data *>(data));
}
