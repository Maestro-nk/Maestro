#include <iostream>

int main()
{
	{
		const char CONST1 = '+';
		char chVar1;
		chVar1 = 'f';
		char chVar2 = '4';
		const char CONST2 = 0x30;
		char chVar3;
		chVar3 = 0x7;
		char chVar4 = 0x79;

	}
	{
		int nA;

		float fltB;

		unsigned short wC;

		nA = 31765;

		fltB = -7.293e3;

		wC = 26543;


		double dblD;

		int nE;

		char chF;



		dblD = nA;

		nE = fltB;

		chF = wC;



		dblD = (double)nA;

		nE = (int)fltB;

		chF = (char)wC;

		double* pdblD;

		void* pV;

		pV = &nA;

		pdblD = (double*)pV;

		dblD = *pdblD;

		int* pnE;

		pV = &fltB;

		pnE = (int*)pV;

		nE = *pnE;

		char* pchF;

		pV = &wC;

		pchF = (char*)pV;

		chF = *pchF;
	}
}