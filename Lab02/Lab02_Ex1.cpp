int findMax(const vector<int>& arr) 
{ 
 // TODO: Add counts for initialization 
 int max = arr[0]; //一次陣列存取+一次賦值，共兩步 
  
 // TODO: Add counts for loop operations 
 for (int i = 1; i < arr.size(); i++) { //for迴圈初始化賦值，共一步 
 // TODO: Add counts for comparison and assignment  if (arr[i] > max) { 
 max = arr[i]; 
 } 
 } 
 // TODO: Add counts for return 
 return max; 
}

// Total operations:
// 3 (initial) + 6 * (n-1) (loop) + 1 (exit) + 1 (return)
// = 6n - 1 operations
// Therefore, O(n) complexity
