class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, mxht=0, temp=0;
        for(auto &i:height){
            if(i>=mxht){
                ans+=temp;
                mxht=i;
                temp=0;
            }
            else temp+=mxht-i;
        }
        reverse(height.begin(),height.end());
        mxht=0;
        temp=0;
        for(auto &i:height){
            if(i>mxht){
                ans+=temp;
                mxht=i;
                temp=0;
            }
            else temp+=mxht-i;
        }
        return ans;
    }
};
