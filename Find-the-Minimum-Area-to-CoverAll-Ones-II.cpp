class Solution {
public:
    int minimumSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
        auto area = [&](int r1,int r2,int c1,int c2){
            int rmin=m, rmax=-1, cmin=n, cmax=-1;
            for(int i=r1;i<=r2;i++)
                for(int j=c1;j<=c2;j++)
                    if(g[i][j]) rmin=min(rmin,i), rmax=max(rmax,i),
                                cmin=min(cmin,j), cmax=max(cmax,j);
            return rmax==-1?0:(rmax-rmin+1)*(cmax-cmin+1);
        };
        
        int ans=m*n;
        // Case 1 & 2: horizontal + split
        for(int i=0;i<m;i++) for(int j=0;j<n;j++){
            ans=min(ans, area(0,i,0,n-1)+area(i+1,m-1,0,j)+area(i+1,m-1,j+1,n-1));
            ans=min(ans, area(i,m-1,0,n-1)+area(0,i-1,0,j)+area(0,i-1,j+1,n-1));
        }
        // Case 3 & 4: vertical + split
        for(int j=0;j<n;j++) for(int i=0;i<m;i++){
            ans=min(ans, area(0,m-1,0,j)+area(0,i,j+1,n-1)+area(i+1,m-1,j+1,n-1));
            ans=min(ans, area(0,m-1,j,n-1)+area(0,i,0,j-1)+area(i+1,m-1,0,j-1));
        }
        // Case 5: 3 horizontal
        for(int i1=0;i1<m;i1++) for(int i2=i1+1;i2<m;i2++)
            ans=min(ans, area(0,i1,0,n-1)+area(i1+1,i2,0,n-1)+area(i2+1,m-1,0,n-1));
        // Case 6: 3 vertical
        for(int j1=0;j1<n;j1++) for(int j2=j1+1;j2<n;j2++)
            ans=min(ans, area(0,m-1,0,j1)+area(0,m-1,j1+1,j2)+area(0,m-1,j2+1,n-1));
        return ans;    
    }
};
