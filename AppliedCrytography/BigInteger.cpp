#include "BigInteger.h"

BigInteger::BigInteger()
{
	bitNum = 0;
	isNegative = false;
}

BigInteger::BigInteger(int origin)
{
	if (origin == 0)
	{
		bitNum = 0;
		return;
	}
	if (origin < 0)
	{
		origin = -origin;
		isNegative = true;
	}
	if (origin > MAX_EACH)
	{
		data.push_back(origin & MASK_LOW);
		unsigned int temp = (origin & MASK_HIGH) >> GROUP_BIT_NUM;
		data.push_back(temp);
		bitNum = log2(temp) + 1 + GROUP_BIT_NUM;
	}
	else
	{
		data.push_back(origin);
		bitNum = (int)log2(origin) + 1;
	}
}

BigInteger::BigInteger(unsigned int origin)
{
	if (origin == 0) {
		bitNum = 0;
	}
	else
	{
		if (origin > MAX_EACH)
		{
			data.push_back(origin & MASK_LOW);
			unsigned int temp = (origin & MASK_HIGH) >> GROUP_BIT_NUM;
			data.push_back(temp);
			bitNum = log2(temp) + 1 + GROUP_BIT_NUM;
		}
		else
		{
			data.push_back(origin);
			bitNum = (int)log2(origin) + 1;
		}
	}
}

BigInteger::BigInteger(string temp)
{
	char each_group[BITS_16_NUM];
	const char* chars = temp.c_str();
	int len = temp.length();
	if (len == 0 || len == 1 && chars[0] == '0')
	{
		bitNum = 0;
	}
	else
	{
		int i = 0;
		long temp_each = 0;
		while (len - i > BITS_16_NUM) {
			strncpy(each_group, chars + len - i - BITS_16_NUM, BITS_16_NUM);
			temp_each = strtol(each_group, NULL, 16);
			data.push_back((int)temp_each);
			i += BITS_16_NUM;
		}
		string first_group = temp.substr(0, len - i);
		temp_each = strtol(first_group.c_str(), NULL, 16);
		if (temp_each < 0) {
			temp_each = -temp_each;
			isNegative = true;
		}
		data.push_back(temp_each);
		normalize();
	}
}

BigInteger::BigInteger(long long origin)
{
	if (origin == 0) 
	{
		bitNum = 0;
	}
	else 
	{
		if (origin < 0)
		{
			origin = -origin;
			isNegative = true;
		}
		while (origin > 0) {
			int temp = origin;
			temp = temp & MASK_LOW;
			data.push_back(temp);
			origin = origin >> GROUP_BIT_NUM;
		}
		normalize();
	}
}

BigInteger::BigInteger(unsigned long long origin)
{
	if (origin == 0) {
		bitNum = 0;
	}
	else
	{
		while (origin > 0) {
			int temp = origin;
			temp = temp & MASK_LOW;
			data.push_back(temp);
			origin = origin >> GROUP_BIT_NUM;
		}
		normalize();
	}
}

void BigInteger::opposite()
{
	if (bitNum != 0)
		isNegative ^= true;
}

void BigInteger::normalize()
{
	int j = data.size() - 1;
	if (j < 0 || (j == 0 && data[0] == 0))
	{
		bitNum = 0;
		isNegative = false;
	}
	else 
	{
		while (j >= 0 && data[j] == 0 ) {
			data.pop_back();
			j--;
		}
		if (j == -1)
		{
			bitNum = 0;
		}
		else
		{
			bitNum = (data.size() - 1) * GROUP_BIT_NUM;
			bitNum += log2(data[data.size() - 1]) + 1;
		}
	}
}

