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

// Word Ladder II

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList), end(wordList));    
        vector<vector<string>> res;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        while(!q.empty()) {
            auto sequence = q.front(); q.pop();
        /*
            we are on another level so we remove words in usedOnLevel from set
            to mark them as used or visited and we increment the level to identify
            further levels from current level
        */
            if(size(sequence) > level) {
                level += 1;
                for(string &it : usedOnLevel) {
                    st.erase(it);
                }
            }
            
        /*
            next we get latest word of sequence and peform the changes on that
            word charecter by charecter such that we obtain a word from wordList
            to be later used to reach the end word
        */
            string word = sequence.back();
            
        // check if we got to the end word, if yes we pushback the sequence into our answer
            if(word == endWord) {
            /*
                if our answer is empty, that means we have the sequence which is shortest
                which we will use later for comparision when entering another sequences which
                are possible
            */
                if(size(res) == 0) {
                    res.push_back(sequence);
                }
            // if new sequence is also shortest
                else if(res[0].size() == sequence.size()) {
                    res.push_back(sequence);
                }
            }
            
            for(int i=0; i<size(word); ++i) {
            /*
                store original charecter in order to get back the original word
                due to the fact that it will be needed for another charecter change
            */
                char original = word[i];
                for(char x = 'a'; x <= 'z'; ++x) {
                    word[i] = x;
                    if(st.find(word) != st.end()) {
                        sequence.push_back(word);
                        q.push(sequence);
                        usedOnLevel.push_back(word);
                        sequence.pop_back();
                    }
                }
                word[i] = original; // charecter restoration
            }
        }
        return res;
    }
};
