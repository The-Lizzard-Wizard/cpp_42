#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array &src);
		~Array();

		T &operator[](int i);
		size_t size();
	private:
		T *arr;
};

#endif //ARRAY_HPP