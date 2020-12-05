class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int maxIslands=0;
        if(grid.empty() || grid[0].size()<0){
            return 0;
        }
        int maxRowNum = grid.size(); 
        int maxColNum = grid[0].size(); 
        
        for(int i=0;i<maxRowNum; i++){
            for(int j=0;j<maxColNum;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,maxRowNum,maxColNum);
                    maxIslands++;
                }
            }
        }
          
        return maxIslands;
    }
    
    void dfs(vector<vector<char>> &grid, int i,int j,int maxRowNum,int maxColNum){
        
        if(i>=maxRowNum || j>=maxColNum || i<0 || j<0){
            return; 
        }
       
        if(grid[i][j]=='0'){
            return;
        }
       
        grid[i][j]='0';
        //North and South          
        dfs(grid,i-1,j,maxRowNum,maxColNum);
        dfs(grid,i+1,j,maxRowNum,maxColNum);
         //East and West
        dfs(grid,i,j+1,maxRowNum,maxColNum);
        dfs(grid,i,j-1,maxRowNum,maxColNum);
     
    }
};