class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int num=q.front().second;
            q.pop();
            if(word==endWord) return num;
            for(int i=0; i<word.size(); i++){
                string original=word;
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(set.find(word)!=set.end()){
                        set.erase(word);
                        q.push({word, num+1});
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};