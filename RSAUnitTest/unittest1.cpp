#include "stdafx.h"
#include "CppUnitTest.h"
#include "BigInteger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RSAUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//toString16()和normalize()函数已经被隐含在其他测试用例中
		//测试string构造函数
		TEST_METHOD(Constructors_String)
		{
			//字符串构造
			string test_string1("ab98287e98d7897f57d5ac768e875110340");
			BigInteger test1(test_string1);
			Assert::AreEqual(test_string1, test1.toString16());
		}

		//测试unsigned int构造函数
		TEST_METHOD(Constructors_U_Int)
		{
			unsigned int test_int1 = 39916800;
			char chars[10];
			sprintf(chars, "%x", test_int1);
			string test_string(chars);
			BigInteger test(test_int1);
			Assert::AreEqual(test_string, test.toString16());

			unsigned int test_int2 = 0;
			char chars2[10];
			sprintf(chars2, "%x", test_int2);
			string test_string2(chars);
			BigInteger test2(test_int1);
			Assert::AreEqual(test_string2, test2.toString16());
		}

		//测试int构造函数
		TEST_METHOD(Constructors_Int)
		{
			int test_int1 = 39916800;
			char chars[10];
			string test_string1;

			sprintf(chars, "%x", test_int1);
			test_string1 = chars;
			BigInteger test1(test_int1);
			Assert::AreEqual(test_string1, test1.toString16());

			int test_int2 = -39916800;
			char chars2[10];
			string test_string2;

			sprintf(chars2, "%x", -test_int2);
			test_string2 = chars2;
			test_string2 = "-" + test_string2;
			BigInteger test2(test_int2);
			Assert::AreEqual(test_string2, test2.toString16());
		}

		//测试long long构造函数
		TEST_METHOD(Constructors_Long)
		{
			long long test_int1 = 355687428096000;
			char chars[20];
			string test_string1;

			sprintf(chars, "%llx", test_int1);
			test_string1 = chars;
			BigInteger test1(test_int1);
			Assert::AreEqual(test_string1, test1.toString16());

			long long test_int2 = -355687428096000;
			char chars2[20];
			string test_string2;

			sprintf(chars2, "%llx", -test_int2);
			test_string2 = chars2;
			test_string2 = "-" + test_string2;
			BigInteger test2(test_int2);
			Assert::AreEqual(test_string2, test2.toString16());
		}

		//测试unsigned long long构造函数
		TEST_METHOD(Constructors_U_Long)
		{
			unsigned long long test_int1 = 355687428096000;
			char chars[20];
			string test_string1;

			sprintf(chars, "%llx", test_int1);
			test_string1 = chars;
			BigInteger test1(test_int1);
			Assert::AreEqual(test_string1, test1.toString16());

			unsigned long long test_int2 = 9223372036854776000;
			char chars2[20];
			string test_string2;

			sprintf(chars2, "%llx", test_int2);
			test_string2 = chars2;
			BigInteger test2(test_int2);
			Assert::AreEqual(test_string2, test2.toString16());
		}

		//测试-（取相反数）功能
		TEST_METHOD(Function_Opposite)
		{
			long long test_int1 = 355687428096000;
			char chars[20];
			string test_string1;

			sprintf(chars, "%llx", test_int1);
			test_string1 = chars;
			test_string1 = "-" + test_string1;
			BigInteger test1(test_int1);
			test1.opposite();
			Assert::AreEqual(test_string1, test1.toString16());

			unsigned long long test_int2 = 9223372036854776000;
			char chars2[20];
			string test_string2;

			sprintf(chars2, "%llx", test_int2);
			test_string2 = chars2;
			test_string2 = "-"+test_string2;
			BigInteger test2(test_int2);
			Assert::AreEqual(test_string2, (-test2).toString16());
		}

		//测试>功能
		TEST_METHOD(Function_Greater)
		{
			long long test_int1 = 3556874280960232200;
			long long test_int2 = 9223372036850233200;
			long long test_int3 = 3556874280960232200;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(true, test2 > test1);
			Assert::AreEqual(false, test3 > test1);
			test1.opposite();
			test2.opposite();
			Assert::AreEqual(true, test3 > test1);
			Assert::AreEqual(true, test1 > test2);
		}

		//测试>=功能
		TEST_METHOD(Function_GreaterEqual)
		{
			long long test_int1 = 3556874280960232200;
			long long test_int2 = 9223372036850233200;
			long long test_int3 = 3556874280960232200;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(true, test2 >= test1);
			Assert::AreEqual(true, test3 >= test1);
			test1.opposite();
			test2.opposite();
			Assert::AreEqual(true, test3 >= test1);
			Assert::AreEqual(true, test1 >= test2);
			test3.opposite();
			Assert::AreEqual(true, test1 >= test3);
		}

		//测试<功能
		TEST_METHOD(Function_Less)
		{
			long long test_int1 = 234534554345343;
			long long test_int2 = 23144363373546345;
			long long test_int3 = 234534554345343;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(false, test2 < test1);
			Assert::AreEqual(false, test3 < test1);
			test1.opposite();
			test2.opposite();
			Assert::AreEqual(false, test3 < test1);
			Assert::AreEqual(true, test1 < test3);
			Assert::AreEqual(true, test2 < test1);
		}

		//测试<=功能
		TEST_METHOD(Function_LessEqual)
		{
			long long test_int1 = 123523473936554;
			long long test_int2 = 9223372036850233200;
			long long test_int3 = 123523473936554;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(false, test2 <= test1);
			Assert::AreEqual(true, test1 <= test2);
			Assert::AreEqual(true, test3 <= test1);
			test1.opposite();
			test2.opposite();
			Assert::AreEqual(false, test3 <= test1);
			Assert::AreEqual(true, test1 <= test3);
			Assert::AreEqual(true, test2 <= test1);
			test3.opposite();
			Assert::AreEqual(true, test1 <= test3);
		}

		//测试==功能
		TEST_METHOD(Function_Equal)
		{
			long long test_int1 = 3556874280960232200;
			long long test_int2 = 9223372036850233200;
			long long test_int3 = 3556874280960232200;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(true, test1 == test3);
			Assert::AreEqual(false, test1 == test2);
		}

		//测试!=功能
		TEST_METHOD(Function_NotEqual)
		{
			long long test_int1 = 3556874280960232200;
			long long test_int2 = 9223372036850233200;
			long long test_int3 = 3556874280960232200;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);

			Assert::AreEqual(false, test1 != test3);
			Assert::AreEqual(true, test1 != test2);
		}

		//测试+功能
		TEST_METHOD(Function_Plus)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand()*rand();
				long long test_int2 = rand()*rand();
				long long test_int3 = test_int1 + test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 + test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand()*rand();
				long long test_int2 = -rand()*rand();
				long long test_int3 = test_int1 + test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 + test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand()*rand();
				long long test_int2 = -rand()*rand();
				long long test_int3 = test_int1 + test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 + test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}
		}

		//测试-功能
		TEST_METHOD(Function_Minus)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand()*rand();
				long long test_int2 = rand()*rand();
				long long test_int3 = test_int1 - test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 - test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand()*rand();
				long long test_int2 = -rand()*rand();
				long long test_int3 = test_int1 - test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 - test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand()*rand();
				long long test_int2 = -rand()*rand();
				long long test_int3 = test_int1 - test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 - test2;
				Assert::AreEqual(test3.toString16(), test4.toString16());
			}
		}

		//测试*功能
		TEST_METHOD(Function_Times)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int2 = rand();
				long long test_int3 = test_int1 * test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 * test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand();
				long long test_int2 = rand();
				long long test_int3 = test_int1 * test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 * test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand();
				long long test_int2 = -rand();
				long long test_int3 = test_int1 * test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 * test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			string test_s1 = "-d4fdc287b";//57174403195
			string test_s2 = "2135aa25d";//8914641501
			string test_s3 = "-1ba15c2cbcb0d68aaf";//509689307517053995695

			BigInteger tests1(test_s1);
			BigInteger tests2(test_s2);
			BigInteger tests3 = tests1 * tests2;

			Assert::AreEqual(test_s3, tests3.toString16());
		}

		//测试/功能
		TEST_METHOD(Function_Divide)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int2 = rand();
				long long test_int3 = test_int1 / test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 / test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int2 = -rand();
				long long test_int3 = test_int1 / test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 / test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand();
				long long test_int2 = -rand();
				long long test_int3 = test_int1 / test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 / test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			string test_s1 = "d4fdc287b";//57174403195
			string test_s2 = "1ba15c2cbcb0d68aaf";//509689307517053995695
			string test_s3 = "2135aa25d";//8914641501

			BigInteger tests1(test_s1);
			BigInteger tests2(test_s2);
			BigInteger tests3 = tests2 / tests1;

			Assert::AreEqual(test_s3, tests3.toString16());
		}

		//测试%功能
		TEST_METHOD(Function_Module)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int2 = rand();
				long long test_int3 = test_int1 % test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 % test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int2 = -rand();
				long long test_int3 = test_int1 % test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 % test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand();
				long long test_int2 = -rand();
				long long test_int3 = test_int1 % test_int2;

				BigInteger test1(test_int1);
				BigInteger test2(test_int2);
				BigInteger test3(test_int3);
				BigInteger test4 = test1 % test2;

				Assert::AreEqual(test3.toString16(), test4.toString16());
			}

			string test_s1 = "d4fdc287b";//57174403195
			string test_s2 = "1ba15c2cbcb0d68aaf";//509689307517053995695
			string test_s3 = "0";//8914641501

			BigInteger tests1(test_s1);
			BigInteger tests2(test_s2);
			BigInteger tests3 = tests2 % tests1;

			Assert::AreEqual(test_s3, tests3.toString16());
		}

		//测试*性能
		//TEST_METHOD(Function_Times_Effciency)
		//{
		//	string test_s1 = "asd2e1asde14asasd2e1asde14as6de1asde16de1asd2e1asde14as6de1asde1asd2e1asde14as6de1asde1asde1";
		//	string test_s2 = "asd2e1asde14asasd2e1asde14as6de1asde16de1asd2e1asde14as6de1asde1asd2e1asde14as6de1asde1asde1";
		//	BigInteger tests1(test_s1);
		//	BigInteger tests2(test_s2);
		//	for (int i = 0; i < 1000000; i++)
		//	{
		//		tests1 * tests2;
		//	}
		//}

		//测试inverse功能
		TEST_METHOD(Function_Inverse)
		{
			long long test_int1 = 28;
			long long test_int2 = 75;
			long long test_int3 = 67;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			BigInteger test3(test_int3);
			BigInteger test4 = inverseMod(test1,test2);
			Assert::AreEqual(test3.toString16(), test4.toString16());
			test4 = inverseMod(test4, test2);
			Assert::AreEqual(test1.toString16(), test4.toString16());

			long long test_int5 = 12111345435247;
			long long test_int6 = 12434633333524;

			BigInteger test5(test_int5);
			BigInteger test6(test_int6);
			BigInteger test8 = inverseMod(test5, test6);
			BigInteger testt = test8;
			test8 = inverseMod(test8, test6);
			Assert::AreEqual(test5.toString16(), test8.toString16());
			BigInteger testk = (testt*test5) % test6;
			Assert::AreEqual(BigInteger(1).toString16(),testk.toString16());
		}

		//测试Increment功能
		TEST_METHOD(Function_Increment)
		{
			srand((unsigned)time(NULL));

			for (int i = 0; i < 50; i++) {
				long long test_int1 = rand();
				long long test_int3 = test_int1+1;

				BigInteger test1(test_int1);
				BigInteger test3(test_int3);
				test1.increment();
				Assert::AreEqual(test3.toString16(), test1.toString16());
			}

			for (int i = 0; i < 50; i++) {
				long long test_int1 = -rand();
				long long test_int3 = test_int1+1;

				BigInteger test1(test_int1);
				BigInteger test3(test_int3);
				test1.increment();
				Assert::AreEqual(test3.toString16(), test1.toString16());
			}

			long long test_int1 = -1;
			long long test_int2 = test_int1 + 1;

			BigInteger test1(test_int1);
			BigInteger test2(test_int2);
			test1.increment();
			Assert::AreEqual(test2.toString16(), test1.toString16());

			long long test_int3 = (1 << 24) - 1;
			long long test_int4 = test_int3 + 1;

			BigInteger test3(test_int3);
			BigInteger test4(test_int4);
			test3.increment();
			Assert::AreEqual(test4.toString16(), test3.toString16());
		}

		//测试ModularExp功能
		TEST_METHOD(Function_ModularExp)
		{
			BigInteger ta("34534434616548138465183158351832");
			BigInteger tb("34534434616548138465183158351831");
			BigInteger tn("45634765656555");
			BigInteger tr("1");
			Assert::AreEqual(tr.toString16(), (modularExp(ta,tn,tb)).toString16());
		}

		//测试isPrime功能
		TEST_METHOD(Function_isPrime)
		{
			BigInteger test(920419823);
			Assert::AreEqual(true, isPrime(test));
			BigInteger test2(1721 * 3769);
			Assert::AreEqual(false, isPrime(test2));
			BigInteger test3 = 92041982344333;
			BigInteger test4 = test3 * test3;
			Assert::AreEqual(false, isPrime(test4));
		}

		//测试扩展欧几里得算法
		TEST_METHOD(Functoin_Euclid)
		{
			BigInteger a(99),b(78);
			BigInteger x, y, d;
			d = extendEclid(a,b,x,y);
			Assert::AreEqual(-11, -x.getInt());
			Assert::AreEqual(14, y.getInt());
			Assert::AreEqual(3, d.getInt());
		}

		//测试整个操作所用时间
		TEST_METHOD(Total_Time_1024)
		{
			BigInteger a, b, p, q, n, phi_n;
			int bits,i=0;
			bits = 1024;
			p = producePrime(bits / 2);
			q = producePrime(bits / 2);
			n = q*p;
			phi_n = (q - 1)*(p - 1);
			b = produceBigInteger(bits/2);
			while (gcd(b, phi_n) != 1)
			{
				b = b+1;
			}
			a = inverseMod(b, phi_n);
		}

		//测试整个操作所用时间
		TEST_METHOD(Total_Time_768)
		{
			BigInteger a, b, p, q, n, phi_n;
			int bits, i = 0;
			bits = 768;
			p = producePrime(bits / 2);
			q = producePrime(bits / 2);
			n = q*p;
			phi_n = (q - 1)*(p - 1);
			b = produceBigInteger(bits / 2);
			while (gcd(b, phi_n) != 1)
			{
				b = b + 1;
			}
			a = inverseMod(b, phi_n);
		}

		//测试整个操作所用时间
		TEST_METHOD(Total_Time_2048)
		{
			BigInteger a, b, p, q, n, phi_n;
			int bits, i = 0;
			bits = 2048;
			p = producePrime(bits / 2);
			q = producePrime(bits / 2);
			n = q*p;
			phi_n = (q - 1)*(p - 1);
			b = produceBigInteger(bits / 2);
			while (gcd(b, phi_n) != 1)
			{
				b = b + 1;
			}
			a = inverseMod(b, phi_n);
		}

		//测试ProducePrime功能
		TEST_METHOD(Function_ProducePrime)
		{
			BigInteger k = producePrime(512);
		}

		//测试生成密码的正确性
		TEST_METHOD(Rightness)
		{
			int bits = 768;
			BigInteger p = producePrime(bits / 2);
			BigInteger q = producePrime(bits / 2);
			BigInteger n = q*p;
			BigInteger phi_n = (q - 1)*(p - 1);
			BigInteger b = produceBigInteger(bits / 2);
			while (gcd(b, phi_n) != 1)
				b = b + 1;
			BigInteger a = inverseMod(b, phi_n);
			BigInteger midtest = (a*b) % phi_n;
			Assert::AreEqual(BigInteger(1).toString16(),midtest.toString16());

			vector<BigInteger> origin;
			vector<BigInteger> after;
			string ostring = "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in liberty, and dedicated to the proposition.";
			string enstring;
			string rstring;

			transferToBigIntegers(origin, ostring, bits);
			for (int i = 0; i < origin.size(); i++)
			{
				after.push_back(modularExp(origin[i], b, n));
			}
			transferToString16(after, enstring, bits);

			transferToBigIntegers16(origin, enstring, bits);
			after.clear();
			for (int i = 0; i < origin.size(); i++)
			{
				after.push_back(modularExp(origin[i], a, n));
			}
			transferToString(after, rstring, bits);
			
			Assert::AreEqual(ostring, rstring);
		}

		//测试<<功能
		TEST_METHOD(Function_Left_Move)
		{
			unsigned long long temp_long = 5242234;
			BigInteger test(temp_long);
			temp_long = temp_long << 34;
			test = test << 34;
			BigInteger test_result(temp_long);

			Assert::AreEqual(test_result.toString16(), test.toString16());
		}

		//测试>>功能
		TEST_METHOD(Function_Right_Move)
		{
			unsigned long long temp_long = 102234224;
			BigInteger test(temp_long);
			temp_long = temp_long >> 11;
			test = test >> 11;
			BigInteger test_result(temp_long);

			Assert::AreEqual(test_result.toString16(), test.toString16());
		}
	};
}