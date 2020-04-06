//#include <iostream>
//#include <string>
//using namespace std;
//
//int firstUniqChar(string s)
//{
//	int count[256] = { 0 };
//	for (int i = 0; i < s.size(); i++)
//	{
//		++count[s[i]];
//	}
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (1 == count[s[i]])
//			return i;
//	}
//
//	return -1;
//}
//
//int main()
//{
//	string ch;
//	while (cin >> ch)
//	{
//		int ret = firstUniqChar(ch);
//		if (ret == -1)
//		{
//			cout << "-1" << endl;
//		}
//		else
//			cout << ch[ret] << endl;
//	}
//	
//	
//
//	system("pause");
//	return 0;
//}
//
////#include <iostream>
////#include <string>
////using namespace std;
////
////int firstUniqChar(char s[])
////{
////	int size = strlen(s);
////	int count[256] = { 0 };
////	for (int i = 0; i < size; i++)
////	{
////		++count[s[i]];
////	}
////	for (int i = 0; i < size; i++)
////	{
////		if (1 == count[s[i]])
////			return i;
////	}
////
////	return -1;
////}
////
////int main()
////{
////	char ch[2000];
////	while (cin >> ch)
////	{
////		int ret = firstUniqChar(ch);
////		if (ret == -1)
////		{
////			cout << "-1" << endl;
////		}
////		else
////			cout << ch[ret] << endl;
////	}
////
////
////	system("pause");
////	return 0;
////}

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//int LastWordLen(string ch)
//{
//	int i = 0;
//	int begin = 0, end = 0;
//	int Long = 0;
//	while (ch[i])
//	{
//		begin = i;
//		while (ch[i] != ' ' && ch[i + 1])
//		{
//			i++;
//		}
//		end = i;
//		Long = end - begin;
//	}
//	
//	return Long;
//}

//int main()
//{
//	string ch;
//	int ret;
//	while (getline(cin, ch))
//	{
//		
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string ch;
//	int pos = 0;
//	while (getline(cin, ch))
//	{
//		pos = ch.rfind(' ');
//		cout << ch.size() - pos - 1 << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include <math.h>
//
//class Solution {
//public:
//	bool isLegal(char c)
//	{
//		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
//			return true;
//		return false;
//	}
//
//	bool isPalindrome(string s) 
//	{
//		if (s.empty())
//			return true;
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (!isLegal(s[begin]) && begin < end)
//			{
//					begin++;
//			}
//
//			while (!isLegal(s[end]) && begin < end)
//			{
//				end--;
//			}
//
//			//// 从前往后找一个数字字符或者字母
//			//while (begin != end)
//			//{
//			//	if (isLegal(s[begin]))
//			//		break;
//			//	++begin;
//			//}
//			//// 从后往前找一个数字字符或者字母
//			//while (begin < end)
//			//{
//			//	if (isLegal(s[end]))
//			//		break;
//			//	--end;
//			//}
//
//			//if (end <= begin)
//			//	return true;
//
//
//			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//				return false;
//			else
//			{
//				begin++;
//				end--;
//			}
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
//
//	system("pause");
//	return 0;
//}

//wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong wrong****
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		string add;
//		int Lsize = num1.size();
//		int Ssize = num2.size();
//		if (num1.size() < num2.size())
//		{
//			Lsize = num2.size();
//			Ssize = num1.size();
//		}
//		int x = Lsize - Ssize;
//		int i = 0;
//		int j;
//		add.push_back('0');
//	
//		for (int i = 0; i < Lsize - Ssize; i++)
//		{
//			if (num1.size() < num2.size())
//			{
//				add.push_back(num2[i]);
//			}
//			else
//			{
//				add.push_back(num1[i]);
//			}
//		}
//
//		for (int i = x; i < Lsize; i++)
//		{
//			if (num1.size() < num2.size())
//			{
//				int sumi = (num1[i] - '0') + (num2[i+x] - '0');
//				if (sumi >= 10)
//				{
//					if (i == x)
//					{
//						add.push_back(1 + '0');
//						sumi -= 10;
//						j = 1;
//					}
//					else
//					{
//						add[i - 1 - x]++;
//						sumi -= 10;
//					}	
//				}
//				add.push_back(sumi + '0');
//				j++;
//			}
//			else
//			{
//				int sumi = (num1[i+x] - '0') + (num2[i] - '0');
//				if (sumi >= 10)
//				{
//					if (i == x)
//					{
//						add.push_back(1 + '0');
//						sumi -= 10;
//						j = 1;
//					}
//					else
//					{
//						add[i - 1 - x]++;
//						sumi -= 10;
//					}
//				
//				}
//				add.push_back(sumi + '0');
//				j++;
//			}
//		}
//
//		return add;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string s1 = "55555", s2 = "555551";
//	string ret = s.addStrings(s1, s2);
//	cout << ret << endl;
//
//	system("pause");
//}

