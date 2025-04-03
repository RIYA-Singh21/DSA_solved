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
    //changing the links
    public ListNode oddEvenList(ListNode head) {
        if(head==null || head.next==null){
            return head;
        }
        ListNode odd_index=head;
        ListNode even_index=head.next;
        ListNode evenhead=head.next;
        while(even_index!=null && even_index.next!=null){
            odd_index.next=odd_index.next.next;
            even_index.next=even_index.next.next;
            //now the odd.next=odd.next.next
            odd_index=odd_index.next;
            even_index=even_index.next;
        }
        odd_index.next=evenhead;
        return head;
    }
}