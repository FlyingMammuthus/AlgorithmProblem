#pragma once
#include "TreeNode.h"

/* 一个简单的方法：中序遍历，加上m1,m2,pre指针
class Solution22 {
public:
TreeNode *m1, *m2, *pre;
void recoverTree(TreeNode* root) {
m1 = NULL;
m2 = NULL;
pre = NULL;
traverseTree(root);
if (m1 != NULL && m2 != NULL) {
int i = m1->val;
m1->val = m2->val;
m2->val = i;
}
}
void traverseTree(TreeNode *root) {
if (root == NULL) return;
traverseTree(root->left);
if (pre != NULL && root->val < pre->val) {
if (m1 == NULL) {
m1 = pre;
}
m2 = root;
}
pre = root;
traverseTree(root->right);
}
};
*/

/* 改版：基于Morris遍历，可以是空间复杂度达到O(1) */
class Solution22 {
public:
	TreeNode *m1, *m2, *pre;
	void recoverTree(TreeNode* root) {
		m1 = NULL;
		m2 = NULL;
		pre = NULL;

		if (root == NULL) {
			return;
		}
		TreeNode *p1 = root, *p2 = NULL;

		while (p1 != NULL) {
			p2 = p1->left;
			if (p2 != NULL) {
				while (p2->right != NULL && p2->right != p1) {
					p2 = p2->right;
				}
				if (p2->right == NULL) {
					p2->right = p1;
					p1 = p1->left;
					continue;
				}
				else {
					p2->right = NULL;
				}
			}
			if (pre != NULL && p1->val < pre->val) {
				if (m1 == NULL) {
					m1 = pre;
				}
				m2 = p1;
			}
			pre = p1;
			p1 = p1->right;
		}
		if (m1 != NULL && m2 != NULL) {
			int i = m1->val;
			m1->val = m2->val;
			m2->val = i;
		}
	}
};
