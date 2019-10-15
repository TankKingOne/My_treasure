#pragma once
// 1.���������Ĺ������ڵ�
// 2.���������ڵ㵽root֮��ڵ��ƽ������
//	a.�����ڵ� == ���׵���  p.bf++
//	b.�����ڵ� == ���׵���  p.bf--
// 3.���p.bf == 0����ǰ�����������ĸ߶Ȳ��䣬������ϲ�������Ӱ�죬���½���
// 4.���|p.bf| == 1����ǰ�����������ĸ߶ȱ��ˣ���Ӱ���ϲ����ȣ��������ϸ���
// 5.���|p.bf| == 2����ǰ������������ƽ�⣬Υ��������ת�������������ƽ�����ӣ�����

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

		// ����ƽ������
		while (parent)  //parent_bf==0ʱ����Ҫ���£����Ե�parent��Ϊ0ʱ����
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
			if (parent->_bf == 1 || parent->_bf == -1)  //ֱ�����ϸ���
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				//��ת����ƽ��
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)   //�ҵ���
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
					if (cur->_bf == 1)   //����
					{
						RotateL(parent);
					}
					else  //cur->_bf==-1
					{
						RotateRL(parent);
					}
				}
				break;  //��ת��ƽ�⣬ֱ��break
			}  //end��ת
		} //endƽ�����ӵĸ��º�ʧ�⴦��
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
			cout << "ƽ�������쳣��" << root->_kv.first << endl;
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