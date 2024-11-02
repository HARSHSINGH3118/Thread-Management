#define _WIN32_WINNT 0x0600
#ifndef THREAD_H
#define THREAD_H

#include <windows.h>

// Structure to hold thread information
typedef struct my_thread
{
    HANDLE handle;
    DWORD id;
    int is_active;
    void *(*start_routine)(void *);
    void *arg;
} my_thread;

// Function declarations
int my_thread_create(my_thread *thread, void *(*start_routine)(void *), void *arg);
int my_thread_join(my_thread *thread);
void my_thread_exit(void);

#endif
