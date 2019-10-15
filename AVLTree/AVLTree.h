#pragma once
// 1.按搜索树的规则插入节点
// 2.更新新增节点到root之间节点的平衡因子
//	a.新增节点 == 父亲的右  p.bf++
//	b.新增节点 == 父亲的左  p.bf--
// 3.如果p.bf == 0，当前父亲所在树的高度不变，不会对上层祖先有影响，更新结束
// 4.如果|p.bf| == 1，当前父亲所在树的高度变了，会影响上层祖先，继续向上更新
// 5.如果|p.bf| == 2，当前父亲所在树不平衡，违反规则。旋转这棵子树，更新平衡因子，结束

#include <iostream>
#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	int _bf; // balance factor

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 更新平衡因子
		while (parent)  //parent_bf==0时不需要更新，所以当parent不为0时更新
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			if (parent->_bf == 1 || parent->_bf == -1)  //直接向上更新
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				//旋转以求平衡
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)   //右单旋
					{
						RotateR(parent);
					}
					else   //cur->_bf==1
					{
						RotateLR(parent);
					}
				}
				else if (parent->_bf == 2)
				{
					if (cur->_bf == 1)   //左单旋
					{
						RotateL(parent);
					}
					else  //cur->_bf==-1
					{
						RotateRL(parent);
					}
				}
				break;  //旋转后平衡，直接break
			}  //end旋转
		} //end平衡因子的更新和失衡处理
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		
		if (_root == parent)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_right == parent)
				ppNode->_right = subL;
			else
				ppNode->_left = subL;
			
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if(bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_InOrder(root->_right);

	}
	void InOrder()
	{
		_InOrder(_root);

	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHight = _Height(root->_left);
		int rightHight = _Height(root->_right);

		return leftHight > rightHight ? (leftHight + 1) : (rightHight + 1);
	}
	bool _IsBanlance(Node* root)
	{
		if (root == nullptr)
			return true;

		int  leftHeight = _Height(root->_left);
		int  rightHeight = _Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "平衡因子异常：" << root->_kv.first << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2 
			&& _IsBanlance(root->_left) 
			&& _IsBanlance(root->_right);
	}
	bool IsBanlance()
	{
		return _IsBanlance(_root);
	}
private:
	Node* _root;
};