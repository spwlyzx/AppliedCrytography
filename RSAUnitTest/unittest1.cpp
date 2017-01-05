#include "stdafx.h"
#include "CppUnitTest.h"
#include "BigInteger.h"
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RSAUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//toString16()��normalize()�����Ѿ�����������������������
		//����string���캯��
		TEST_METHOD(Constructors_String)
		{
			//�ַ�������
			string test_string1("ab98287e98d7897f57d5ac768e875110340");
			BigInteger test1(test_string1);
			Assert::AreEqual(test_string1, test1.toString16());
		}

		//����unsigned int���캯��
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

		//����int���캯��
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

		//����long long���캯��
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

		//����unsigned long long���캯��
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

		//����-��ȡ�෴��������
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

		//����>����
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

		//����>=����
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

		//����<����
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

		//����<=����
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

		//����==����
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

		//����!=����
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

		//����+����
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
		}

		//����-����
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
		}

		//����*����
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

			string test_s1 = "-d4fdc287b";//57174403195
			string test_s2 = "2135aa25d";//8914641501
			string test_s3 = "-1ba15c2cbcb0d68aaf";//509689307517053995695

			BigInteger tests1(test_s1);
			BigInteger tests2(test_s2);
			BigInteger tests3 = tests1 * tests2;

			Assert::AreEqual(test_s3, tests3.toString16());
		}

		//����/����
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

			string test_s1 = "d4fdc287b";//57174403195
			string test_s2 = "1ba15c2cbcb0d68aaf";//509689307517053995695
			string test_s3 = "2135aa25d";//8914641501

			BigInteger tests1(test_s1);
			BigInteger tests2(test_s2);
			BigInteger tests3 = tests2 / tests1;

			Assert::AreEqual(test_s3, tests3.toString16());
		}

		//����*����
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

		//����<<����
		TEST_METHOD(Function_Left_Move)
		{
			unsigned long long temp_long = 5242234;
			BigInteger test(temp_long);
			temp_long = temp_long << 34;
			test = test << 34;
			BigInteger test_result(temp_long);

			Assert::AreEqual(test_result.toString16(), test.toString16());
		}

		//����>>����
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