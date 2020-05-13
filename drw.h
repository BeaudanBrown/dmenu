/* See LICENSE file for copyright and license details. */

typedef struct {
	Cursor cursor;
} Cur;

typedef struct Fnt {
	Display *dpy;
	unsigned int h;
	XftFont *xfont;
	FcPattern *pattern;
	struct Fnt *next;
} Fnt;

enum { ColFg, ColBg }; /* Clr scheme index */
typedef XftColor Clr;

typedef struct {
	unsigned int w, h;
	Display *dpy;
	int screen;
	Window root;
	Drawable drawable;
	GC gc;
	Clr *scheme0;
	Clr *scheme;
	Fnt *fonts;
	XImage *screenshot;
} Drw;

/* enums */
enum { SchemeFirst, SchemeNorm, SchemeSel, SchemeOut, SchemeLast }; /* color schemes */

void drw_blurimage (XImage *image, int radius, unsigned int cpu_threads);
void drw_blurrect(Drw *drw, int x, int y, unsigned int w, unsigned int h, unsigned long tint, unsigned int num_threads);

/* Drawable abstraction */
Drw *drw_create(Display *dpy, int screen, Window win, unsigned int w, unsigned int h);
void drw_resize(Drw *drw, unsigned int w, unsigned int h);
void drw_free(Drw *drw);
void drw_takesblurcreenshot(Drw *drw, int x, int y, unsigned int w, unsigned int h, int blurlevel, unsigned int num_threads);

/* Fnt abstraction */
Fnt *drw_fontset_create(Drw* drw, const char *fonts[], size_t fontcount);
void drw_fontset_free(Fnt* set);
unsigned int drw_fontset_getwidth(Drw *drw, const char *text);
void drw_font_getexts(Fnt *font, const char *text, unsigned int len, unsigned int *w, unsigned int *h);

/* Colorscheme abstraction */
void drw_clr_create(Drw *drw, Clr *dest, const char *clrname);
Clr *drw_scm_create(Drw *drw, const char *clrnames[], size_t clrcount);

/* Cursor abstraction */
Cur *drw_cur_create(Drw *drw, int shape);
void drw_cur_free(Drw *drw, Cur *cursor);

/* Drawing context manipulation */
void drw_setfontset(Drw *drw, Fnt *set);
void drw_setscheme(Drw *drw, Clr *scm);

/* Drawing functions */
void drw_rect(Drw *drw, int x, int y, unsigned int w, unsigned int h, int filled, int invert, unsigned int num_threads);
int drw_text(Drw *drw, int x, int y, unsigned int w, unsigned int h, unsigned int lpad, const char *text, int invert, unsigned int num_threads);

/* Map functions */
void drw_map(Drw *drw, Window win, int x, int y, unsigned int w, unsigned int h);
