#ifndef __DRAWMINAL_DRAWER_INCLUDED_H__
#define __DRAWMINAL_DRAWER_INCLUDED_H__

typedef enum {
    BUFFERED
} DRAWER_TYPE;

struct Drawer {
    DRAWER_TYPE type;
};

typedef struct Drawer drawer_t;

void draw(void *buffer, int nlayer);

#endif // __DRAWMINAL_DRAWER_INCLUDED_H__
