#include "BigInteger.h"

bool isNotInit = true;

BigInteger::BigInteger()
{
	bitNum = 0;
	isNegative = false;
	data.reserve(NORMAL_VECTOR_SIZE);
}

BigInteger::BigInteger(int origin)
{
	data.reserve(NORMAL_VECTOR_SIZE);
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
	data.reserve(NORMAL_VECTOR_SIZE);
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
	data.reserve(NORMAL_VECTOR_SIZE);
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
	data.reserve(NORMAL_VECTOR_SIZE);
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
	data.reserve(NORMAL_VECTOR_SIZE);
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

void InitRandom()
{
	if (isNotInit)
	{
		srand(unsigned(time(0)));
		isNotInit = false;
	}
}

//使得当前的整数变为其相反数
void BigInteger::opposite()
{
	if (bitNum != 0)
		isNegative ^= true;
}

//使得当前整数的位数标准化，这个操作会消除所有高位无用的0占据的数组空间，从而确保数组大小的标准性
void BigInteger::normalize()
{
	int j = data.size() - 1;
	if (j < 0 || (j == 0 && !data[0]))
	{
		bitNum = 0;
		isNegative = false;
	}
	else 
	{
		while (j >= 0 && !data[j]) {
			data.pop_back();
			j--;
		}
		if (j == -1)
		{
			bitNum = 0;
			isNegative = false;
		}
		else
		{
			bitNum = (data.size() - 1) * GROUP_BIT_NUM;
			bitNum += log2(data[data.size() - 1]) + 1;
		}
	}
}

//返回当前大整数转换成字符串的结果，字母为小写
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

//将当前的数增加1
void BigInteger::increment()
{
	if (bitNum == 0) {
		data.push_back(1);
		bitNum = 1;
	}
	else if (isNegative)
	{
		int size = data.size();
		for (int i = 0; i < size; i++) {
			if (data[i] == 0)
				data[i] = MAX_EACH;
			else
			{
				data[i]--;
				break;
			}
		}
		normalize();
	}
	else
	{
		bool temp = true;
		int size = data.size();
		for (int i = 0; i < size; i++) {
			data[i]++;
			if (data[i] > MAX_EACH)
				data[i] = 0;
			else
			{
				temp = false;
				break;
			}
		}
		if (temp)
			data.push_back(1);
		normalize();
	}
}

//若当前数字小于MAX_EACH，则返回当前数字的int形式，否则返回-1
int BigInteger::getInt()
{
	if (bitNum == 0)
		return 0;
	else if (bitNum < 25)
		return data[0];
	else
		return -1;
}

//返回a最后r位组成的数字
BigInteger mod_r(BigInteger a, int rbits)
{
	if (a.bitNum <= rbits)
		return a;
	BigInteger b;
	int groups = rbits / GROUP_BIT_NUM;
	int remains = rbits % GROUP_BIT_NUM;
	int i;
	for (i = 0; i < groups; i++)
		b.data.push_back(a.data[i]);
	b.data.push_back(a.data[i] & ((1 << remains) - 1));
	b.normalize();
	return b;
}

//产生一个bits位的大质数
BigInteger producePrime(int bits)
{
	int primes_mod[primes_size] = { 0 };
	BigInteger result = produceBigIntegerP(bits);
	bool flag = true;
	for (int i = 0; i < primes_size; i++)
	{
		primes_mod[i] = (result%primes[i]).getInt();
	}
	for (int i = 0; i < primes_size; i++)
	{
		if (primes_mod[i] == 0)
		{
			flag = false;
			break;
		}
	}
	if (flag && isPrime(result))
		return result;
	else
	{
		while (true) {
			result.increment();
			result.increment();
			flag = true;
			for (int i = 0; i < primes_size; i++)
			{
				primes_mod[i] = (primes_mod[i] + 2) % primes[i];
				if (primes_mod[i] == 0)
				{
					flag = false;
				}
			}
			if (flag && isPrime(result))
				break;
		}
		return result;
	}
}

//获取最大公约数
BigInteger gcd(const BigInteger &a, const BigInteger &b)
{
	if (b.bitNum == 0)
		return a;
	else
		return gcd(b,a%b);
}

//扩展欧几里得算法，ax+by = gcd(a,b)，此处默认gcd为1
BigInteger extendEclid(const BigInteger &a, const BigInteger &b, BigInteger &x, BigInteger &y)
{
	if (b.bitNum == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		BigInteger m, n;
		BigInteger d = extendEclid(b, a%b, m, n);
		x = n;
		y = m - (a / b)*n;
		return d;
	}
}

//检测正整数n是否位素数，若为负数或复合数，则返回false
bool isPrime(const BigInteger& n)
{
	if (n.isNegative || n.bitNum <= 1)
		return true;
	BigInteger n_1 = n - 1;
	int size = n_1.data.size();
	int s = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (n_1.data[i] == 0)
			s += GROUP_BIT_NUM;
		else
			break;
	}
	unsigned int temp = n_1.data[i];
	while ((temp & 1) ^ 1) {
		temp = temp >> 1;
		s++;
	}
	BigInteger d = n_1 >> s;
	BigInteger x0;
	BigInteger x1;
	BigInteger a;
	BigInteger b;
	for (int j = 0; j < MILLER_RABIN_TIMES; j++)
	{
		a = produceBigInteger(n_1);
		while (b == a)
			a.increment();
		b = a;
		if (gcd(a, n) > 1)
			return false;
		bool flag = true;
		x0 = modularExp(a, d, n);
		for (i = 0; i < s; i++) {
			if (x0.bitNum == 1) 
			{
				flag = false;
				break;
			}
			x0 = (x0 * x0) % n;
		}
		if (x0.bitNum == 1)
			flag = false;
		if (flag)
			return false;
	}
	return true;
}

