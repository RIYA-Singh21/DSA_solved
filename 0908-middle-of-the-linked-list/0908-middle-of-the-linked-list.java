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
    //brute force sol
    public ListNode middleNode(ListNode head) {
        int cnt=0;
        ListNode temp=head;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }
        temp=head;
        int middlenode=(cnt/2)+1;
        while(temp!=null){
            middlenode=middlenode-1;
            if(middlenode==0){
                break;
            }
            temp=temp.next;
        }
        return temp;     
    }
}