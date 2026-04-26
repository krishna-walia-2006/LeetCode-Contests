class Solution {
    bool isVowel(char ch) {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
public:
    string sortVowels(string s) {
        int n=s.size();
        unordered_map<char,int> freq;
        unordered_map<char,int> firstPos;
        for(int i=0;i<n;i++) {
            if(isVowel(s[i])) freq[s[i]]++;
            if(firstPos.find(s[i])==firstPos.end()) firstPos[s[i]]=i;
        }
        vector<char> vowels={'a','e','i','o','u'};
        sort(vowels.begin(),vowels.end(),[&](char a,char b) {
            if(freq[a]!=freq[b]) return freq[a]>freq[b];
            else return firstPos[a]<firstPos[b];
        });
        string orderedVowels="";
        for(char v:vowels) {
            orderedVowels+=string(freq[v],v);
        }
        int idx=0;
        for(int i=0;i<n;i++) {
            if(isVowel(s[i])) {
                s[i]=orderedVowels[idx];
                idx++;
            }
        }
        return s;
    }
};
