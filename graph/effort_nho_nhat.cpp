
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};

bool valid(int row,int col){
    return 0<=row && row<m && 0<=col && col<n;
}

bool check(int effort,vector<vector<int>>& heights){
    vector<vector<bool>> seen(m,vector<bool>(n,false));
    stack<pair<int,int>> stack;
    stack.push({0,0});
    
    while(!stack.empty()){
        auto [row,col]=stack.top();
        stack.pop();
        
        if(row==m-1 && col==n-1)
            return true;
        
        for(vector<int>& direction: directions) {
            int nextrow = row + direction[0], nextcol = col + direction[1];
            if (valid(nextrow, nextcol) && !seen[nextrow][nextcol]) {
                if (abs(heights[nextrow][nextcol] - heights[row][col]) <= effort) {
                    seen[nextrow][nextcol] = true;
                    stack.push({nextrow, nextcol});
                }
            }
        }
    }
    
    return false;
}

int minimumeffortpath(vector<vector<int>>& heights){
    m=heights.size();
    n=heights[0].size();
    
    int l=0,r=0;
    
    for(vector<int>& row:heights){
        for(int num:row){
            r=max(r,num);
        }
    }
    
    while(l<r){
        int mid=l+(r-l)/2;
        
        if(check(mid,heights))
            r=mid;
        else
            l=mid+1;
    }
    
    return l;
}

int main(){
    vector<vector<int>> heights={{1,3,2,3},{5,3,2,3},{6,1,4,3},{5,5,5,7}};
    cout<<minimumeffortpath(heights);
    return 0;
}

