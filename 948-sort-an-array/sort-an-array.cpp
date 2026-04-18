// class Solution {
// public:
//     void merge(vector<int>& nums, int start, int mid, int end){
//         vector<int> temp;
//         int i = start, j = mid+1;

//         while(i <= mid && j <= end){
//             if(nums[i] <= nums[j]){
//                 temp.push_back(nums[i]);
//                 i++;
//             }
//             else{
//                 temp.push_back(nums[j]);
//                 j++;
//             }
//         }

//         while(i <= mid){
//             temp.push_back(nums[i]);
//             i++;
//         }

//         while(j <= end){
//             temp.push_back(nums[j]);
//             j++;
//         }

//         for(int index=0; index<temp.size(); index++){
//             nums[index + start] = temp[index];
//         }
//     }

//     void mergeSort(vector<int>& nums, int start, int end){
//         if(start < end){
//             int mid = start + (end-start) / 2;

//             mergeSort(nums, start, mid); // left half
//             mergeSort(nums, mid+1, end); // right half

//             merge(nums, start, mid, end);
//         }
//     }
//     vector<int> sortArray(vector<int>& nums) {
        
//         mergeSort(nums, 0, nums.size()-1);
//         return nums;
//     }
// };

// method to optimal solution

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && nums[left] > nums[largest])
            largest = left;

        if(right < n && nums[right] > nums[largest])
            largest = right;

        if(largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build Max Heap
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(nums, n, i);
        }

        // Step 2: Extract elements
        for(int i = n - 1; i > 0; i--){
            swap(nums[0], nums[i]);   // move max to end
            heapify(nums, i, 0);      // heapify reduced heap
        }

        return nums;
    }
};