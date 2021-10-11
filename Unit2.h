// ---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class Thread1 : public TThread {
private:
protected:
	void __fastcall Execute();

public:
	__fastcall Thread1(bool CreateSuspended);
};
// ---------------------------------------------------------------------------
#endif
