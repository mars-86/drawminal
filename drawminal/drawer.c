#include <stdlib.h>
#include "drawer.h"

static wchar_t *buffer;

void drawer_init(void)
{

}

drawer_t *drawer_create(DRAWER_TYPE dtype)
{

}

void drawer_destroy(drawer_t *drawer)
{

}

void drawer_cleanup(void)
{
    free(buffer);
}
