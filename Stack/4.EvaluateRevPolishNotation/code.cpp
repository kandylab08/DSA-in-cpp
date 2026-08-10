class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      vector<int> stck;
        int n1, n2, res;
        for (auto elem : tokens)
        {
            if (elem == "+" || elem == "-" || elem == "*" || elem == "/")
            {
                n2 = stck.back();
                stck.pop_back();
                n1 = stck.back();
                stck.pop_back();
                if (elem == "+")
                    res = n1 + n2;
                else if (elem == "-")
                    res = n1 - n2;
                else if (elem == "*")
                    res = n1 * n2;
                else
                {
                    res = n1 / n2;
                }
                stck.push_back(res);
            }
            else
            {
                stck.push_back(stoi(elem));
            }
        }
        return stck.back();
    }
};