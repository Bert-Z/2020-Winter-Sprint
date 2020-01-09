#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> bracks_stack;
        
        for(int i=0;i<s.size();i++){
            char cur = s[i];
            
            if(cur=='('||cur=='{'||cur=='[')
                bracks_stack.push(s[i]);
            else{
                if(bracks_stack.size()==0)
                    return false;
                
                switch(cur){
                    case ')':
                        if(bracks_stack.top()!='(')
                            return false;
                        break;
                    case ']':
                        if(bracks_stack.top()!='[')
                            return false;
                        break;
                    case '}':
                        if(bracks_stack.top()!='{')
                            return false;
                        break;
                }
                bracks_stack.pop();
            }
        }
        
        if(bracks_stack.size()!=0)
            return false;
        
        return true;
    }
};