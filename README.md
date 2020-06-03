# MinidumpDiagnostics

This is essantially a resurrection of UE4 MinidumpDiagnostics that was removed in 4.24

https://github.com/EpicGames/UnrealEngine/commit/38e839a1b161cfb8c151643a80f322ce3796e555

It can take an build plus a minidump from a crash and extract a stacktrace. 

We only need it for windows so I cant guarantee that it works in any other environment.

## Building

It requires the the unreal engine source code (it does NOT work with the distributed binaries, sorry)

Unreal engine disables the possibility to point to the symbol (\*.pdb) with the help of environment variables
if you build with shipping, so you have to build it in some other mode (debug works)

## Usage

To run it you need to set the \_NT\_SYMBOL_PATH to where the pdb is located (next to the exe in unreal project)

PowerShell example:

	$Env:_NT_SYMBOL_PATH = '<RootProject>\<GameName>\Binaries\Win64'; .\MinidumpDiagnostics-Win64-Debug.exe <RootProject>\<GameName>\Saved\Crashes\UE4CC-Windows-8B54BF104295FCC82D217D932E80FE24_0000\UE4Minidump.dmp

