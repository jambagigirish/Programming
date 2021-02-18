class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res= 0;
        int low =0;
        int high =height.size()-1;
        while(low<high){
            int temp = (high-low) * min(height[low],height[high]);
            if(res<temp){
                res=temp;
            }
            
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        
        return res;        
    }
};