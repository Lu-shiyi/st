#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void deleteListNode(ListNode *p, ListNode *q){
    p->next = q->next;
    q->next = NULL;
    delete [] q;
}

int main(){
    int n;
    cin>>n;
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for(int i=1;i<n;i++){
        ListNode *q = new ListNode(i);
        p->next = q;
        p = q;
    }
    p->next = head;
    int count = 0;
    ListNode *node = head;
    while(count!=n-2){
        deleteListNode(node->next, node->next->next);
        node = node->next->next;
        count++;
    }
    cout<<node->next->val<<endl;
    return 0;
}