vector<string> get_strings(string str){
        vector<string> internal;
        stringstream ss(str);
        char delimiter = ' ';
        string tok;
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        return internal;
    }