#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class TextEditor {
  string left;
  string right;

 public:
  TextEditor() = default;
  void print() const;
  void addText(const string& text);
  int deleteText(int k);
  string cursorLeft(int k);
  string cursorRight(int k);
};

void te_cli(TextEditor& text);
void printMenu();

int main(int argc, char* argv[]) {
  TextEditor text;
  te_cli(text);

  return 0;
}

using TE = TextEditor;
  void TE::print() const {
    std::cout << left;
    for (auto it = right.rbegin(); it != right.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
  }

  void TE::addText(const string& text) {
    left += text;
  }

  int TE::deleteText(int k) {
    k = std::min(k, static_cast<int>(left.size()));
    left.erase(left.end() - k, left.end());
    return k;
  }

  string TE::cursorLeft(int k) {
    k = std::min(k, static_cast<int>(left.size()));

    string move = left.substr(left.size() - k);
    std::reverse(move.begin(), move.end());
    right += move;

    left.erase(left.end() - k, left.end());

    return left;
  }

  string TE::cursorRight(int k) {
    k = std::min(k, static_cast<int>(right.size()));
    string move = right.substr(right.size() - k);
    std::reverse(move.begin(), move.end());
    left += move;

    right.erase(right.end() - k, right.end());

    return string(right.rbegin(), right.rend());
  }


void te_cli(TextEditor& text) {
  text.print();
  printMenu();
  bool exit = false;
  while (!exit) {
    short in = 0;
    std::cin >> in;
    switch (in) {
      case 0:{
        std::cout << "Exit?(1/0)\n";
        short exit_in = 1;
        std::cin >> exit_in;
        if (exit_in) {
          exit = true;
        }
        break;
	     }
      case 2:{
	string str;
        std::cout << "Enter a text:"; 
	std::cin >> str;
        std::cout << std::endl;
        text.addText(str);
        break;
	     }
      case 3:{
        std::cout << "Enter a number of characters:";
       	size_t n;
        std::cin >> n;
        std::cout << "\n" << text.deleteText(n) << "\n";
        break;
	     }
      case 4:{
        while (true) {
          std::cout << "Enter a shift:";
	  int shift;
          std::cin >> shift;
          if (shift < 0) {
            text.cursorLeft(-shift);
          }
          if (shift > 0) {
            text.cursorRight(shift);
          }
          break;
        }
        break;
	     }
      case 5:{
        text.print();
        break;
	     }
      case 1:
      default:
        printMenu();
        break;
    }
  }
}

void printMenu() {
  std::cout << "Use the following commands:\n"
            << "0 - to exit\n"
            << "1 - to print menu\n"
            << "2 - to add a text\n"
            << "3 - to delete some characters\n"
            << "4 - to move cursor\n"
            << "5 - to print text\n";
}
