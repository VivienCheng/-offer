#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;
#define inf 0x3f3f3f3f

struct ListNode{
    int val;
    ListNode *nextNode;
    ListNode(int val):val(val),nextNode(nullptr){}
};

void DeleteNode(ListNode **pListHead,ListNode *pToBeDeleted)
{
  if(pListHead == nullptr || *pListHead == nullptr || pToBeDeleted == nullptr){
    return;
  }

  if(*pListHead != pToBeDeleted) {

    if(pToBeDeleted->nextNode != nullptr) {
      ListNode *pNextNode = pToBeDeleted->nextNode;

      /*pToBeDeleted = pNextNode;*/

      pToBeDeleted->val = pNextNode->val;
      pToBeDeleted->nextNode = pNextNode->nextNode;

      delete pNextNode;
      pNextNode = nullptr;
    }else{
      ListNode *pNode = *pListHead;
      while(pNode->nextNode != pToBeDeleted){
        pNode = pNode->nextNode;
      }
      pNode->nextNode = nullptr; // 千万记得其前一个节点的nextNode要指向空

      //该写法错误，该写法表示pNode是最后一个节点，但是我们想要的是：pNode是最后一个节点的前一个节点。
     /* while(pNode->nextNode != nullptr){
        pNode = pNode->nextNode;
      }*/
      delete pNode;
      pNode = nullptr;
    }
  }
  else{
    delete pToBeDeleted;
    pToBeDeleted = nullptr;

    delete *pListHead;
    *pListHead = nullptr;
  }

  return;
}