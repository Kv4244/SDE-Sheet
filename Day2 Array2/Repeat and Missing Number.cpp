vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int repeat = -1, missing = -1;
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++)
        vis[A[i]] ++;
    for(int i=1;i<=n;i++){
        if(vis[i] >= 2) repeat = i;
        if(vis[i] == 0) missing = i;
    }        
    return {repeat,missing};
}
