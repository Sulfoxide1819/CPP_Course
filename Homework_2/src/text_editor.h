#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>

class TextEditor {
  std::string left;
  std::string right;

 public:
  TextEditor() = default;
  std::string getFullText() const;
  void print() const;
  void addText(const std::string& text);
  int deleteText(int k);
  std::string cursorLeft(int k);
  std::string cursorRight(int k);

  std::string getLeft() const { return left; }
  std::string getRight() const { return right; }
};

void te_cli(TextEditor& text);
void printMenu();

#endif
