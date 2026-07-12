class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr; // copy original array
        sort(temp.begin(), temp.end()); // sort the coppied array

        unordered_map<int, int>mp;
        int rank = 1;

        // store the rank of each unique element 
        for(int i=0; i<temp.size(); i++){

            if(mp.find(temp[i]) == mp.end()){ // element not present
                mp[temp[i]] = rank;
                rank++;
            }
        }

        // relpace original element with their rank;
        for(int i=0; i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};