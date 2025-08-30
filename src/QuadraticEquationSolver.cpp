#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include "../src_h/EquationSolutionFunctions.h"
#include "../src_h/SolverTests.h"
#include "../src_h/UserInterface.h"


int main(int argc, char*argv[])
{
    if(argc > 0)
    {
        if(strcmp(argv[1], "--test") == 0)
            SolverT();
        else if(strcmp(argv[1], "--user") == 0)
            UserI();
        else if(strcmp(argv[1], "--help") == 0)
            printf("Usage: quadratka.exe [options] file...\n Options:\n --user                   Run user mode\n --test                   Run test mode\n --help                   Display this information\n");
        else if(strcmp(argv[1], "--prank") == 0)
        {
            ShellExecuteA(GetDesktopWindow(),"open","musor\\RickRoll.mp4",NULL,NULL,SW_SHOW);
            Sleep(1000);
        }
    }
    else
    {
        printf(RED "quadratka.exe: error: unrecognized command line option '%s'\n use QES.exe --help if you don't know any other flags\n compilation terminated.\n" BLACK, argv[1]);
    }
}
