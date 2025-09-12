#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

std::queue<std::string> readline(const std::string&);
double computePostfix(std::queue<std::string>);

int main(int argc, char* argv[]) {
	std::string expr;
	
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in.is_open() && out.is_open()) {
		while (std::getline(in, expr)) 
		{
			out << expr << " = " << computePostfix( readline(expr) ) << std::endl;
				
		}
	}

}

std::queue<std::string> readline(const std::string& expr){
	std::queue<std::string> output;
	
	for (size_t i = 0; i < expr.length(); ++i){
		char token = expr[i];

		if (isdigit(token)) {
			std::string number;
			while (i < expr.length() && (isdigit(expr[i]))) {
				number += expr[i];
				++i;
			}
			--i;
			output.push(number);
		}
		if (token == '+' || token == '-' || token == '*' || token == '/'){
			output.push(std::string(1,token));
		}
	}
	return output;
};

double computePostfix(std::queue<std::string> postfix)
{
	std::stack<double> values;
	while (!postfix.empty()) {
		std::string token = postfix.front();
		postfix.pop();

		if (isdigit(token[0])) {
			values.push(stod(token));
		}
		else {
			double b = values.top();
			values.pop();
			double a = values.top();
			values.pop();

			if (token == "+") {
				values.push(a + b);
			} else if (token == "-") {
				values.push(a - b);
			}
			else if (token == "*") {
				values.push(a * b);
			}
			else if (token == "/") {
				values.push(a / b);
			}
		}
	}

	return values.top();
}


