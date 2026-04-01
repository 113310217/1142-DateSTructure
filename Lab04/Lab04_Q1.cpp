#include <iostream>
#include <string>
using namespace std;

//定義一個名為 Student 的 Struct 
struct Student {
 int id;
 string name;
 int chinese;
 int english;
 int math;
 int social;
 int science;
};

void updateMath(Student &s) { //將s改成&s， &s代表s是傳入變數的別名，可直接操作記憶，修改原始變數 
 s.math = 100; //因為是引用，所以這裡的修改會引響到 main裡的原始變數  
}

void printStudent(Student s) {
 cout << "學生編號: " << s.id << endl;
 cout << "姓名: " << s.name << endl;
 cout << "數學成績: " << s.math << endl;
}

int main() 
{
 //宣告一個 Student 型態的變數，名稱為one 
 Student one;
 
 //使用[.]存取成員，並賦予變數的初始值 
 one.id = 1; 
 one.name = "張小美";
 one.chinese = 77;
 one.english = 83;
 one.math = 86; //將初始值設為 86 
 one.social = 68;
 one.science = 91;
 
 //呼叫函數並傳入one，因為函數參數是 Student &s，所以s會直接指向one的地址updateMath(one) 
 updateMath(one);
 
 //列印出結果，且此時的 one.math已被修改成 100 
 printStudent(one);
 return 0;
}
