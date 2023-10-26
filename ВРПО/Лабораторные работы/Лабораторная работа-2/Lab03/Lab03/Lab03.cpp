#include <iostream>
using namespace std;
//BerezkaVadim2006
// 0042 0065 0072 0065 007A 006B 0061 0056 0061 0064 0069 006D 0032 0030 0030 0036
// 42 65 72 65 7A 6B 61 56 61 64 69 6D 32 30 30 36
// 42 65 72 65 7A 6B 61 56 61 64 69 6D 32 30 30 36
//БерёзкаВадимСергеевич2006
// 0411 0435 0440 0451 0437 043A 0430 0412 0430 0434 0438 043C 0421 0435 0440 0433 0435 0435 0432 0438 0447 0032 0030 0030 0036
// c1 e5 f0 b8 e7 ea e0 c2 e0 e4 e8 ec d1 e5 f0 e3 e5 e5 e2 e8 f7 32 30 30 36
// c1 e5 f0 b8 e7 ea e0 c2 e0 e4 e8 ec d1 e5 f0 e3 e5 e5 e2 e8 f7 32 30 30 36
//Берёзка2006Vadim
// 0411 0435 0440 0451 0437 043A 0430 0032 0030 0030 0036 0056 0061 0064 0069 006D
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

	cout << hello << lfie << endl;
	return 0;
}