//class Solution {
//public:
//	string addStrings(string num1, string num2)
//	{
//		//使 num1 和 num2 长度相同（短的前面补0）
//		while (num1.size() < num2.size())
//		{
//			num1 = '0' + num1;
//		}
//		while (num1.size() > num2.size())
//		{
//			num2 = '0' + num2;
//		}
//		string val;
//		int res = 0;
//		for (int i = num1.size() - 1; i >= 0; i--)
//		{
//			int temp = num1[i] - '0' + num2[i] - '0'; //记录两个 数字 和
//			res = res + temp;
//			val = to_string(res % 10) + val;          //将 int 转换成 string ，并 "前插"
//			res /= 10;                                //记录进位
//		}
//		if (res != 0)
//			val = to_string(res) + val;
//		return val;
//	}
//};

//int main()
//{
//	Solution s;
//	string s1 = "555555555555555555555", s2 = "55555555555555555";
//	string ret = s.addStrings(s1, s2);
//	cout << ret << endl;
//
//	system("pause");
//}


//class Solution {
//public:
//	void _reversalStr(string &s, int begin, int k)
//	{
//		int end = begin + k - 1;
//		while (begin < end)
//		{
//			swap(s[begin], s[end]);
//			++begin;
//			--end;
//		}
//	}
//
//	string reverseStr(string s, int k) 
//	{
//		int begin = 0, end = s.size();
//		int i;
//		for (i = 0; i < s.size(); i+=2*k)
//		{
//			begin = i;
//			if (s.size() - begin >= 2 * k)
//			{
//				begin = i;
//				_reversalStr(s, begin, k);
//			}
//
//			else if (s.size() - begin < k)
//			{
//				_reversalStr(s, begin, s.size() - begin);
//			}
//
//			else
//			{
//				_reversalStr(s, begin, k);
//				return s;
//			}
//		}
//
//		return s;
//	}
//};

//int main()
//{
//	Solution S;
//	int k = 39;
//	string s("hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl");
//	//cin >> s >> k;
//	string ret = S.reverseStr(s, k);
//	cout << ret << endl;
//	
//	system("pause");
//	return 0;
//}


//class Solution {
//public:
//	void _reverseWords(string& s, int begin, int end)
//	{
//		while (begin < end)
//		{
//			swap(s[begin], s[end]);
//			++begin;
//			--end;
//		}
//	}
//
//	string reverseWords(string s) 
//	{
//		int i = 0;
//		int end;
//		while (i < s.size())
//		{
//			end = s.find(' ', i);
//			if (s.find(' ', i) != -1)
//			{
//				_reverseWords(s, i, end - 1);
//				i = end + 1;
//			}
//			else
//			{
//				_reverseWords(s, i, s.size() - 1);
//				break;
//			}
//		}
//
//		return s;
//	}
//};
//
//int main()
//{
//	Solution S;
//	string s("Let's take LeetCode contest");
//	string ret = S.reverseWords(s);
//	cout << ret << endl;
//
//	system("pause");
//	return 0;
//}


//class Solution {
//public:
//	string s;
//
//	string multiply(string num1, string num2)
//	{
//		if (num1[0] == '0' || num2[0] == '0')
//		{
//			s.push_back('0');
//			return s;
//		}
//		int len = num1.size() + num2.size();
//		int *sum = new int[len];
//
//		for (int i = 0; i < num1.size() + num2.size(); i++)
//		{
//			sum[i] = 0;
//		}
//
//		for (int i = num1.size() - 1; i >= 0; i--)
//		{
//			for (int j = num2.size() - 1; j >= 0; j--)
//			{
//				sum[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
//			} 
//		}
//		
//		//进位
//		int carry = 0;
//		for (int i = len - 1; i >= 0; i--) 
//		{
//			sum[i] += carry;
//			carry = sum[i] / 10;
//			sum[i] %= 10;
//		}
//
//		//处理前面的0
//		int beginIndex = 0;
//		while (beginIndex < (len - 1) && sum[beginIndex] == 0)
//		{
//			beginIndex++;
//		}
//
//		for (int i = 0; i < len; i++)
//		{
//			s.push_back(sum[i] + '0');
//		}
//
//		if (s[0] == '0')
//			s.erase(0, 1);
//
//		return s;
//	}
//};
//
//int main()
//{
//	Solution s;
//	string s1 = "9", s2 = "1";
//	string ret = s.multiply(s1, s2);
//	cout << ret << endl;
//
//	system("pause");
//}