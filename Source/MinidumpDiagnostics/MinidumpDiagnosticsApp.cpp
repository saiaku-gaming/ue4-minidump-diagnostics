#include "MinidumpDiagnosticsApp.h"

#include "Modules/ModuleManager.h"
#include "CrashDebugHelperModule.h"
#include "CrashDebugHelper.h"
#include "Misc/Paths.h"

int32 RunMinidumpDiagnostics(int32 ArgC, TCHAR* Argv[])
{
	// Make sure we have at least a single parameter
	if( ArgC < 2 )
	{
		UE_LOG( LogInit, Error, TEXT( "MinidumpDiagnostics - not enough parameters." ) );
		UE_LOG( LogInit, Error, TEXT( " ... usage: MinidumpDiagnostics.exe <Crash.dmp> [-SyncMicrosoftSymbols]" ) );
		UE_LOG( LogInit, Error, TEXT( " ..." ) );
		UE_LOG( LogInit, Error, TEXT( " ... -SyncMicrosoftSymbols: Sync symbols from the Microsoft Symbol Server" ) );
		return 1;
	}

	// Load in the stack walking module
	FCrashDebugHelperModule& CrashHelperModule = FModuleManager::LoadModuleChecked<FCrashDebugHelperModule>( FName( "CrashDebugHelper" ) );
	ICrashDebugHelper* CrashDebugHelper = CrashHelperModule.Get();
	if( CrashDebugHelper == NULL )
	{
		UE_LOG( LogInit, Error, TEXT( "Failed to load CrashDebugHelper module; unsupported platform?" ) );
		return 1;
	}

	// Create a report for the minidump passed in on the command line
	FString MinidumpName = Argv[1];
	const bool bValidCallstack = CrashDebugHelper->CreateMinidumpDiagnosticReport( MinidumpName );
	FString DiagnosticsPath = FPaths::GetPath( MinidumpName );
	if( bValidCallstack )
	{	
		DiagnosticsPath /= FString( TEXT( "Diagnostics.txt" ) );
	}
	else
	{
		DiagnosticsPath /= FString( TEXT( "DiagnosticsFailed.txt" ) );
	}

	// Write a report next to the original minidump	
	CrashDebugHelper->CrashInfo.GenerateReport( DiagnosticsPath );

	// Cleanup
	CrashHelperModule.ShutdownModule();

	UE_LOG( LogInit, Warning, TEXT( "MinidumpDiagnostics completed successfully!" ) );
	return 0;
}