#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // 用於 std::max
#include <climits>   // 用於 INT_MIN

using namespace std;

// 樹的節點
class TreeNode {
public:
 int value;             // 節點的值
 TreeNode* left;        // 左子節點
 TreeNode* right;       // 右子節點
 TreeNode(int val) : value(val), left(NULL), right(NULL) {} // 初始化節點
};

// 樹結構
class BinaryTree {
public:
 TreeNode* root;
 BinaryTree() : root(NULL) {} // 初始化樹

 // 用陣列構建二元樹
 void buildTree(vector<int>& arr) {
  if (arr.empty()) return;

  queue<TreeNode*> q; // 儲存待處理的節點
  root = new TreeNode(arr[0]); // 建立根節點 (陣列第一個元素)
  q.push(root); // 將根節點加入queue

  size_t i = 1; // 陣列索引
  while (!q.empty() && i<arr.size()) {
   TreeNode* current = q.front(); // 取出隊列中的節點
   q.pop();

   // 添加左子節點
   if (i < arr.size()) {
    current->left = new TreeNode(arr[i]);
    q.push(current->left); // 將左子節點加入queue
    i++;
   }
   // 添加右子節點
   if (i < arr.size()) {
    current->right = new TreeNode(arr[i]);
    q.push(current->right); // 將右子節點加入queue
    i++;
   }
  }
 }
 
 // 中序遍歷
 void inorderTraversal(TreeNode* node) {
  if (node == NULL) return; // 如果節點為空，忽略

  inorderTraversal(node->left);  // 遍歷左子樹
  cout << node->value << " ";    // 訪問當前節點
  inorderTraversal(node->right); // 遍歷右子樹
 }

 //Q1:後序遍歷 (Left -> Right -> Root)
 void postorderTraversal(TreeNode* node) {
  if (node == NULL) return;
  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->value << " ";
 }
  
  // Q2: 尋找子樹最大值 (遞迴)
  int findMax(TreeNode* node) {
   if (node == nullptr) return INT_MIN;
   int res = node->value;
   int leftRes = findMax(node->left);
   int rightRes = findMax(node->right);
   return max({res, leftRes, rightRes});
  }
};

int main() {
 BinaryTree tree; // 宣告二元樹

 // 輸入陣列用於構建樹，NULL 表示空子節點
 vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };

 tree.buildTree(arr); // 建立樹

 // Q1結果:
 cout << "Q1輸出結果:" << endl; 
 cout << "Inorder Traversal: ";
 tree.inorderTraversal(tree.root);
 cout << endl;
    
 cout << "Postorder Traversal: ";
 tree.postorderTraversal(tree.root);
 cout << "\n" << endl;
 
 // Q2結果:
 cout << "Q2輸出結果:" << endl;
 cout << "Inorder Traversal: ";
 tree.inorderTraversal(tree.root);
 cout << endl;

 int leftMax = tree.findMax(tree.root->left);
 int rightMax = tree.findMax(tree.root->right);
 cout << "Max left subtree Value: " << (leftMax == INT_MIN ? 0 : leftMax) << endl;
 cout << "Max right subtree Value: " << (rightMax == INT_MIN ? 0 : rightMax) << endl;
    
 return 0;
}

