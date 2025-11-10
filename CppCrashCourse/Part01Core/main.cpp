// Part01Core.cpp : Defines the entry point for the application.
//
//
//#include <locale>
//#include <io.h>       // For _setmode()
//#include <fcntl.h>    // For _O_U16TEXT

#include "chap1_up/chap1_up.h"
#include "chap2_types/chap2_types.h"
#include "chap3_references//chap3_references.h"
#include "chap4_lifecycle/chap4_lifecycle.h"
#include "chap5_rt_pm/chap5_rt_pm.h"
#include "chap6_ct_pm/chap6_ct_pm.h"
 
enum class Chapters {
	chap1_up,
	chap2_types,
	chap3_references,
	chap4_lifecycle,
	chap5_rt_pm,
	chap6_ct_pm
};
const Chapters chapter = Chapters::chap6_ct_pm;

int main()
{
	//_setmode(_fileno(stdout), _O_U16TEXT); // Enable UTF-16 output in Windows console

	printf("THIS IS MAIN\n");
	switch (chapter)
	{
	case Chapters::chap1_up: {
		chap1_up::run();
	}break;
	case Chapters::chap2_types: {
		chap2_types::run();
	}break;
	case Chapters::chap3_references: {
		chap3_references::run();
	}break;
	case Chapters::chap4_lifecycle: {
		chap4_lifecycle::run();
	}break;
	case Chapters::chap5_rt_pm: {
		chap5_rt_pm::run();
	}break;
	case Chapters::chap6_ct_pm: {
		chap6_ct_pm::run();
	}break;					
	}
	
	return 0;
}
