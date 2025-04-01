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
    //brute force , replace data
    public ListNode oddEvenList(ListNode head) {
        if(head==null){
            return head;
        }
        //getting odd ones first
        ListNode temp=head;
        ArrayList<Integer>arr=new ArrayList<>();
        while(temp!=null){
            arr.add(temp.val);
            if(temp.next==null)break;
            temp=temp.next.next;
        }
        temp=head.next;
         while(temp!=null){
            arr.add(temp.val);
            if(temp.next==null)break;
            temp=temp.next.next;
        }
        temp=head;
        int i=0;
        while(temp!=null){
            temp.val=arr.get(i);
            temp=temp.next;
            i++;
        }
        return head;

    }
}