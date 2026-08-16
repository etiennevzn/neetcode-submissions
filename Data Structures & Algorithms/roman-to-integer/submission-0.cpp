class Solution {
public:
    int romanToInt(string s) {
        int res = 0, i = 0;
        while(i < s.size()){
            const char& c = s[i];

            switch(c){
                case 'I':
                    if(i + 1 < s.size()){
                        if(s[i + 1] == 'V'){
                            res += 4;
                            i += 2;
                        }else if(s[i + 1] == 'X'){
                            res += 9;
                            i += 2;
                        }else{
                            res++;
                            i++;
                        }
                    }else{
                        res++;
                        i++;
                    }
                    break;

                case 'X':
                    if(i + 1 < s.size()){
                        if(s[i + 1] == 'L'){
                            res += 40;
                            i += 2;
                        }else if(s[i + 1] == 'C'){
                            res += 90;
                            i += 2;
                        }else{
                            res += 10;
                            i++;
                        }
                    }else{
                        res += 10;
                        i++;
                    }
                    break;
                
                case 'C':
                    if(i + 1 < s.size()){
                        if(s[i + 1] == 'D'){
                            res += 400;
                            i += 2;
                        }else if(s[i + 1] == 'M'){
                            res += 900;
                            i += 2;
                        }else{
                            res += 100;
                            i++;
                        }
                    }else{
                        res += 100;
                        i++;
                    }
                    break;
                
                case 'V':
                    res += 5;
                    i++;
                    break;

                case 'L':
                    res += 50;
                    i++;
                    break;
                
                case 'D':
                    res += 500;
                    i++;
                    break;
                
                case 'M':
                    res += 1000;
                    i++;
                    break;
            }
        }

        return res;
    }
};