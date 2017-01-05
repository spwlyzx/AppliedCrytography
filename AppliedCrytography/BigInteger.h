#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <math.h>
#include <algorithm>

//默认每组数的位数大于等于16，小于32，且是4的倍数以确保满足16进制的运算
#define GROUP_BIT_NUM 24 

const unsigned int BITS_16_NUM = GROUP_BIT_NUM / 4;
const unsigned int MAX_EACH = (1 << GROUP_BIT_NUM) - 1;
const unsigned int MASK_HIGH = ((1 << (32 - GROUP_BIT_NUM)) - 1) << GROUP_BIT_NUM;
const unsigned int MASK_LOW = (1 << GROUP_BIT_NUM) - 1;
const unsigned long long LONG_MAKS_LOW = (1 << GROUP_BIT_NUM) - 1;
const unsigned long long LONG_MAKS_MID = ((1 << GROUP_BIT_NUM) - 1) << GROUP_BIT_NUM;

using namespace std;

class BigInteger
{
public:
	vector<unsigned int> data;
	bool isNegative = false;
	unsigned int bitNum;

public:
	//默认构造一个值为0的数
	BigInteger();
	//使用一个有符号整数来初始化
	BigInteger(int origin);
	//使用一个无符号整数来初始化
	BigInteger(unsigned int origin);
	//使用一个16进制的字符串来初始化，未进行对字符串正确性的检查
	BigInteger(string temp);
	//使用一个long long类型的整数来初始化
	BigInteger(long long origin);
	//使用一个unsigned long long类型的整数来初始化
	BigInteger(unsigned long long origin);
	//使得当前的整数变为其相反数
	void opposite();
	//使得当前整数的位数标准化，这个操作会消除所有高位无用的0占据的数组空间，从而确保数组大小的标准性
	void normalize();
	//返回当前大整数转换成字符串的结果，字母为小写
	string toString16();
};

BigInteger operator-(const BigInteger &a);
BigInteger operator+(const BigInteger &a, const BigInteger &b);
BigInteger operator-(const BigInteger &a, const BigInteger &b);
BigInteger operator*(const BigInteger &a, const BigInteger &b);
BigInteger operator/(const BigInteger &a, const BigInteger &b);
BigInteger operator%(const BigInteger &a, const BigInteger &b);
BigInteger operator<<(const BigInteger &a, const int &b);
BigInteger operator>>(const BigInteger &a, const int &b);
bool operator>(const BigInteger &a, const BigInteger &b);
bool operator<(const BigInteger &a, const BigInteger &b);
bool operator>=(const BigInteger &a, const BigInteger &b);
bool operator<=(const BigInteger &a, const BigInteger &b);
bool operator==(const BigInteger &a, const BigInteger &b);
bool operator!=(const BigInteger &a, const BigInteger &b);

#endif