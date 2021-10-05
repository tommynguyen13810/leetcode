ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return head;
    ListNode *t = head, *p = head->next;
    int pre = head->val;
    while(p) {
        if(pre != p->val) {
            t->next = p;
            pre = p->val;
            t = t->next;
        }
        p = p->next;
    }
    t->next = NULL;
    return head;
}

//iterative
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* cur = dummy;
	int duplicate;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			duplicate = cur->next->val;
			while (cur->next && cur->next->val == duplicate) 
				cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	return dummy->next;
}

//recursive
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return 0;
    if (!head->next) return head;
    int val = head->val;
    ListNode* p = head->next;
    if (p->val != val) { head->next = deleteDuplicates(p); return head;} 
    else { 
        while (p && p->val == val) p = p->next; 
        return deleteDuplicates(p); 
    }
}