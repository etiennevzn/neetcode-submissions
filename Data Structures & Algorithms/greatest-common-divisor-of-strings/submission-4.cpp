class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) swap(str1, str2);

        string res = str1;

        while(!res.empty()){
            if(str1.size() % res.size() || str2.size() % res.size()){
                res.pop_back();
                continue;
            }

            int div1 = str1.size() / res.size(), div2 = str2.size() / res.size();
            bool equal1 = false, equal2 = false;

            string compare = "";
            for(int i = 0; i < div1; ++i) compare += res;
            if(compare == str1) equal1 = true;

            compare = "";
            for(int i = 0; i < div2; ++i)compare += res;
            if(compare == str2) equal2 = true;

            if(equal1 && equal2) return res;
            res.pop_back();
        }

        return "";
    }
};