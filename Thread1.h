// ---------------------------------------------------------------------------

#ifndef Thread1H
#define Thread1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class CalculateThread : public TThread {
private:
	int MaxWordLength;
	int length;
	int MaxCountOnThisLength;

	void __fastcall NewPoint();

protected:
	void __fastcall Execute();

public:
	__fastcall CalculateThread(bool CreateSuspended);
};
// ---------------------------------------------------------------------------
#endif
