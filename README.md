# voicemail-system

## Setup
1. Download [Boost](http://www.boost.org/users/download/)
2. Run bootstrap.bat
3. Run b2.exe
4. Rune bjam.exe
5. Inside Visual Studio: Project > Properties > C/C++ > Include additional directories - Edit > Browse to the root directory you unzipped Boost to and click Apply
6. Under C/C++ > Precompiled Headers > Precompiled Header - Choose 'Not Using Precompiled Headers' and click Apply
7. Select Linker > Additional Libary Dependencies - Edit > Browse to stage/lib that is inside the Boost directory and click Apply
8. Compile and run
