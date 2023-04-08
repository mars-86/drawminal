#ifndef __DRAWMINAL_DRAWER_INCLUDED_H__
#define __DRAWMINAL_DRAWER_INCLUDED_H__

typedef enum {
    BUFFERED
} DRAWER_TYPE;

struct Drawer {
    DRAWER_TYPE type;
};

typedef struct Drawer drawer_t;

void drawer_init(void);
drawer_t *drawer_create(DRAWER_TYPE dtype);
void drawer_destroy(drawer_t *drawer);
void drawer_cleanup(void);

#endif // __DRAWMINAL_DRAWER_INCLUDED_H__
