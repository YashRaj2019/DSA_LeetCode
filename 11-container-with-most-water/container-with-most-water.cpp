class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size()-1;
        long long area = 0;

        while(left<right){
            long long width = right - left;
            long long h = min(height[left], height[right]);
            area = max(area, width*h);

            if(height[left]<height[right]){
                left++;
            }

            else{
                right--;
            }
        }

        return area;
        
    }
};