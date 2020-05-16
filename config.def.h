/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

#define OPAQUE                  0xffU

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1;                       /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static int centered = 1;                    /* -c option; centers dmenu on screen */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=14"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeFirst] = { "#c5c8c6", "#373b41" },
	[SchemeNorm] =  { "#c5c8c6", "#373b41" },
	[SchemeSel] =   { "#c5c8c6", "#5f819d" },
	[SchemeOut] =   { "#282a2e", "#81a2be" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 6;
static unsigned int maxhist    = 15;
static int histnodup           = 1;	/* if 0, record repeated histories */
static unsigned int lineheight = 24;         /* -h option; minimum height of a menu line     */
/* intensity of blur level*/
static unsigned int blurlevel  = 7;

//Used for multi-threaded blur effect
#define CPU_THREADS 8

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
