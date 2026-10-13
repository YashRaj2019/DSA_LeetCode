/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        boolean isCycle = false;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast= fast.next.next;
            
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle){
            return null;
        }
        
        
        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        
        return slow;
        
        // ListNode temp = head;
        // while(temp != slow){
        //     temp = temp.next;
        //     slow = slow.next;
        // }
        // return temp;  // slow can also be true here
    }
}