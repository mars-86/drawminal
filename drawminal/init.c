#include "init.h"
#include "../lib/os/os.h"
#include <stdio.h>
#include <stdlib.h>

static wchar_t *buffer;
static void *stdout_h;
static unsigned int code_page;
static unsigned long tmode;
static CONSOLE_FONT_INFOEX info;

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

}

void tgraph_global_cleanup(void)
{
    set_term_out_cp(code_page);
    set_term_mode(stdout_h, tmode);
    set_term_font(stdout_h, info.FaceName, info.dwFontSize.Y);

    free(buffer);
}
