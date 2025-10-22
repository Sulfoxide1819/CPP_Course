#include <gtest/gtest.h>
#include "text_editor.h"

class TextEditorTest : public testing::Test {
protected:
  TextEditor editor;

 //void SetUp() override;
 //void TearDown() override;

};

// Test default constructor
TEST_F(TextEditorTest, DefaultConstructor) {
    EXPECT_EQ(editor.getLeft(), "");
    EXPECT_EQ(editor.getRight(), "");
    EXPECT_EQ(editor.getFullText(), "");
}

TEST_F(TextEditorTest, AddText) {
    editor.addText("Hello");
    EXPECT_EQ(editor.getLeft(), "Hello");
    EXPECT_EQ(editor.getRight(), "");
    EXPECT_EQ(editor.getFullText(), "Hello");

    editor.addText(" World");
    EXPECT_EQ(editor.getLeft(), "Hello World");
    EXPECT_EQ(editor.getFullText(), "Hello World");
}

TEST_F(TextEditorTest, DeleteText) {
    editor.addText("Hello World");

    int deleted = editor.deleteText(3);
    EXPECT_EQ(deleted, 3);
    EXPECT_EQ(editor.getLeft(), "Hello Wo");
    EXPECT_EQ(editor.getFullText(), "Hello Wo");

    deleted = editor.deleteText(10);
    EXPECT_EQ(deleted, 8);
    EXPECT_EQ(editor.getLeft(), "");
    EXPECT_EQ(editor.getFullText(), "");
}

TEST_F(TextEditorTest, CursorLeft) {
    editor.addText("Hello World");

    std::string result = editor.cursorLeft(3);
    EXPECT_EQ(result, "Hello Wo");
    EXPECT_EQ(editor.getLeft(), "Hello Wo");
    EXPECT_EQ(editor.getRight(), "dlr");
    EXPECT_EQ(editor.getFullText(), "Hello World");

    result = editor.cursorLeft(20);
    EXPECT_EQ(result, "");
    EXPECT_EQ(editor.getLeft(), "");
    EXPECT_EQ(editor.getRight(), "dlroW olleH"); 
}

TEST_F(TextEditorTest, CursorRight) {
    editor.addText("Hello");
    editor.cursorLeft(3); 

    std::string result = editor.cursorRight(2);
    EXPECT_EQ(result, "o");
    EXPECT_EQ(editor.getLeft(), "Hell");
    EXPECT_EQ(editor.getRight(), "o");
    EXPECT_EQ(editor.getFullText(), "Hello");

    // Перемещение больше, чем доступно
    result = editor.cursorRight(10);
    EXPECT_EQ(result, "");
    EXPECT_EQ(editor.getLeft(), "Hello");
    EXPECT_EQ(editor.getRight(), "");
}

TEST_F(TextEditorTest, EdgeCases) {
    // Удаление из пустого редактора
    EXPECT_EQ(editor.deleteText(5), 0);

    // Перемещение в пустом редакторе
    EXPECT_EQ(editor.cursorLeft(5), "");
    EXPECT_EQ(editor.cursorRight(5), "");
    //Add empty line
    editor.addText("");
    EXPECT_EQ(editor.getFullText(), "");
}

TEST_F(TextEditorTest, IntegrationTest) {
    editor.addText("The quick brown fox");
    EXPECT_EQ(editor.getFullText(), "The quick brown fox");

    editor.cursorLeft(4);
    EXPECT_EQ(editor.getFullText(), "The quick brown fox");

    editor.addText(" jumps");
    EXPECT_EQ(editor.getFullText(), "The quick brown jumps fox");

    int deleted = editor.deleteText(6);
    EXPECT_EQ(deleted, 6);
    EXPECT_EQ(editor.getFullText(), "The quick brown fox");

    editor.cursorRight(1);
    editor.addText("over the ");
    EXPECT_EQ(editor.getFullText(), "The quick brown over the fox");
}

TEST_F(TextEditorTest, SequentialOperations) {
    editor.addText("abc");
    editor.cursorLeft(1);
    editor.addText("d");
    editor.cursorRight(1);
    editor.addText("e");

    EXPECT_EQ(editor.getFullText(), "abdce");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
