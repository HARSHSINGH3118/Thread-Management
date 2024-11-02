#include "sync_primitives.h"

void my_mutex_init(my_mutex *mutex)
{
    InitializeCriticalSection(mutex);
}

void my_mutex_lock(my_mutex *mutex)
{
    EnterCriticalSection(mutex);
}

void my_mutex_unlock(my_mutex *mutex)
{
    LeaveCriticalSection(mutex);
}
