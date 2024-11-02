#include "thread.h"
#include <stdio.h>

DWORD WINAPI start_thread(LPVOID arg)
{
    my_thread *thread = (my_thread *)arg;
    thread->start_routine(thread->arg);
    return 0;
}

int my_thread_create(my_thread *thread, void *(*start_routine)(void *), void *arg)
{
    thread->start_routine = start_routine;
    thread->arg = arg;
    thread->handle = CreateThread(NULL, 0, start_thread, thread, 0, &thread->id);
    if (thread->handle == NULL)
    {
        perror("Error creating thread");
        return -1;
    }
    thread->is_active = 1;
    return 0;
}

int my_thread_join(my_thread *thread)
{
    if (WaitForSingleObject(thread->handle, INFINITE) != WAIT_OBJECT_0)
    {
        perror("Error joining thread");
        return -1;
    }
    CloseHandle(thread->handle);
    thread->is_active = 0;
    return 0;
}

void my_thread_exit(void)
{
    ExitThread(0);
}
