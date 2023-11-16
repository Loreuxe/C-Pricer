#include "pch.h"
#include "../Cpp_projet_partie_3/PutOption.h"
#include "CppUnitTest.h"
// Premiere partie des tests unitaires. Attention aux inclusions de fichiers toutes n'ont pas marchés pour moi. 
// Je n'ai donc pas pu vérifier Vanilla Option, reste good normalement
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ppprojetpatie3Tests
{
	TEST_CLASS(OptionTests)
	{
	public:
		TEST_METHOD(TestGetExpiry)
		{

			double expiry = 1.5;
			Option option(expiry);
			double result = option.GetExpiry();

			Assert::AreEqual(1.5, result);
			Assert::AreEqual(1.0, result);
		}

		TEST_METHOD(TestIsAmericanOption)
		{
			Option option(2.0);
			bool result = option.isAmericanOption();

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestIsAsianOption)
		{
			Option option(2.0);
			bool result = option.isAsianOption();

			Assert::IsFalse(result);
		}
	};
	
	
	TEST_CLASS(PutOptionTests)
	{
	public:
		
		TEST_METHOD(GetOptionTypeTest)
		{
			double expiry = 1.5;
			double strike = 100.0;
			PutOption putOption(expiry, strike);

			OptionType optionType = putOption.GetOptionType();

			Assert::AreEqual(OptionType::Put, optionType);
		}
		TEST_METHOD(TestPayoff)
		{
			double expiry = 1.5;
			double strike = 100.0;
			PutOption putOption(expiry, strike);

			
			double payoff1 = putOption.payoff(110.0); 
			double payoff2 = putOption.payoff(90.0);  

			
			Assert::AreEqual(10.0, payoff1);
			Assert::AreEqual(8.0, payoff1);
			Assert::AreEqual(0.0, payoff2);
			Assert::AreEqual(10.0, payoff2);
		}
	};


	TEST_CLASS(VanillaOptionTests)
	{
	public:

		TEST_METHOD(TestgetStrike)
		{
			double expiry = 1.5;
			double strike = 100.0;
			VanillaOption vanillaOption(expiry, strike);

			double optionStrike = vanillaOption.GetStrike();

			Assert::AreEqual(100.0, optionStrike);
			Assert::AreEqual(101.0, optionStrike);
		}
	
	};

	TEST_CLASS(CallOptionTests)
	{
	public:

		TEST_METHOD(GetOptionTypeTest)
		{
			double expiry = 1.5;
			double strike = 100.0;
			CallOption callOption(expiry, strike);

			OptionType optionType = callOption.GetOptionType();

			Assert::AreEqual(OptionType::call, optionType);
		}
		TEST_METHOD(TestPayoff)
		{
			double expiry = 1.5;
			double strike = 100.0;
			CallOption callOption(expiry, strike);


			double payoff1 = callOption.payoff(110.0);
			double payoff2 = callOption.payoff(90.0);


			Assert::AreEqual(10.0, payoff1);
			Assert::AreEqual(8.0, payoff1);
			Assert::AreEqual(0.0, payoff2);
			Assert::AreEqual(10.0, payoff2);
		}
	};

	TEST_CLASS(BlackScholesPricerTests)
	{
	public:
		TEST_METHOD(TestOperator)
		{
			VanillaOption vanillaCall(1.5, 100.0);
			BlackScholesPricer pricerCall(&vanillaCall, 95.0, 0.05, 0.2);

			VanillaOption vanillaPut(1.5, 100.0);
			vanillaPut.SetOptionType(OptionType::Put);
			BlackScholesPricer pricerPut(&vanillaPut, 95.0, 0.05, 0.2);

			double callPrice = pricerCall();
			double putPrice = pricerPut();

			
			Assert::AreEqual(8.911, callPrice, 0.001); // Adjust the tolerance as needed
			Assert::AreEqual(7.862, putPrice, 0.001); // Adjust the tolerance as needed
		}

		TEST_METHOD(TestDelta)
		{
			// Arrange
			VanillaOption vanillaCall(1.5, 100.0);
			BlackScholesPricer pricerCall(&vanillaCall, 95.0, 0.05, 0.2);

			VanillaOption vanillaPut(1.5, 100.0);
			vanillaPut.SetOptionType(OptionType::Put);
			BlackScholesPricer pricerPut(&vanillaPut, 95.0, 0.05, 0.2);

			// Act
			double callDelta = pricerCall.delta();
			double putDelta = pricerPut.delta();

			// Assert
			Assert::AreEqual(0.553, callDelta, 0.001); // Adjust the tolerance as needed
			Assert::AreEqual(-0.447, putDelta, 0.001); // Adjust the tolerance as needed
		}
	};

}
