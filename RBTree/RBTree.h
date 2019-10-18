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
	// 1.空树，插入黑色根结点
	// 2.插入红节点，如果父亲是黑色，满足条件
	// 3.插入红节点，如果父亲是红色
	std::pair<iterator, bool> Insert(const V& value)
	{
		// 1.按搜索树的规则进行插入
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

		cur->_col = RED;       // 如果新插入结点为黑色，违反4规则，需要处理所有路径，插入红色，可能违反3规则，只需处理当前路径
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

		// 平衡
		// 1.cur为红，p为红，g为黑，u存在且为红
		//   解决方式：将p,u改为黑，g改为红，然后把g当成cur，继续向上调整。
		// 2.cur为红，p为红，g为黑，u不存在/u为黑
		//   2.1 p为g的左孩子，cur为p的左孩子，则进行右单旋转；
		//   2.2 p为g的右孩子，cur为p的右孩子，则进行左单旋转
		//  p、g变色--p变黑，g变红
		// 3.cur为红，p为红，g为黑，u不存在/u为黑
		//   3.1 p为g的左孩子，cur为p的右孩子，则针对p做左单旋转；
		//   3.2 p为g的右孩子，cur为p的左孩子，则针对p做右单旋转
		//	则转换成了情况2
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					// 情况1
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// 情况3 双旋-->单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}
					// 情况2 单旋+变色
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
					// 情况1
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// 情况3 双旋-->单旋
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(cur, parent);
					}
					// 情况2 单旋+变色
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

		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* root, size_t k, const size_t blackCount)
	{
		if (nullptr == root)
			return true;

		// 统计黑色节点的个数
		if (BLACK == root->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		Node* parent = root->_parent;
		if (parent && RED == parent->_col && RED == root->_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		// 如果root是因子节点，检测当前路径中黑色节点的个数是否有问题
		if (nullptr == root->_left&& nullptr == root->_right)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
		}

		//递归判断左右子树都满足红黑树的性质
		return _IsValidRBTree(root->_left, k, blackCount) &&
			_IsValidRBTree(root->_right, k, blackCount);
	}

private:
	Node* _root;
};