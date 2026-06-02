#include "common/common.h"

#include <stdarg.h>
#include <stdio.h>

#if defined(TARGET_WINDOWS)
#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "dbghelp.lib")
#endif

void CDECL debug(char* str, ...)
{
    char debugBuffer[256];

    va_list args;
    va_start(args, str);

    if (vsprintf(debugBuffer, str, args) < 0)
    {
        debugBuffer[0] = 0;
    }

    va_end(args);

#if defined(TARGET_WINDOWS)
    puts(debugBuffer);

    FILE* fp = fopen("LOG.TXT", "ab");
    fputs(debugBuffer, fp);
    fputc('\n', fp);
    fclose(fp);
#else
    //FILE* fp = fopen("LOG.TXT", "ab");
    //fputs(debugBuffer, fp);
    //fputc('\n', fp);
    //fclose(fp);
#endif
}

#if defined(TARGET_WINDOWS)
static LONG WINAPI UnhandledExceptionHandler(EXCEPTION_POINTERS* exceptionPointers);
#endif

void DEBUG_Initialize(void)
{
    FILE* fp = fopen("LOG.TXT", "wb");
    fclose(fp);

#if defined(TARGET_WINDOWS)
    SetUnhandledExceptionFilter(UnhandledExceptionHandler);
#endif
}

#if defined(TARGET_WINDOWS)

static void WriteCrashDump(EXCEPTION_POINTERS* exceptionPointers)
{
    SYSTEMTIME time;
    GetLocalTime(&time);

    wchar_t path[MAX_PATH];

    StringCchPrintfW(path, MAX_PATH, L"crash_%04u%02u%02u_%02u%02u%02u.dmp", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);

    HANDLE file = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (file == INVALID_HANDLE_VALUE)
        return;

    MINIDUMP_EXCEPTION_INFORMATION exceptionInfo = { 0, };
    exceptionInfo.ThreadId = GetCurrentThreadId();
    exceptionInfo.ExceptionPointers = exceptionPointers;
    exceptionInfo.ClientPointers = FALSE;

    MINIDUMP_TYPE dumpType = (MINIDUMP_TYPE)(MiniDumpWithIndirectlyReferencedMemory | MiniDumpScanMemory | MiniDumpWithThreadInfo | MiniDumpWithUnloadedModules);

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file, dumpType, exceptionPointers != NULL ? &exceptionInfo : NULL, NULL, NULL);

    CloseHandle(file);
}

static LONG WINAPI UnhandledExceptionHandler(EXCEPTION_POINTERS* exceptionPointers)
{
    WriteCrashDump(exceptionPointers);

    return EXCEPTION_EXECUTE_HANDLER;
}

#endif
