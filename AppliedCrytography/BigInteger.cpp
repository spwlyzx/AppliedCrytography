#include "BigInteger.h"

BigInteger::BigInteger()
{
	data.resize(64);
}

BigInteger::BigInteger(int origin)
{
	if (origin < 0)
	{
		origin = -origin;
		isNegative = true;
	}
	if (origin > MAX_EACH)
	{
		data.push_back(origin & MASK_LOW);
		int temp = (origin & MASK_HIGH) >> GROUP_BIT_NUM;
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
	if (origin > MAX_EACH)
	{
		data.push_back(origin & MASK_LOW);
		int temp = (origin & MASK_HIGH) >> GROUP_BIT_NUM;
		data.push_back(temp);
		bitNum = log2(temp) + 1 + GROUP_BIT_NUM;
	}
	else
	{
		data.push_back(origin);
		bitNum = (int)log2(origin) + 1;
	}
}

BigInteger::BigInteger(string temp)
{
	//TODO
}

void BigInteger::opposite()
{
	isNegative ^= true;
}

void BigInteger::normalize()
{
	bitNum = (data.size() - 1) * 24;
	bitNum += log2(data[data.size() - 1]) + 1;
}

BigInteger operator-(BigInteger &a)
{
	BigInteger temp = a;
	temp.isNegative = a.isNegative ^ true;
	return temp;
}

BigInteger operator+(BigInteger &a, BigInteger &b)
{
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
	else
	{
		int sa = a.data.size();
		int sb = b.data.size();
		int i = 0;
		int carry = 0;
		int temp = 0;
		BigInteger c;
		for (; i <= min(sa, sb); i++)
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
}

BigInteger operator-(BigInteger &a, BigInteger &b)
{
	if (a.isNegative ^ b.isNegative)
	{
		if (a.isNegative)
		{
			return -((-a) + b);
		}
		else
		{
			return a + (-b);
		}
	}
	else
	{
		int sa = a.data.size();
		int sb = b.data.size();
		int i = 0;
		int carry = 0;
		int temp = 0;
		BigInteger c;

	}
}

BigInteger operator*(BigInteger &a, BigInteger &b)
{
	return NULL;
}

BigInteger operator/(BigInteger &a, BigInteger &b)
{
	return NULL;
}

BigInteger operator%(BigInteger &a, BigInteger &b)
{
	return NULL;
}