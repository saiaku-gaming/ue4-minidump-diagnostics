#pragma once

#include "CoreMinimal.h"

// Extract a debugging report from a minidump
int32 RunMinidumpDiagnostics(int32 ArgC, TCHAR* Argv[]);

#ifndef _DEBUG
	#define _DEBUG
#endif