//返回b在模a下的逆，若返回值为NULL则表明模a下逆不存在
BigInteger inverseMod(const BigInteger &b, const BigInteger &a)
{
	if (gcd(a, b) > 1)
		return NULL;
	BigInteger x, y;
	extendEclid(b, a, x, y);
	while (x < 0)
		x = x + a;
	return x;
}

//返回montogomery模乘结果
BigInteger montogomeryProduction(const BigInteger& a, const BigInteger& b, const BigInteger& n, const BigInteger& n_s)
{
	int rbits = n.bitNum;
	BigInteger ab = a * b;
	BigInteger t = mod_r(ab, rbits);
	BigInteger m = mod_r((t * n_s), rbits);
	BigInteger u = (ab + m*n) >> rbits;
	if (u >= n)
		return u - n;
	return u;
}

//返回a的b次方在n下的模
BigInteger modularExp(const BigInteger& a, const BigInteger& e, const BigInteger& n)
{
	BigInteger r_reverse, n_s;
	BigInteger r(1);
	int rbits = n.bitNum;
	r = r << rbits;
	extendEclid(r, n, r_reverse, n_s);
	if (r_reverse < 0)
	{
		r_reverse = r_reverse + n;
		n_s = n_s - r;
		n_s.opposite();
	}
	else
		n_s.opposite();
	BigInteger a_s = (a << rbits) % n;
	BigInteger x_s = (BigInteger(1) << rbits) % n;
	for (int i = e.bitNum-1; i >= 0; i--)
	{
		x_s = montogomeryProduction(x_s, x_s, n, n_s);
		if (e.data[i / GROUP_BIT_NUM] & (1 << (i%GROUP_BIT_NUM)))
			x_s = montogomeryProduction(a_s, x_s, n, n_s);
	}
	return montogomeryProduction(x_s, 1, n, n_s);
}

//返回一个第一位为1的bits位的末位为1的大正整数
BigInteger produceBigIntegerP(int bits)
{
	InitRandom();
	if (bits <= 0)
		return NULL;
	BigInteger result;
	int groups = bits / GROUP_BIT_NUM;
	int remains = bits % GROUP_BIT_NUM;
	while (groups > 0) {
		result.data.push_back(rand() & MAX_EACH);
		groups--;
	}
	if (remains != 0)
		result.data.push_back(rand() & ((1 << remains) - 1) | (1 << (remains - 1)));
	result.data[0] = result.data[0] | 1;
	result.normalize();
	return result;
}

//返回一个随机生成的最多为bits位的大正整数
BigInteger produceBigInteger(int bits)
{
	InitRandom();
	if (bits <= 0)
		return NULL;
	BigInteger result;
	int groups = bits / GROUP_BIT_NUM;
	int remains = bits % GROUP_BIT_NUM;
	while (groups > 0)
	{
		result.data.push_back(rand() & MAX_EACH);
		groups--;
	}
	if(remains!=0)
		result.data.push_back(rand() & ((1 << remains) - 1));
	result.normalize();
	return result;
}

//返回一个随机生成的小于n的大正整数
BigInteger produceBigInteger(const BigInteger& n)
{
	InitRandom();
	int bits = n.bitNum;
	if (bits <= 1)
		return NULL;
	BigInteger result;
	int groups = bits / GROUP_BIT_NUM;
	int remains = bits % GROUP_BIT_NUM;
	if (remains == 0) {
		groups--;
		remains = GROUP_BIT_NUM;
	}
	while (groups > 0)
	{
		result.data.push_back(rand() & MAX_EACH);
		groups--;
	}
	result.data.push_back(rand() % n.data[n.data.size() - 1]);
	result.normalize();
	return result;
}

//将一个长字符串转化为一系列BigInteger
void transferToBigIntegers(vector<BigInteger> &bigs, const string &message, const int& bits)
{
	bigs.clear();
	const char* temp = message.c_str();
	unsigned char x, y, z;
	unsigned int total;
	int i, j;
	int size = message.size();
	int each = bits / 8 - 3;
	for (j = 0; j < size; j = j + each)
	{
		BigInteger temp2;
		for (i = j; i < size && i < j + each; i = i + 3) {
			x = temp[i];
			if (i + 1 < size && i + 1 < j + each)
				y = temp[i + 1];
			else
				y = 0;
			if (i + 2 < size && i + 2 < j + each)
				z = temp[i + 2];
			else
				z = 0;
			total = (x << 16) + (y << 8) + z;
			temp2.data.push_back(total);
		}
		temp2.normalize();
		bigs.push_back(temp2);
	}
}

