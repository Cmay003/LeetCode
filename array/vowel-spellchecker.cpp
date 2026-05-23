class Solution {
public:
    string isLower(string word){
        for(char &c:word){
            c=tolower(c);
        }
        return word;
    }

    string deVowel(string word){
        for(char &c:word){
            char x = tolower(c);
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                c='*';
            }
        }
        return word;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> exact;
        unordered_map<string, string> LUcase;
        unordered_map<string, string> vowel;
        for(auto word: wordlist){
            exact.insert(word);
            string lower = isLower(word);
            string vow = deVowel(lower);
            if(LUcase.find(lower)==LUcase.end()){
                LUcase[lower] = word;
            }
            if(vowel.find(vow)==vowel.end()){
                vowel[vow] = word;
            }
        }

        vector<string> ans;
        for(auto query:queries){
            if(exact.count(query)==1){
                ans.push_back(query);
                continue;
            }
            string low = isLower(query);
            if(LUcase.find(low)!=LUcase.end()){
                ans.push_back(LUcase[low]);
                continue;
            }
            string devow = deVowel(low);
            if(vowel.find(devow)!=vowel.end()){
                ans.push_back(vowel[devow]);
                continue;
            }
            else{
                ans.push_back("");
            }
        }
        return ans;
    }
};