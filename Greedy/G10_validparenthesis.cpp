    bool checkValidString(string s) {
        stack<int> st1;
        stack<int> st2;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st1.push(i);
            }
            if(s[i] == '*'){
                st2.push(i);
            }
            if(s[i] == ')'){
                if(!st1.empty()) st1.pop();
                else if(!st2.empty()) st2.pop();
                else return false;
            }
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() < st2.top()){
                st1.pop();
                st2.pop();
            }
            else break;
        }

        return st1.empty();
    }