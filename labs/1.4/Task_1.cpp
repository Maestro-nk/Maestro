#include <iostream>

int main()
{
	unsigned short wVar1;
	int iVar2;
	float fVar3;
	double dVar4;

	unsigned short* pwVar1;
	int* piVar2;
	float* pfVar3;
	double* pdVar4;

	void* pV;

	pwVar1 = &wVar1;
	piVar2 = &iVar2;
	pfVar3 = &fVar3;
	pdVar4 = &dVar4;

	*pwVar1 = 9040;
	*piVar2 = -267;
	*pfVar3 = 0.007642;
	*pdVar4 = -1.11e99;

	int sizeOfwVar1 = sizeof(wVar1);
	int sizeOfiVar2 = sizeof(iVar2);
	int sizeOfdVar4 = sizeof(dVar4);
	int sizeOffVar4 = sizeof(fVar3);

	int sizeOfpiVar2 = sizeof(piVar2);
	int sizeOfDerefpiVar2 = sizeof(*piVar2);
	int sizeOfpV = sizeof(pV);

	pV = &pwVar1;

}