#include <string>

class Harl
{
	public:
		Harl();
		void Complain(std::string level);
	private: 
		void Debug(void);
		void Info(void);
		void Warning(void);
		void Error(void);
};