string BigInteger::toString16()
{
	if (bitNum == 0)
	{
		return "0";
	}
	unsigned int temp = 0;
	char chars[BITS_16_NUM];
	string total = "";
	for (int i = 0; i < data.size()-1; i++) {
		temp = data[i];
		sprintf(chars,"%06x",temp);//此处未做到随着BITS_16_NUM变更而自动变更
		total = chars + total;
	}
	temp = data[data.size() - 1];
	sprintf(chars, "%x", temp);//此处未做到随着BITS_16_NUM变更而自动变更
	total = chars + total;
	if (isNegative) {
		total = "-" + total;
	}
	return total;
}

BigInteger operator-(const BigInteger &a)
{
	BigInteger temp = a;
	temp.opposite();
	return temp;
}

BigInteger operator+(const BigInteger &a, const BigInteger &b)
{
	if (a.bitNum == 0)
		return b;
	else if (b.bitNum == 0)
		return a;
	if (a.isNegative ^ b.isNegative)
	{
		if (a.isNegative)
		{
			return b - (-a);
		}
		else
		{
			return a - (-b);
		}
	}

	int sa = a.data.size();
	int sb = b.data.size();
	int i = 0;
	int temp = 0;
	int carry = 0;
	BigInteger c;
	int mins = sa < sb ? sa : sb;
	for (; i < mins; i++)
	{
		temp = a.data[i] + b.data[i] + carry;
		if (temp & MASK_HIGH)
		{
			carry = 1;
			temp = temp & MASK_LOW;
		}
		else
		{
			carry = 0;
		}
		c.data.push_back(temp);
	}
	if (sa == sb)
	{
		if (carry == 1)
		{
			c.data.push_back(1);
		}
	}
	else
	{
		if (sa > sb)
		{
			c.data.push_back(a.data[i] + carry);
			for (i++; i < a.data.size(); i++) {
				c.data.push_back(a.data[i]);
			}
		}
		else
		{
			c.data.push_back(b.data[i] + carry);
			for (i++; i < b.data.size(); i++) {
				c.data.push_back(b.data[i]);
			}
		}
	}
	c.isNegative = a.isNegative;
	c.normalize();
	return c;
}

BigInteger operator-(const BigInteger &a, const BigInteger &b)
{
	if (a.bitNum == 0)
		return -b;
	else if (b.bitNum == 0)
		return a;
	if (a.isNegative ^ b.isNegative)
		return a + (-b);
	else
	{
		int sa = a.data.size();
		int sb = b.data.size();
		int i = 0;
		bool carry = false;
		int temp = 0;
		BigInteger c;
		bool isAbigger = a >= b ? !a.isNegative : a.isNegative;
		if (isAbigger) 
		{
			for (; i < sb; i++)
			{
				if (carry)
					temp = a.data[i] - b.data[i] - 1;
				else
					temp = a.data[i] - b.data[i];
				if (temp < 0)
				{
					carry = true;
					temp = temp + MAX_EACH + 1;
				}
				else
				{
					carry = false;
				}
				c.data.push_back(temp);
			}
			for (; carry && i < sa; i++)
			{
				temp = a.data[i] - 1;
				if (temp < 0)
				{
					carry = true;
					temp = temp + MAX_EACH + 1;
				}
				else
				{
					carry = false;
				}
				c.data.push_back(temp);
			}
			for (; i < sa; i++) {
				c.data.push_back(a.data[i]);
			}
		}
		else 
		{
			for (; i < sa; i++)
			{
				if (carry)
					temp = b.data[i] - a.data[i] - 1;
				else
					temp = b.data[i] - a.data[i];
				if (temp < 0)
				{
					carry = true;
					temp = temp + MAX_EACH + 1;
				}
				else
				{
					carry = false;
				}
				c.data.push_back(temp);
			}
			for (; carry && i < sb; i++)
			{
				temp = b.data[i] - 1;
				if (temp < 0)
				{
					carry = true;
					temp = temp + MAX_EACH + 1;
				}
				else
				{
					carry = false;
				}
				c.data.push_back(temp);
			}
			for (; i < sb; i++) {
				c.data.push_back(b.data[i]);
			}
		}
		if (a.isNegative ^ isAbigger)
		{
			c.isNegative = false;
		}
		else
		{
			c.isNegative = true;
		}
		c.normalize();
		return c;
	}
}

