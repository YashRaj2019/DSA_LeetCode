class Solution {
    public int[] sortArray(int[] nums) {

        if(nums.length == 1){
            return nums;
        }

        mergeSort(nums);
        return nums;
    }

   public void mergeSort(int[] arr){
        if(arr.length == 1){
            return;
        }
        int n = arr.length;

        int[] a = new int[n/2];
        int[] b = new int[n-n/2];

        int idx = 0; // idx will iterate on arr
        for(int i=0; i<a.length; i++){
            a[i] = arr[idx];
            idx++;
        }

        for(int i=0; i<b.length; i++){
            b[i] = arr[idx];
            idx++;
        }

        mergeSort(a);
        mergeSort(b);

        merge(a, b, arr);

    }

    void merge(int[] a, int[] b, int[] c){
        int i=0, j=0, k=0;

        while(i<a.length && j<b.length){
            if(a[i] < b[j]){
                c[k] = a[i];
                k++;
                i++;
            }
            else{
                c[k] = b[j];
                k++;
                j++;
            }
        }

        while(i<a.length){
            c[k]=a[i];
            k++;
            i++;
            
        }

        while(j<b.length){
            c[k]=b[j];
            k++;
            j++;

        }
    }
}