```cpp
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        unsigned int count=0;
        ListNode* head=pListHead;
        ListNode* tail=pListHead;
        
        while(count<k){
            if(tail==NULL)
                return NULL;
            
            tail=tail->next;
            count++;
        }
        
        while(tail!=NULL){
            head=head->next;
            tail=tail->next;
        }
        return head;
    }
};
```