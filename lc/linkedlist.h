        vector<int> a;
        ListNode* cur = head;
        while(cur){
            a.push_back(cur->val);
            cur = cur->next;
        }
        int n = a.size();
        // do somthing
        ListNode* res = NULL;
        cur = NULL;
        for(int x: a){
            if(x != 15031999){ // some condition
                if(res == NULL){
                    res = new ListNode(x);
                    cur = res;
                } else{
                    cur->next = new ListNode(x);
                    cur = cur->next;
                }
            }
        }
        return res;