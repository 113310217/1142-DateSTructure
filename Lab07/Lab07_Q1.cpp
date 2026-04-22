#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
 char data;  // 存儲字符 (運算子或括號)
 Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
 Node* top; // 指向堆疊頂端
public:
 Stack() { top = NULL; } // 初始化堆疊

 // Push 操作：將元素放入堆疊
 void push(char ch) {
  Node* newNode = new Node; // 創建新節點
  newNode->data = ch;       // 存入數據
  newNode->next = top;      // 讓新節點指向目前的頂端
  top = newNode;            // 更新頂端指標
 }

 // Pop 操作：移除並回傳頂端元素
 char pop() {
  if (isEmpty()) return '\0'; // 若堆疊為空，回傳空字符
   char ch = top->data;         // 取得頂端元素
   Node* temp = top;            // 暫存頂端節點
   top = top->next;             // 移動頂端指標
   delete temp;                 // 釋放記憶體
   return ch;                   // 回傳彈出的元素
 }

 // Peek 操作：取得頂端元素但不移除
 char peek() {
  return (top ? top->data : '\0');
 }

 // 判斷堆疊是否為空
 bool isEmpty() {
  return top == NULL;
 }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {
 if (op == '+' || op == '-') {
  return 1;
 }
 
 if (op == '*' || op == '/') {
  return 2;
 }
 
 return 0; // 對於括號或其他字元回傳 0
}

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
 Stack s;
 int j = 0; // 用於填寫 postfix 陣列的索引

 for (int i = 0; infix[i] != '\0'; i++) {
  char c = infix[i];

  // 如果是運算元 (字母或數字)，直接輸出到 postfix
  if (isalnum(c)) {
   postfix[j++] = c;
  }
  
  // 如果是左括號 '('，推入 Stack
  else if (c == '(') {
   s.push(c);
  }
  
  // 如果是右括號 ')'，彈出 Stack 直到遇見 '('
  else if (c == ')') {
   while (!s.isEmpty() && s.peek() != '(') {
    postfix[j++] = s.pop();
   }
   s.pop(); // 彈出並捨棄 '('
  }
  
        // 如果是運算子 (+, -, *, /)
  else {
  // 當 Stack 不為空，且頂端運算子優先權大於或等於當前運算子
   while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
    postfix[j++] = s.pop();
   }
   s.push(c); // 將當前運算子推入 Stack
  }
 }

 // 將 Stack 中剩下的運算子全部彈出
 while (!s.isEmpty()) {
  postfix[j++] = s.pop();
 }

 postfix[j] = '\0'; // 在字串結尾加上結束符號
}

int main() {
 char infix[100], postfix[100];
 cout << "Enter an Infix expression: ";
 cin >> infix; // 輸入中序表達式

 InfixToPostfix(infix, postfix); // 轉換為後序表達式
 cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

 return 0;
}
