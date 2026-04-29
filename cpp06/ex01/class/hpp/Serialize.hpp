#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer
{
	public:
	private:
		Serializer();
		Serializer(Serializer &src);
		~Serializer();
		Serializer &operator=(Serializer &src);
};

#endif //SERIALIZER_HPP