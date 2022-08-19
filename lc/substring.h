//https://leetcode.com/problems/minimum-window-substring/discuss/703234/Substring-template
int findSubstring(string s) {
	unordered_map<char, int> m;
	int start = 0, end = 0;
	int len; // Length of substring. Final return value.
	int counter; // check whether the substring is valid
    
	/* Initialize hashmap */
    
	while (end < s.size()) {
		if (m[s[end]] ???) /* Modify counter */

		m[s[end]]--;
        end++;
            
    	while (/* counter condition */) {
         	/* Update len if finding minimum */
            
            /* Advance start to make the window (in)valid */
            
            if (m[s[start]] ???) /* Modify counter */
        	
            m[s[start]]++;
            start++;
        }
        /* Update len if finding maximum */
    }		
    return len;
}