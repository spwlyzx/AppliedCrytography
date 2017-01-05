#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <math.h>
#include <algorithm>

//Ĭ��ÿ������λ�����ڵ���16��С��32������4�ı�����ȷ������16���Ƶ�����
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
	//Ĭ�Ϲ���һ��ֵΪ0����
	BigInteger();
	//ʹ��һ���з�����������ʼ��
	BigInteger(int origin);
	//ʹ��һ���޷�����������ʼ��
	BigInteger(unsigned int origin);
	//ʹ��һ��16���Ƶ��ַ�������ʼ����δ���ж��ַ�����ȷ�Եļ��
	BigInteger(string temp);
	//ʹ��һ��long long���͵���������ʼ��
	BigInteger(long long origin);
	//ʹ��һ��unsigned long long���͵���������ʼ��
	BigInteger(unsigned long long origin);
	//ʹ�õ�ǰ��������Ϊ���෴��
	void opposite();
	//ʹ�õ�ǰ������λ����׼��������������������и�λ���õ�0ռ�ݵ�����ռ䣬�Ӷ�ȷ�������С�ı�׼��
	void normalize();
	//���ص�ǰ������ת�����ַ����Ľ������ĸΪСд
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