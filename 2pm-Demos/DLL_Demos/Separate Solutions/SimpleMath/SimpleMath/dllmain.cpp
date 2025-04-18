/* DLL Demo for IGME 209 - Austin Willoughby, arwigm@rit.edu
*  Based on: https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170
* 
*  In this demo we will be creating a DLL or Dynamic-Link Library. DLLs are code
*  libraries that are precompiled and can be used by any number of programs running
*  on a computer. One advantage of a DLL over a something like a standard library, or
*  writing code directly into your project is that DLLs can be replaced without
*  recompiling your executable. This is very useful for things like patching, or
*  hotswapping content in and out of an executable.
* 
*  Below we see the dllmain file. This is generated for us when we create a DLL
*  project. We can use the switch statement to setup and cleanup things being
*  used in the DLL. However, for this project we don't need to do anything here.
* 
*  Look at SimpleMath.h next.
*/
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

