class Solution {
    set<vector<pair<int,int>>> ans;
    vector<vector<char>> vis;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;

    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> ans1;
        q.push({i,j});
        vis[i][j] = '1';

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            ans1.push_back({x - i, y - j}); // relative position

            for(int k=0; k<4; k++){
                int x1 = x + dx[k];
                int y1 = y + dy[k];

                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1 && vis[x1][y1]=='0'){
                    vis[x1][y1] = '1';
                    q.push({x1,y1});
                }
            }
        }

        ans.insert(ans1); // insert shape after finishing BFS
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        vis.assign(n, vector<char>(m,'0'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]=='0'){
                    bfs(grid, i, j);
                }
            }
        }
        return ans.size();
    }
};
