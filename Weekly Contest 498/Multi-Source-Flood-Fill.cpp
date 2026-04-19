class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> g(n,vector<int> (m,0)),t(n,vector<int>(m,-1));
        queue<vector<int>> q;
        for(auto &s:sources) {
            if(s[2]>g[s[0]][s[1]]) {
                g[s[0]][s[1]]=s[2];
                t[s[0]][s[1]]=0;
                q.push({s[0],s[1],s[2],0});
            }
        }
        int d[]={0,1,0,-1,0};
        while(!q.empty()) {
            auto c=q.front(); q.pop();
            if(c[2]<g[c[0]][c[1]]) continue;
            for(int i=0;i<4;i++) {
                int nr=c[0]+d[i],nc=c[1]+d[i+1];
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    if(t[nr][nc]==-1 || (t[nr][nc]==c[3]+1 && g[nr][nc]<c[2])) {
                        t[nr][nc]=c[3]+1;
                        g[nr][nc]=c[2];
                        q.push({nr,nc,c[2],c[3]+1});
                    }
                }
            }
        }

        return g;
    }
};
