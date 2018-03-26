#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
#define inf 0x3f3f3f3f


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};

TreeNode *reConstructTree(vector<int> preOrder, vector<int> inOrder)
{
  int len_pre = preOrder.size(), len_in = inOrder.size();

  if(len_pre == 0 || len_in == 0 || len_pre != len_in){
    return nullptr;
  }

  //找到根节点，以及在中序序列中根节点的位置
  int root_val = preOrder[0];
  int root_ind = 0;
  TreeNode *tHead = new TreeNode(root_val);
   for(int i = 0 ; i < len_pre; ++i){
     if(inOrder[i] == root_val){
       root_ind = i;
       break;
     }
   }

  //确定左子树的前序中序 和 右子树的前序中序
  vector<int> left_pre, right_pre, left_in, right_in;

  for(int i = 0 ;i < root_ind; ++i){
    left_pre.push_back(preOrder[i+1]);
    left_in.push_back(inOrder[i]);
  }

  for(int i = root_ind+1; i < len_pre; ++i){
    right_pre.push_back(preOrder[i]);
    right_in.push_back(inOrder[i]);
  }

  //
  tHead->left = reConstructTree(left_pre,left_in);
  tHead->right = reConstructTree(right_pre,right_in);

  return tHead;
}

void printTree(TreeNode *root){
  if(root == nullptr){
    return;
  }
  printTree(root->left);
  cout << root-> val << endl;
  printTree(root->right);
}

int main()
{
  int pre[] = {1,2,4,7,3,5,6,8};
  int in[] = {4,7,2,1,5,3,8,6};


  vector<int> pre_order(pre,pre+8);
  vector<int> in_order( begin(in),end(in) );

  TreeNode *root = reConstructTree(pre_order, in_order);
  printTree(root);
  return 0;
}






