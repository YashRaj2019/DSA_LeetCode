/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        ArrayList<ListNode> arr = new ArrayList<>();
        for(int i=0; i<lists.length; i++){
            arr.add(lists[i]);
        }

        if(arr.isEmpty()){
            return null;
        }

        while(arr.size() > 1){

            ListNode a = arr.get(arr.size() - 1);
            arr.remove(arr.size() - 1);

            ListNode b = arr.get(arr.size() - 1);
            arr.remove(arr.size() - 1);

            ListNode c = merge(a, b);
            arr.add(c);
        }
        return arr.get(0);
    }

    public ListNode merge(ListNode head1, ListNode head2){
        ListNode i = head1;
        ListNode j = head2;
        ListNode dummy = new ListNode(-1);
        ListNode k = dummy;

        while(i != null && j != null){
            if(i.val <= j.val){
                k.next = i;
                i = i.next;
            }
            else{
                k.next = j;
                j = j.next;
            }
            k = k.next;
        }
        if(i == null){
            k.next = j;
        }
        else{
            k.next = i;
        }
        return dummy.next;
    }
}