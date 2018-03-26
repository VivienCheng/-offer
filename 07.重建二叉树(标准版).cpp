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

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode(int val):m_nValue(val),m_pLeft(nullptr),m_pRight(nullptr){}
};

BinaryTreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);

BinaryTreeNode* Construct(int *preorder, int *inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode(rootValue);

    if(startPreorder == endPreorder) //两数组相同时，即当tartPreorder和endPreorder指向同一地址时
    {
        if(*startPreorder == *startInorder)
            return root;
        else {                        //说明输入的前序序列和中序序列不对
            cout << "wrong input!" <<endl;
            return root;}
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)//找根节点找到了最后还没有找到，说明输入的前序序列和中序序列不对
    {
        cout << "wrong input!" << endl;
        return root;
    }

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;
}

void PrintTree(BinaryTreeNode *root){
    if(root != nullptr){
        PrintTree(root->m_pLeft);
        cout << root->m_nValue << endl;
        PrintTree(root->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode *root)
{
    delete root;
    root = nullptr;
}
// ====================测试代码====================
void Test( int* preorder, int* inorder, int length)
{

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

int main()
{

    const int length = 7;
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 8, 1, 6, 3, 7};

    Test(preorder,inorder,7);
    return 0;
}