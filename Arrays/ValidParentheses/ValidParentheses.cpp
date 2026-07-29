class Solution {
public:
    bool isValid(string s) {
    unordered_map<char, char> comp;
    char a[100000];
    int top = -1;
    int n = s.size();
    comp[')'] = '(';
    comp['}'] = '{';
    comp[']'] = '[';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            a[++top] = s[i];
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1)
            {

                return false;
            }
            if (a[top] == comp[s[i]])
                --top;
            else
            {

                return false;
            }
        }
        else
        {

            return false;
        }
    }
    if (top == -1)
    return true;
    return false;
}

};