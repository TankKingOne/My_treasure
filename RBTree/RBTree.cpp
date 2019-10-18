#include "RBTree.h"
#include "MyMap.h"
#include "MySet.h"

//void test()
//{
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		//cout << "IsBalance:" << t.IsBanlance() << "--->" << e << endl;
//		t.Insert(std::make_pair(e, e));
//	}
//	t.InOrder();
//	cout << t.IsValidRBTree();
//
//	//cout << t.IsBanlance() << endl;
//}

//void test2()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//	AVLTree<int, int> t;
//	for (auto e : a)
//	{
//		cout << "IsBalance:" << t.IsBanlance() << "--->" << e << endl;
//		t.Insert(make_pair(e, e));
//	}
//	t.InOrder();
//
//	cout << t.IsBanlance() << endl;
//}


int main()
{
	testSet();
	testMap();
	//test2();
	system("pause");
	return 0;
}