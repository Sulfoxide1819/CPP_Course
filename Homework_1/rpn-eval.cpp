#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>


using std::string;

std::queue<string> readline(const string);
double computePostfix(std::queue<string> postfix);

int main(int argc , char* argv[]){
	string line;

	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in.is_open() && out.is_open()){
		while (std::getline(in,line)){
			out << line << " = " << computePostfix(readline(line)) << std::endl;
		}
		std::cout << "Successful execution!" << std::endl;	
	}
	else {
		std::cout << "Stream error!" << std::endl;
	}
	return 0;
}



std::queue<string> readline(const string expr){
	std::queue<string> output;
	for (size_t i = 0; i < expr.length(); ++i){
		char token = expr[i];
		if (std::isdigit(token)) {
			string number;
			while (i < expr.length() && isdigit(expr[i] )) {
				number += expr[i];
				++i;
			}
			--i;
			output.push(number);
		}
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			output.push(string(1,token));
		}
	}
	return output;
}

double computePostfix(std::queue<string> postfix){
	std::stack<double> values;
	while (!postfix.empty()) {
		string token = postfix.front();
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
		return values.top();
	}
}