//将一系列BigInteger转化为一个长字符串
void transferToString(const vector<BigInteger> &bigs, string &message, const int& bits)
{
	message = "";
	int i, j;
	unsigned char x, y, z;
	for (j = 0; j < bigs.size(); j++)
	{
		for (i = 0; i < bigs[j].data.size(); i++) {
			unsigned int temp = bigs[j].data[i];
			x = temp >> 16;
			y = temp >> 8;
			z = temp;
			if (x != 0)
				message.push_back(x);
			if (y != 0)
				message.push_back(y);
			if (z != 0)
				message.push_back(z);
		}
	}
}

//将一个16进制长字符串转化为一系列BigInteger
void transferToBigIntegers16(vector<BigInteger> &bigs, const string &message, const int& bits)
{
	bigs.clear();
	int pos;
	for (int i = 0; i < message.length();) {
		pos = message.find("|", i);
		string substr;
		if (string::npos == pos) 
		{
			substr = message.substr(i, message.length() - i);
			bigs.push_back(BigInteger(substr));
			break;
		}
		else
		{
			substr = message.substr(i, pos - i);
			bigs.push_back(BigInteger(substr));
			i = pos + 1;
		}
	}
}

//将一系列BigInteger转化为一个16进制长字符串
void transferToString16(vector<BigInteger> &bigs, string &message, const int& bits)
{
	message = "";
	int num = bigs.size();
	string temp;
	int i;
	for (i = 0; i < num - 1; i++)
	{
		temp = bigs[i].toString16();
		message = message + temp + "|";
	}
	temp = bigs[i].toString16();
	message = message + temp;
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
			return b - (-a);
		else
			return a - (-b);
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
			carry = 0;
		c.data.push_back(temp);
	}
	if (sa == sb)
	{
		if (carry == 1)
			c.data.push_back(1);
	}
	else
	{
		if (sa > sb)
		{
			c.data.push_back(a.data[i] + carry);
			for (i++; i < a.data.size(); i++)
				c.data.push_back(a.data[i]);
		}
		else
		{
			c.data.push_back(b.data[i] + carry);
			for (i++; i < b.data.size(); i++)
				c.data.push_back(b.data[i]);
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
		else if (a < b ? !a.isNegative : a.isNegative)
		{
			return 0;
		}
		else
		{
			int diff = abits - bbits;
			BigInteger tempa = a;//最后储存余数
			if (a.isNegative)
				tempa.opposite();
			BigInteger tempb = b << diff;
			if (b.isNegative)
				tempb.opposite();
			BigInteger result;
			while (diff >= 0) {
				if (tempa >= tempb)
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
	if (b.bitNum == 0)
		return NULL;
	else if (a.bitNum == 0)
		return 0;
	else
	{
		int abits = a.bitNum;
		int bbits = b.bitNum;
		if (abits < bbits)
			return a;
		else if (abits == bbits && a == b)
		{
			return 0;
		}
		else if (a < b ? !a.isNegative : a.isNegative)
		{
			return a;
		}
		else
		{
			int diff = abits - bbits;
			BigInteger tempa = a;//最后储存余数
			if (a.isNegative)
				tempa.opposite();
			BigInteger tempb = b << diff;
			if (b.isNegative)
				tempb.opposite();
			while (diff >= 0) {
				if (tempa >= tempb)
					tempa = tempa - tempb;
				tempb = tempb >> 1;
				diff--;
			}
			tempa.normalize();
			if (a.isNegative)
				tempa.opposite();
			return tempa;
		}
	}
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
	int size = a.data.size();
	unsigned int mask = (1 << in_move) - 1;
	unsigned int temp1 = 0, temp2;
	for (int i = group_move; i < size; i++) {
		c.data.push_back(a.data[i]);
	}
	for (int i = c.data.size()-1; i>=0; i--) {
		temp2 = (c.data[i] & mask) << (GROUP_BIT_NUM - in_move);
		c.data[i] = ((c.data[i] >> in_move) | temp1);
		temp1 = temp2;
	}
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

bool operator==(const BigInteger &a, const int &b)
{
	if (a.bitNum == 0)
	{
		if (b == 0)
			return true;
		else
			return false;
	}
	if (a.isNegative ^ (b < 0))
		return false;
	int temp = log2(b) + 1;
	if (a.bitNum ^ temp)
		return false;
	if (a.data[0] == b)
		return true;
	else
		return false;
}

bool operator!=(const BigInteger &a, const int &b)
{
	if (a.bitNum == 0)
	{
		if (b == 0)
			return false;
		else
			return true;
	}
	if (a.isNegative ^ (b < 0))
		return true;
	int temp = log2(b) + 1;
	if (a.bitNum ^ temp)
		return true;
	if (a.data[0] == b)
		return false;
	else
		return true;
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
