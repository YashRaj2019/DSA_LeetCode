class Solution {
public:

    void merge(vector<int>& nums, int start, int mid, int end){

        vector<int>temp;

        int i = start;
        int j = mid+1;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){  // // nums[i] >= nums[j] for sort in descending order
                temp.push_back(nums[i]); 
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = start; k <= end; k++){ // after merging overrite the original array
            nums[k] = temp[k - start];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = start + (end - start)/2;

            mergeSort(nums, start, mid); // left half
            mergeSort(nums, mid+1, end); // right half

            merge(nums, start, mid, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};