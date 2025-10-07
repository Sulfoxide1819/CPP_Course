#include <iostream>
#include <string>

using std::string;

class String {
	string str;
	public:
	String(const string& str):str(str){}

	class StrProxy {
		const String& parent;
		size_t start;
		public:
		StrProxy(const String& s, size_t i): parent(s), start(i){}
		
		String operator[](size_t end) const {
			size_t len = end - start;
			string substr = parent.str.substr(start, len);
			return String(substr);
		}	
	
	
	};

	StrProxy operator[](size_t start) const {
		return StrProxy(*this, start);
	}
	const string& get() const {return str;}

};

int main(){
	String string("hello");
	std::cout << "hello\n";
	String substr = string[1][4];
        std::cout << "substr 'ell':"<< substr.get() << "\n";
	String str = string[1][2];
	std::cout << "a char:"<< str.get() << "\n";
	String empty = string[1][1];
	std::cout << "empty:" << empty.get() << "\n";
	

}
