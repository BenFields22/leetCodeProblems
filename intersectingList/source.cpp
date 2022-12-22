#include <iostream>
#include <unordered_map>

typedef struct ListNode{
    ListNode* next;
    int val;
} ListNode;

ListNode* intersection(ListNode* head1, ListNode* head2){
    std::unordered_map<ListNode*,int> mymap;
    ListNode* curr = head1;
    while (curr) {
        mymap[curr]=1;
        curr=curr->next;
    }
    curr=head2;
    while (curr) {
        if (mymap[curr]) {
            return curr;
        }
        curr=curr->next;
    }
    return NULL;
}

int main(int argc, char** argv){
    ListNode* head = new ListNode();     
    ListNode* head2 = new ListNode();
    head->val = 3;
    ListNode* second = new ListNode();
    second->val = 5;
    ListNode* third = new ListNode();
    third->val = 12;
    ListNode* fourth = new ListNode();
    fourth->val = 22;
    ListNode* fifth = new ListNode();
    fifth->val = 33;
    head2->val=88;
    head->next = second;
    second->next = third;
    third->next=fourth;
    fourth->next=NULL;
    head2->next=fifth;
    fifth->next=fourth;
    // list1 = 3 -> 5 -> 12 -> 22->NULL
    // list2 =     88 -> 33 -> ^
    ListNode* ans = intersection(head,head2);
    ListNode* curr = head;
    std::cout << "First List: " ;
    while (curr) {
        std::cout << curr->val << " "; 
        curr=curr->next;
    }
    std::cout  << std::endl;
    curr=head2;
    std::cout << "Second List: " ;
    while (curr) {
        std::cout << curr->val << " "; 
        curr=curr->next;
    }
    std::cout  << std::endl;

    std::cout << "The intersection is: " <<ans->val<< std::endl;
    return 0;
}
