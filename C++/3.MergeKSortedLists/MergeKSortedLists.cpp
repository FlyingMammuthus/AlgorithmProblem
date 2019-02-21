#include <vector>
#include <queue>                        // priority_queue defined in head file queue
#include "ListNode.h"
using namespace std;
/*Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
*/

/* one simple way which is easy to implement
class Solution3 {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		ListNode *sortStart = new ListNode(-1), *ret = new ListNode(-1), *nPre = NULL, *ins = NULL;
		int temp;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i] != NULL) {
				temp = lists[i]->val;
				nPre = sortStart;
				while (nPre->next != NULL && lists[nPre->next->val]->val < temp) {
					nPre = nPre->next;
				}
				ins = new ListNode(i);
				ins->next = nPre->next;
				nPre->next = ins;
			}
		}
		ListNode *retPre = ret;
		while (sortStart->next != NULL) {
			nPre = sortStart->next;
			retPre->next = lists[nPre->val];
			lists[nPre->val] = lists[nPre->val]->next;
			sortStart->next = nPre->next;
			ins = nPre;
			if (lists[ins->val] != NULL) {
				temp = lists[ins->val]->val;
				nPre = sortStart;
				while (nPre->next != NULL && lists[nPre->next->val]->val < temp) {
					nPre = nPre->next;
				}
				ins->next = nPre->next;
				nPre->next = ins;
			}
			else {
				delete ins;
			}
			retPre = retPre->next;
		}
		retPre->next = NULL;
		retPre = ret;
		ret = ret->next;
		delete retPre;
		delete sortStart;
		return ret;
	}
};
*/

// method above can be simplied by using ListNode *sortStart instead of ListNode<ListNode *>.....

// improved method is to use priority_queue
class Solution3 {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		ListNode *ret = new ListNode(-1);
		priority_queue<ListNode *, vector<ListNode*>, cmp_list> sortList;
		for (auto list : lists) { //'auto' means define variable type of list automatically (ListNode * here), ':' means list traverse lists
			if (list) {          // same as 'if (list == nullptr)''
				sortList.push(list);
			}
		}
		ListNode *retPre = ret;
		while (!sortList.empty()) {
			retPre->next = sortList.top();
			sortList.pop();
			retPre = retPre->next;
			if (retPre->next) {
				sortList.push(retPre->next);
			}
		}
		retPre->next = NULL;
		retPre = ret;
		ret = ret->next;
		delete retPre;
		return ret;
	}

	struct cmp_list {            //define < but we want smallest value from priority_queue, so return > 
		bool operator()(const ListNode* a, const ListNode* b) {
			return a->val > b->val;
		}
	};
};
