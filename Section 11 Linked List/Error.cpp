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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  
        ListNode *third=NULL,*last=NULL;
        if(list1->val < list2->val){
            last=third=list1;
            list1=list1->next;
             // last->next=NULL;
        }else{
            last=third=list2;
            list2=list2->next;
            last->next=NULL;
        }
        while(list1 and list2){
       
             if(list1->val < list2->val){
                 last->next=list1;
                 last=list1;
                 list1=list1->next;
                 last->next=NULL;
             }else{
                  last->next=list2;
                 last=list2;
                 list2=list2->next;
                 last->next=NULL;
             }
        }
            if(list1) last->next=list1;
            if(list2) last->next=list2;
        return third;
    }
};

// if(l1 == NULL){
// 			return l2;
// 		}
// 		if(l2 == NULL){
// 			return l1;
// 		}
// 		ListNode* newHead = NULL;
// 		ListNode* newTail = NULL;
// 		if(l1->val < l2->val){
// 			newHead = l1;
// 			newTail = l1;
// 			l1 = l1->next;
// 		}
// 		else{
// 			newHead = l2;
// 			newTail = l2;
// 			l2 = l2->next;
// 		}
// 		while(l1 != NULL and l2 != NULL){
// 			if(l1->val < l2->val){
// 				newTail->next = l1;
// 				newTail = newTail->next;
// 				l1 = l1->next;
// 			}
// 			else{
// 				newTail->next = l2;
// 				newTail = newTail->next;
// 				l2 = l2->next;
// 			}
// 		}
// 		if(l1 != NULL){
// 			newTail->next = l1;
// 			l1 = l1->next;
// 		}
// 		if(l2 != NULL){
// 			newTail->next = l2;
// 		}
// 		return newHead;
// 	}