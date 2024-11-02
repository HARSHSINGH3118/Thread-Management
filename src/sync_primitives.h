#ifndef SYNC_PRIMITIVES_H
#define SYNC_PRIMITIVES_H

#include <windows.h>

typedef CRITICAL_SECTION my_mutex;

// Function declarations
void my_mutex_init(my_mutex *mutex);
void my_mutex_lock(my_mutex *mutex);
void my_mutex_unlock(my_mutex *mutex);

#endif
