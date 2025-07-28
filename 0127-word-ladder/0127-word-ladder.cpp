class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin() , wordList.end());
        queue<pair<string , int>>que;
        que.push({beginWord , 1});
        while( !que.empty()){
           
            string frontnode = que.front().first;
            int size = que.front().second;
            que.pop();

            if( frontnode == endWord)
                return size;
            
            for( int i = 0 ; i < frontnode.length(); i++){
                  char originalnode = frontnode[i];

                  for( char ch = 'a' ;ch <= 'z' ; ch++){
                    frontnode[i] =  ch ;

                    if(st.count(frontnode)){
                        que.push({frontnode , size+1});
                        st.erase(frontnode);
                    }

                  }
                  frontnode[i] = originalnode;
                  
            }
            
        }
        return 0;
    }
};