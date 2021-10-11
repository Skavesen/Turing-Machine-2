// ---------------------------------------------------------------------------

#ifndef Thread2H
#define Thread2H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class MultiTape : public TThread {
private:
	int MaxWordLength;
	int length;
	int MaxCountOnThisLength;

	void __fastcall NewPoint();

protected:
	void __fastcall Execute();

public:
	__fastcall MultiTape(bool CreateSuspended);
};
// ---------------------------------------------------------------------------
#endif
