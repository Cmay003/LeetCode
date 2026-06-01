class Solution {
public:
    vector<vector<string>> ans;
    map<string,int> mpp;
    void dfs(string b, string word, vector<string>&seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps=mpp[word];
        for(int i=0; i<word.size(); i++){
            string original=word;
            for(char ch='a'; ch<='z'; ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(b, word, seq);
                    seq.pop_back();
                }
            }
            word=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        mpp[beginWord]=1;
        while(!q.empty()){
            string word=q.front().first;
            int num=q.front().second;
            q.pop();
            if(word==endWord) break;
            for(int i=0; i<word.size(); i++){
                string original=word;
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,num+1});
                        st.erase(word);
                        mpp[word]=num+1;
                    }
                }
                word=original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(beginWord, endWord, seq);
        }
        return ans;
    }
};