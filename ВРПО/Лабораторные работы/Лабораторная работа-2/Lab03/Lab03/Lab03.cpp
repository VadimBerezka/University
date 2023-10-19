#include <iostream>
//BerezkaVadim2006
// 42 65 72 65 7A 6B 61 56 61 64 69 6D 32 30 30 36
// 42 65 72 65 7A 6B 61 56 61 64 69 6D 32 30 30 36
// 42 65 72 65 7A 6B 61 56 61 64 69 6D 32 30 30 36
//БерёзкаВадимСергеевич2006
// 411 435 44 451 437 43A 43 412 43 434 438 43C 421 435 44 433 435 435 432 438 447 32 30 30 36
// c1 e5 f0 b8 e7 ea e0 c2 e0 e4 e8 ec d1 e5 f0 e3 e5 e5 e2 e8 f7 32 30 30 36
// c1 e5 f0 b8 e7 ea e0 c2 e0 e4 e8 ec d1 e5 f0 e3 e5 e5 e2 e8 f7 32 30 30 36
//Берёзка2006Vadim
// 411 435 44 451 437 43A 43 32 30 30 36 56 61 64 69 6D
// c1 e5 f0 b8 e7 ea e0 32 30 30 36 56 61 64 69 6d
// c1 e5 f0 b8 e7 ea e0 32 30 30 36 56 61 64 69 6d

int main(){
	int number = 0x12345678;
	char hello[] = "Hello, ";
	char lfie[] = "BerezkaVadim2006";
	char rfie[] = "БерёзкаВадимСергеевич2006";
	char lr[] = "Берёзка2006Vadim";

	wchar_t Lfie[] = L"BerezkaVadim2006";
	wchar_t Rfie[] = L"БерёзкаВадимСергеевич2006";
	wchar_t LR[] = L"Берёзка2006Vadim";

	std::cout << hello << lfie << std::endl;
	return 0;
}
