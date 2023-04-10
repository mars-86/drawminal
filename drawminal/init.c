#include "init.h"
#include "drawer.h"
#include "layer.h"
#include "../lib/os/os.h"
#include <stdio.h>
#include <stdlib.h>

extern drawer_t *drawer;
extern layer_t *layers;

static wchar_t *buffer;
static void *stdout_h;
static unsigned int code_page;
static unsigned long tmode;
static CONSOLE_FONT_INFOEX info;

static void init_layers(int rows, int cols)
{
    layers = (layer_t *)malloc(sizeof(layer_t));
    layers->buffer = (wchar_t *)malloc((rows * cols) * sizeof(wchar_t));
}

static void destroy_layers(void)
{
    free(layers->buffer);
    free(layers);
}

void tgraph_global_init(void)
{
    TerminalSize ts;
    stdout_h = get_term_stdout_handle();
    get_term_buffer_info(stdout_h, &ts);
    
    buffer = (wchar_t *)malloc((ts.row * ts.col) * sizeof(wchar_t));

    code_page = get_term_out_cp();
    get_term_mode(stdout_h, &tmode);
    get_term_font(stdout_h, &info);

    set_term_out_cp(CP_UTF8);
    set_term_mode(stdout_h, ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    set_term_font(stdout_h, L"Iosevka", 14);

    drawer = (drawer_t *)malloc(sizeof(drawer_t));
    init_layers(ts.row, ts.col);
}

void tgraph_global_cleanup(void)
{
    set_term_out_cp(code_page);
    set_term_mode(stdout_h, tmode);
    set_term_font(stdout_h, info.FaceName, info.dwFontSize.Y);

    free(drawer);
    destroy_layers();
    free(buffer);
}
