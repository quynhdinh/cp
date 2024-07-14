vector<int> nodes;
        ListNode* cur = head;
        while(cur){
            nodes.push_back(cur->val);
            cur = cur->next;
        }
        int n = nodes.size();
        // do something
        ListNode* res = NULL;
        cur = NULL;
        for(const int x: nodes){
            if(x != 15031999){ // some condition
                if(res == NULL){
                    res = new ListNode(x);
                    cur = res;
                } else {
                    cur->next = new ListNode(x);
                    cur = cur->next;
                }
            }
        }
        return res;
