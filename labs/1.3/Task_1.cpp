int main()
{
	int nA = 5;
	int nInvertA = ~5;

	int mA = 76, mB = 109;
	int AndAB = mA & mB;

	int aB = 121, aC = 52;
	int nOrBC = aB | aC;

	int abB = 21, abc = 65;
	int nXorBC = abB ^ abc;

	int aabB = 894,
		aabbB = 14;
	int nLeftShift = aabB << 2;
	int nRightShift = aabbB >> 2;

	return 0;
}