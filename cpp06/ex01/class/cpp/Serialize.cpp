#include "../hpp/Serialize.hpp"

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