BigInteger operator*(const BigInteger &a, const BigInteger &b)
{
	if (a.bitNum == 0 || b.bitNum == 0)
		return 0;
	BigInteger c;
	int asize = a.data.size();
	int bsize = b.data.size();
	int csize = asize*bsize + 1;
	c.data.resize(csize, 0);
	unsigned long long temp, temp_a, temp_b;
	int i, j;
	for (i = 0; i < asize; i++)
	{
		temp_a = a.data[i];
		for (j = 0; j < bsize; j++)
		{
			temp_b = b.data[j];
			temp = temp_a*temp_b;
			c.data[i + j] += temp & LONG_MAKS_LOW;
			c.data[i + j + 1] += temp >> GROUP_BIT_NUM;
		}
	}
	for (i = 0; i < csize; i++)
	{
		if (c.data[i] & MASK_HIGH)
		{
			c.data[i + 1] += c.data[i] >> GROUP_BIT_NUM;
			c.data[i] = c.data[i] & MASK_LOW;
		}
	}
	c.normalize();
	c.isNegative = a.isNegative ^ b.isNegative;
	return c;
}

BigInteger operator/(const BigInteger &a, const BigInteger &b)
{
	if (b.bitNum == 0)
		return NULL;
	else if (a.bitNum == 0)
		return 0;
	else
	{
		int abits = a.bitNum;
		int bbits = b.bitNum;
		if (abits < bbits)
			return 0;
		else if (abits == bbits && a == b)
		{
			return 1;
		}
		else if (a < b)
		{
			return 0;
		}
		else
		{
			int diff = abits - bbits;
			BigInteger tempa = a;//最后储存余数
			BigInteger tempb = b << diff;
			BigInteger result(0);
			while (diff >= 0) {
				if (tempa > tempb)
				{
					tempa = tempa - tempb;
					BigInteger temps(1);
					temps = temps << diff;
					result = result + temps;
				}
				else if (tempa == tempb)
				{
					tempa = tempa - tempb;
					BigInteger temps(1);
					temps = temps << diff;
					result = result + temps;
				}
				tempb = tempb >> 1;
				diff--;
			}
			result.normalize();
			result.isNegative = a.isNegative ^ b.isNegative;
			return result;
		}
	}
}

BigInteger operator%(const BigInteger &a, const BigInteger &b)
{
	return NULL;
}

BigInteger operator<<(const BigInteger &a, const int &b)
{
	if (a.bitNum == 0)
		return 0;
	if (b < 0)
		return NULL;
	else if (b == 0)
	{
		return a;
	}
	int group_move = b / GROUP_BIT_NUM;
	int in_move = b % GROUP_BIT_NUM;
	BigInteger c;
	c = a;
	int size = a.data.size();
	if (!(size*GROUP_BIT_NUM - a.bitNum >= in_move)) {
		c.data.push_back(0);
		size++;
	}
	unsigned int temp1 = 0,temp2;
	for (int i = 0; i < size; i++) {
		temp2 = c.data[i] >> (GROUP_BIT_NUM - in_move);
		c.data[i] = ((c.data[i] << in_move) | temp1) & MAX_EACH;
		temp1 = temp2;
	}
	c.data.insert(c.data.begin(), group_move, 0);
	c.isNegative = a.isNegative;
	c.normalize();
	return c;
}

