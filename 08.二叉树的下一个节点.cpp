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
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val),parent(nullptr),left(nullptr),right(nullptr){}
};

TreeNode * findTheNextNode(TreeNode *pNode)
{
    if(pNode == nullptr){
        return nullptr;
    }

    TreeNode *pNext = nullptr;
    if(pNode->right != nullptr){
        TreeNode *pCurrent = pNode->right;

        //-------------------------------------//
        while(pCurrent->left != nullptr){
            pCurrent = pCurrent->left;
        }
        pNext = pCurrent;

        //-------------------------------------//
    }
        //-------------------------------------//
    else if(pNode->right == nullptr && pNode->parent != nullptr){
       
        TreeNode *pCurrent = pNode;
        TreeNode *pParent = pNode->parent;

        while(pParent->right == pCurrent && pParent != nullptr){
            pCurrent = pParent;
            pParent = pParent->parent;
        }
        pNext = pParent;
    }

    return pNext;
}

int main()
{

}

