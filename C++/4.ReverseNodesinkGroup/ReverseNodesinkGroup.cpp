#include "ListNode.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution4 {
public:
	static ListNode * reverseKGroup(ListNode* head, int k) {
		if (k < 1) {
			return head;
		}
		ListNode *gHeadPrev = new ListNode(-1), *gHead = gHeadPrev, *nodePre = head, *nodeNext = NULL, *nodeEnd = NULL,
			*ret = gHeadPrev;
		int count = k;                                 // Caution : set count = k to avoid error when input a NULL list ([]).
		while (nodePre != NULL) {
			gHeadPrev = gHead;
			gHead = nodePre;
			count = 1;
			nodeEnd = nodePre->next;
			while (count < k && nodeEnd != NULL) {
				nodeNext = nodeEnd;
				nodeEnd = nodeNext->next;
				nodeNext->next = nodePre;
				nodePre = nodeNext;
				++count;
			}
			gHeadPrev->next = nodePre;
			nodePre = nodeEnd;
		}
		gHead->next = NULL;                            // Caution : don not put it inside if-else statement.
		if (count < k) {	
			nodePre = gHeadPrev->next;
			nodeEnd = nodePre->next;
			while (nodeEnd != NULL) {
				nodeNext = nodeEnd;
				nodeEnd = nodeNext->next;
				nodeNext->next = nodePre;
				nodePre = nodeNext;
			}
			gHeadPrev->next->next = NULL;
			gHeadPrev->next = nodePre;
		}
		gHead = ret;
		ret = ret->next;
		delete gHead;
		return ret;
	}
};
