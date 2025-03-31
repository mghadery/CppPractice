// Part01Core.cpp : Defines the entry point for the application.
//
//
//#include <locale>
//#include <io.h>       // For _setmode()
//#include <fcntl.h>    // For _O_U16TEXT

#include "chap1_up/chap1_up.h"
#include "chap2_types/chap2_types.h"


enum class Chapters {
	chap1_up,
	chap2_types
};
const Chapters chapter = Chapters::chap2_types;

int main()
{
	//_setmode(_fileno(stdout), _O_U16TEXT); // Enable UTF-16 output in Windows console

	printf("THIS IS MAIN\n");
	switch (chapter)
	{
	case Chapters::chap1_up:
		chap1_up::run();
		break;
	case Chapters::chap2_types:
		chap2_types::run();
		break;
}
	
	return 0;
}
