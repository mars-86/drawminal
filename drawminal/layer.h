#ifndef __TGRAPH_LIB_LAYER_INCLUDED_H__
#define __TGRAPH_LIB_LAYER_INCLUDED_H__

#include <stdio.h>

struct _Layer {
    wchar_t *buffer;
    int visible;
};

typedef struct _Layer layer_t;

int layer_add(void);
void layer_delete(int nlayer);
void layer_show(int nlayer, int show);

#endif // __TGRAPH_LIB_LAYER_INCLUDED_H__
