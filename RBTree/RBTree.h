#pragma once

#include <iostream>
#include <string>

using  std::cout;
using  std::cin;
using  std::endl;

enum Color
{
	RED,
	BLACK
};

template<class V>
struct RBTreeNode
{
	RBTreeNode<V>* _left;
	RBTreeNode<V>* _right;
	RBTreeNode<V>* _parent;

	V _value;

	Color _col;

	RBTreeNode(const V& value)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
		,_value(value)
	{}
};

template<class V>
struct  _RBTreeIterator
{
	typedef V ValueType;
	typedef RBTreeNode<V> Node;
	typedef _RBTreeIterator<V> Self;
public:
	Node* _node;

	_RBTreeIterator(Node* node)
		:_node(node)
	{}

	V& operator*()
	{
		return _node->_value;
	}
	V& operator->()
	{
		return &_node->_value;
	}
	Self& operator++()
	{
		if (_node->_right == nullptr)
		{
			Node* parent = _node->_parent;
			while (parent && parent->_right == _node)
			{
				_node = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		else
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		return *this;
	}

	Self& operator--()
	{

		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

template<class K, class V, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<V> Node;
public:
	typedef _RBTreeIterator<V> iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	RBTree()
		:_root(nullptr)
	{}
	// 1.�����������ɫ�����
	// 2.�����ڵ㣬��������Ǻ�ɫ����������
	// 3.�����ڵ㣬��������Ǻ�ɫ
	std::pair<iterator, bool> Insert(const V& value)
	{
		// 1.���������Ĺ�����в���
		if (_root == nullptr)
		{
			_root = new Node(value);
			_root->_col = BLACK;
			return std::make_pair(iterator(_root), true);
		}

		KeyOfValue kov;

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kov(cur->_value) < kov(value))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_value) > kov(value))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return std::make_pair(iterator(cur), false);
		}

		cur = new Node(value);
		Node* newnode = cur;

		cur->_col = RED;       // ����²�����Ϊ��ɫ��Υ��4������Ҫ��������·���������ɫ������Υ��3����ֻ�账��ǰ·��
		if (kov(parent->_value) < kov(value))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// ƽ��
		// 1.curΪ�죬pΪ�죬gΪ�ڣ�u������Ϊ��
		//   �����ʽ����p,u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����
		// 2.curΪ�죬pΪ�죬gΪ�ڣ�u������/uΪ��
		//   2.1 pΪg�����ӣ�curΪp�����ӣ�������ҵ���ת��
		//   2.2 pΪg���Һ��ӣ�curΪp���Һ��ӣ����������ת
		//  p��g��ɫ--p��ڣ�g���
		// 3.curΪ�죬pΪ�죬gΪ�ڣ�u������/uΪ��
		//   3.1 pΪg�����ӣ�curΪp���Һ��ӣ������p������ת��
		//   3.2 pΪg���Һ��ӣ�curΪp�����ӣ������p���ҵ���ת
		//	��ת���������2
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					// ���1
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// ���3 ˫��-->����
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}
					// ���2 ����+��ɫ
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					// ���1
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// ���3 ˫��-->����
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(cur, parent);
					}
					// ���2 ����+��ɫ
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}


		_root->_col = BLACK;
		return std::make_pair(iterator(newnode), true);
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
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		std::cout << root->_value.first << " : " << root->_value.second << std::endl;
		_InOrder(root->_right);

	}
	void InOrder()
	{
		_InOrder(_root);

	}

	bool IsValidRBTree()
	{
		Node* pRoot = _root;

		// ����Ҳ�Ǻ����
		if (nullptr == pRoot)
			return true;

		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_col)
		{
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}

		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* root, size_t k, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == root->_col)
			k++;

		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		Node* parent = root->_parent;
		if (parent && RED == parent->_col && RED == root->_col)
		{
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		// ���root�����ӽڵ㣬��⵱ǰ·���к�ɫ�ڵ�ĸ����Ƿ�������
		if (nullptr == root->_left&& nullptr == root->_right)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
		}

		//�ݹ��ж�������������������������
		return _IsValidRBTree(root->_left, k, blackCount) &&
			_IsValidRBTree(root->_right, k, blackCount);
	}

private:
	Node* _root;
};