/* DLL Demo for IGME 209 - Austin Willoughby, arwigm@rit.edu
*
*  This project imports a DLL created by the other project included with this
*  demo code (SimpleMath). To get the project working with the DLL, we had to
*  setup the following in the project settings.
* 
*  Project Settings > C/C++ > General > Additional Include Directories
*		ADD: ..\..\SimpleMath\SimpleMath
*		- This is a relative path to our other project, SimpleMath, so that
*		  we can use the SimpleMath.h file from it.
* 
*  Project Settings > Linker > General > Additional Library Directories
*		ADD: ..\..\SimpleMath\$(IntDir)
*		- This tells the MathUser project how to find the SimpleMath library
*		  file. $(IntDir) is a macro for the "Intermediate Directory", where
*	      the .lib file will be built to.
* 
*  Project Settings > Linker > Input > Additional Dependencies
*		ADD: SimpleMath.lib
*		- This tells the project how to link the DLL, by using the SimpleMath.lib.
* 
*  Project Settings > Build Events > Post Build Events > Command Line
*		ADD: xcopy /y /d "..\..\SimpleMath\$(IntDir)SimpleMath.dll" "$(OutDir)"
*		- This tells Visual Studio to copy the SimpleMath.dll from the SimpleMath
*		  project into the output directory of the MathUser project (where the
*		  .exe will be built to).
* 
*  From there, we can use SimpleMath.h to use the functionality exported from
*  the DLL. Read up on how the DLL works in the other demo. We can also add
*  Vector2.h to get access to the Vector2 class in SimpleMath.
*/

#include <iostream>
#include "SimpleMath.h"
#include "Vector2.h"

using namespace std;

int main()
{
	cout << addition(1, 2) << endl;
	cout << subtraction(1, 2) << endl;
	cout << multiplication(1, 2) << endl;
	cout << division(1, 2) << endl;

	Vector2 myVector = Vector2();
	myVector.x = 10;
	myVector.y = 20;
	myVector.Print();
}