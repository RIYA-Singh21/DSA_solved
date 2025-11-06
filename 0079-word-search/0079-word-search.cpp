class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row =board.size();
        int col=board[0].size();
        //set to see of the char are visited
        unordered_set<string>visited;

        auto dfs=[&](int r,int c,int k,auto& dfs)->bool{
            if(k==word.length())
                return true;
            if(r<0 || r>= row || c<0 || c>=col || visited.count(to_string(r)+","+
            to_string(c)) || board[r][c]!=word[k]
            ){
                return false;
            }
            visited.insert(to_string(r)+","+to_string(c));


            bool res= dfs(r+1,c,k+1,dfs)||
                      dfs(r-1,c,k+1,dfs)||
                      dfs(r,c+1,k+1,dfs)||
                      dfs(r,c-1,k+1,dfs);

            visited.erase(to_string(r)+","+to_string(c));
            return res;
        };
        unordered_map<char,int>count;

        for(char c:word)
            count[c]++;
        if(count[word[0]]>count[word.back()]){
            reverse(word.begin(),word.end());
        }

        //iterate through all the cells of the grid
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(dfs(r,c,0,dfs)){
                    return true;
                }
            }
        }
        return false;

        



    }
};