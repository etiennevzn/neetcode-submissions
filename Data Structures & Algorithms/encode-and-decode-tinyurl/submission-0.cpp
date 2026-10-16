class Solution {
public:
    string encode(string longUrl) {return longUrl + "kt";};
    string decode(string shortUrl) {
        shortUrl.pop_back();
        shortUrl.pop_back();
        return shortUrl;
    }
};
