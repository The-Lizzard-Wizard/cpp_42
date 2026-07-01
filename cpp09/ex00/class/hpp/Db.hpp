#ifndef DB_HPP
#define DB_HPP

#include <map>
#include <string>
#include "../../utils.hpp"
#include "Input.hpp"

class Db
{
	public:
		Db();
		Db(str DbTxt);
		Db(const Db &src);
		Db &operator=(Db &src);

		void outFormInput(Input &Input);

		str getStr() const;
	private:
		str DbStr;
		std::map<str, float> dataBase;
};

#endif //DB_HPP