BigInteger operator>>(const BigInteger &a, const int &b)
{
	if (a.bitNum == 0)
		return 0;
	if (b < 0)
		return NULL;
	else if (b == 0)
	{
		return a;
	}
	int group_move = b / GROUP_BIT_NUM;
	int in_move = b % GROUP_BIT_NUM;
	BigInteger c;
	c = a;
	int size = a.data.size();
	if (in_move > a.bitNum - (size-1)*GROUP_BIT_NUM) {
		group_move++;
	}
	unsigned int mask = (1 << in_move) - 1;
	unsigned int temp1 = 0, temp2;
	for (int i = size - 1; i >=0; i--) {
		temp2 = (c.data[i] & mask) << (GROUP_BIT_NUM - in_move);
		c.data[i] = ((c.data[i] >> in_move) | temp1) & MAX_EACH;
		temp1 = temp2;
	}
	c.data._Pop_back_n(group_move);
	c.isNegative = a.isNegative;
	c.normalize();
	return c;
}

bool operator>(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative) 
	{
		if (a.isNegative)
			return false;
		else 
			return true;
	}
	else if (a.bitNum == 0)
		return b.isNegative;
	else if (b.bitNum == 0)
	{
		if (a.bitNum == 0)
			return false;
		return !a.isNegative;
	}
	else 
	{
		if (a.bitNum < b.bitNum)
			return a.isNegative;
		else if (a.bitNum > b.bitNum)
			return !a.isNegative;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i]) 
				{
					continue;
				}
				else if (a.data[i] > b.data[i])
				{
					return !a.isNegative;
				}
				else
				{
					return a.isNegative;
				}
			}
			return false;
		}
	}
}

bool operator<(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		if (a.isNegative)
			return true;
		else
			return false;
	}
	else if (a.bitNum == 0)
	{
		if (b.bitNum == 0)
			return false;
		return !b.isNegative;
	}
	else if (b.bitNum == 0)
	{
		return a.isNegative;
	}
	else
	{
		if (a.bitNum < b.bitNum)
			return !a.isNegative;
		else if (a.bitNum > b.bitNum)
			return a.isNegative;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i])
				{
					continue;
				}
				else if (a.data[i] > b.data[i])
				{
					return a.isNegative;
				}
				else
				{
					return !a.isNegative;
				}
			}
			return false;
		}
	}
}

bool operator>=(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		if (a.isNegative)
			return false;
		else
			return true;
	}
	else if (a.bitNum == 0)
	{
		if (b.bitNum == 0)
			return true;
		return b.isNegative;
	}
	else if (b.bitNum == 0)
	{
		return !a.isNegative;
	}
	else
	{
		if (a.bitNum < b.bitNum)
			return a.isNegative;
		else if (a.bitNum > b.bitNum)
			return !a.isNegative;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i])
				{
					continue;
				}
				else if (a.data[i] > b.data[i])
				{
					return !a.isNegative;
				}
				else
				{
					return a.isNegative;
				}
			}
			return true;
		}
	}
}

bool operator<=(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		if (a.isNegative)
			return true;
		else
			return false;
	}
	else if (a.bitNum == 0)
	{
		return !b.isNegative;
	}
	else if (b.bitNum == 0)
	{
		if (a.bitNum == 0)
			return true;
		return a.isNegative;
	}
	else
	{
		if (a.bitNum < b.bitNum)
			return !a.isNegative;
		else if (a.bitNum > b.bitNum)
			return a.isNegative;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i])
				{
					continue;
				}
				else if (a.data[i] > b.data[i])
				{
					return a.isNegative;
				}
				else
				{
					return !a.isNegative;
				}
			}
			return true;
		}
	}
}

bool operator==(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		return false;
	}
	else
	{
		if (a.bitNum != b.bitNum)
			return false;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i])
				{
					continue;
				}
				else
					return false;
			}
			return true;
		}
	}
}

bool operator!=(const BigInteger &a, const BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		return true;
	}
	else
	{
		if (a.bitNum != b.bitNum)
			return true;
		else
		{
			for (int i = a.data.size() - 1; i >= 0; i--) {
				if (a.data[i] == b.data[i])
				{
					continue;
				}
				else
					return true;
			}
			return false;
		}
	}
}