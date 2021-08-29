class Solution {//dfs
    int row_num;
    int col_num;
    void bfs(vector<vector<char>>& grid,int x,int y){
    if(x<0||x>=row_num||y<0||y>=col_num||grid[x][y]=='0'){
        return;
    }
    grid[x][y]='0';
    bfs(grid,x-1,y);
    bfs(grid,x+1,y);
    bfs(grid,x,y-1);
    bfs(grid,x,y+1);
    };
public:
    int numIslands(vector<vector<char>>& grid) {
    int result=0;
    row_num=grid.size();
    col_num=grid[0].size();
    for(int i=0;i<row_num;i++){
        for(int j=0;j<col_num;j++){
            if(grid[i][j]=='1'){
             result++;
             bfs(grid,i,j);
            }
        }
    }
        return result;

    }
};
