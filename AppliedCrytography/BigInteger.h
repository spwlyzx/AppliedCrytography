#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <math.h>
#include <algorithm>

#define GROUP_BIT_NUM 24 //Ĭ��ÿ������λ�����ڵ���16��С��32

const unsigned int MAX_EACH = (1 << GROUP_BIT_NUM) - 1;
const unsigned int MASK_HIGH = (1 << (32 - GROUP_BIT_NUM) - 1) << GROUP_BIT_NUM;
const unsigned int MASK_LOW = (1 << GROUP_BIT_NUM) - 1;

using namespace std;

class BigInteger
{
public:
	vector<unsigned int> data;
	bool isNegative = false;
	unsigned int bitNum;

public:
	BigInteger();
	BigInteger(int origin);
	BigInteger(unsigned int origin);
	BigInteger(string temp);
	void opposite();
	BigInteger getOpposite();
	void normalize();
};

BigInteger operator+(BigInteger &a, BigInteger &b);
BigInteger operator-(BigInteger &a, BigInteger &b);
BigInteger operator-(BigInteger &a);
BigInteger operator*(BigInteger &a, BigInteger &b);
BigInteger operator/(BigInteger &a, BigInteger &b);
BigInteger operator%(BigInteger &a, BigInteger &b);
BigInteger operator>(BigInteger &a, BigInteger &b);
BigInteger operator<(BigInteger &a, BigInteger &b);
BigInteger operator+(BigInteger &a, int &b);
BigInteger operator-(BigInteger &a, int &b);
BigInteger operator*(BigInteger &a, int &b);
BigInteger operator/(BigInteger &a, int &b);
BigInteger operator%(BigInteger &a, int &b);

#endif