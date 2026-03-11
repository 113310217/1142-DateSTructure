int findMax(const vector<int>& arr) {
// TODO: Add counts for initialization

 int stepCount = 0 //假設步數
  
 int max = arr[0];
 stepCount++; //陣列存取arr[0]與賦值給max，1步 
// TODO: Add counts for loop operations

 stepCount++; //for迴圈初始化(i=1)，1步 
for (int i = 1; i < arr.size(); i++) {
// TODO: Add counts for comparison and assignment

 stepCount++; //比較i<arr.size()，1步
 
 stepCount++; //比較arr[i]>max，1步 
 if (arr[i] > max) {
  max = arr[i];
  stepCount++; //賦值運算(將新最大值存入max)，1步 
 }
 stepCount++; //增量運算(i++)，1步 
}
// TODO: Add counts for return

stepCount++; //for迴圈結束時最後一次失敗的比較，1步 
stepCount++; //return動作，1步 
return max;
}
// Total operations(總運算次數):
// 2 (初始化) + 4 * (n-1) (for迴圈內的運算) + 1 (跳出迴圈) + 1 (return回傳結果)
// = 4 + 4(n-1) operations
// = 4n operations
// Therefore, O(n) complexity
