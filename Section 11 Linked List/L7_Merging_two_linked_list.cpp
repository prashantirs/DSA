#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

Node * first=NULL,* second=NULL,* third=NULL;

int Count(struct Node *p){
   int length=0;
    while(p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}
void Create1(int A[],int n){
    
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
}

void Create2(int A[],int n){
    
    Node *t,*last;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
}

void Display(struct Node *p){
    
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    
}

void Concatinate(struct Node *first,struct Node * second){
    Node *p=first;
    third=first;
    while(p->next!=NULL){ 
        p=p->next;
    }
    p->next=second;
}

void Merge(struct Node * first,struct Node * second){
    Node * last=NULL;
 if(first->data < second->data){
     third=last=first;
     first=first->next;
     last->next=NULL;
 }else{
     third=last=second;
     second=second->next;
     last->next=NULL;
 }
 //koi bhi list end ho jaye toh stop kr dena
 while(first!=NULL && second!=NULL){
     if(first->data < second->data){
         last->next=first;
         last=first;
         first=first->next;
         last->next=NULL;
     }else{
         last->next=second;
         last=second;
         second=second->next;
         last->next=NULL;
     }
 }
 if(first!=NULL) last->next=first;
 if(second!=NULL) last->next=second;

}



int main(){
    int A[]={2,20,30,40,50};
    int B[]={1,2,3,4,5};
    Create1(A,5);
    Create2(B,5);
    Display(first);
    cout<<endl;
    Display(second);
    cout<<endl;
    // Concatinate(first,second);
    // Display(third);
    // cout<<endl;
    Merge(first,second);
    Display(third);
    return 0;
}



//In leetcode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
// 		if(list1 == NULL){
// 			return list2;
// 		}
// 		if(list2 == NULL){
// 			return list1;
// 		}
//         ListNode *third=NULL,*last=NULL;
//         if(list1->val < list2->val){
//             last=third=list1;
//             list1=list1->next;
    
//         }else{
//             last=third=list2;
//             list2=list2->next;
           
//         }
//         while(list1 && list2){
       
//              if(list1->val < list2->val){
//                  last->next=list1;
//                  last=last->next;
//                  list1=list1->next;
//                
//              }else{
//                   last->next=list2;
//                   last=last->next;
//                  // last=list2;
//                  list2=list2->next;
//               
//              }
        
//         }
//             if(list1){
//                 last->next=list1;                
//             } 
//             if(list2) {
//                 last->next=list2;}
//         return third;
//     }
// };








