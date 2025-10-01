#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using std::string;

// Функция для чтения строки и преобразования в очередь токенов в постфиксной
// нотации
std::queue<string> readline(const string);
// Функция для вычисления значения постфиксного выражения
double computePostfix(std::queue<string> postfix);

int main(int argc, char* argv[]) {
  string line;
  string txt_file = "input.txt";
  if (argc > 1) {
    txt_file = argv[1];
  }
  // Открываем входной и выходной файлы
  std::ifstream in(txt_file);
  std::ofstream out("output.txt");

  // Проверяем, что файлы успешно открыты
  if (in.is_open() && out.is_open()) {
    // Построчно читаем входной файл
    while (std::getline(in, line)) {
      // Записываем в выходной файл исходную строку и результат вычислений
      out << line << " = " << computePostfix(readline(line)) << std::endl;
    }
    std::cout << "Successful execution!" << std::endl;
  } else {
    std::cout << "Stream error!" << std::endl;
  }
  return 0;
}

// Разбивает строку на токены (числа и операторы) и возвращает очередь
std::queue<string> readline(const string expr) {
  std::queue<string> output;
  for (size_t i = 0; i < expr.length(); ++i) {
    char token = expr[i];
    // Если символ - цифра, извлекаем все число
    if (std::isdigit(token)) {
      string number;
      while (i < expr.length() && isdigit(expr[i])) {
        number += expr[i];
        ++i;
      }
      --i;  // Корректируем индекс после цикла
      output.push(number);
    }
    // Если символ - оператор, добавляем его как отдельный токен
    else if (token == '+' || token == '-' || token == '*' || token == '/') {
      output.push(string(1, token));
    }
  }
  return output;
}

// Вычисляет значение постфиксного выражения
double computePostfix(std::queue<string> postfix) {
  std::stack<double> values;  // Стек для хранения промежуточных результатов
  while (!postfix.empty()) {
    string token = postfix.front();
    postfix.pop();

    // Если токен - число, преобразуем и помещаем в стек
    if (isdigit(token[0])) {
      values.push(stod(token));
    }
    // Если токен - оператор, извлекаем два операнда и выполняем операцию
    else {
      double b = values.top();
      values.pop();
      double a = values.top();
      values.pop();

      // Выполняем соответствующую операцию и помещаем результат в стек
      if (token == "+") {
        values.push(a + b);
      } else if (token == "-") {
        values.push(a - b);
      } else if (token == "*") {
        values.push(a * b);
      } else if (token == "/") {
        values.push(a / b);
      }
    }
  }
  // Возвращаем итоговый результат
  return values.top();
}
