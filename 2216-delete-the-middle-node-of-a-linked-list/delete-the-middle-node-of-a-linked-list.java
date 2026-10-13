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
    public ListNode deleteMiddle(ListNode head) {
        ListNode temp = head;
        int length = 0;
        while(temp != null){
            temp=temp.next;
            length++;
        }

        if(length == 1){
            return null;
        }

        if(length == 2){
            head.next = null;
            return head;
        }

        temp = head;
        for(int i=0; i<length/2 -1; i++){
            temp = temp.next;
        }
        // temp.val = temp.next.val;
        temp.next = temp.next.next;

        return head;
    }
}