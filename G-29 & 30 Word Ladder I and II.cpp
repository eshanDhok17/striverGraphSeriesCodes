// Word Ladder I
class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        // Set to store strings to get in O(1) time later rather than linear search 
        unordered_set<string> st;
        for(string &str : wordList) st.insert(str);
        
        // Clear wordlist after storing in hash table
        wordList.clear();
        // Create Queue starting with start word and steps 1
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        // erase from set to not later visit same word; loops endlessly
        st.erase(beginWord);
        while(!q.empty()) {
            auto word = q.front().first;
            auto steps = q.front().second;
            q.pop();
            // if we find our word, we return steps taken to reach this word
            if(word == endWord) return steps;
            /*
              or we change charecters of that word from start to end to see if it matches with another word strictly in the set,
              if found we push that word into queue and replace the replaced char with thwe original char.
            */
            for(int i=0; i<word.size(); ++i) {
                char original = word[i];
                for(char x = 'a'; x <= 'z'; ++x) {
                    word[i] = x;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        // if we can't reach/ create the word, we return 0
        return 0;
    }
};
