/* See LICENSE file for copyright and license details. */
static char font[] = "monospace:size=10";   /* -fn option overrides fonts[0]; default font */
static const char *fonts[] = {
	font,
	"Vazir:size=10",
	"emoji:size=10",
};

static int topbar 		= 1;	/* -b  option; if 0, dmenu appears at bottom */
static unsigned int border_width= 2;	/* -bw option; size of the window border */
static char *prompt      	= NULL;	/* -p  option; prompt to the left of input field */
static unsigned int preselected = 0;	/* -n option; preselected item starting from 0 */
static unsigned int lines      	= 0;	/* -l option; if nonzero dmenu draws vertical list */
static const unsigned int alpha = 0xf0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

static char normfgcolor[] = "#ECEFF4";
static char normbgcolor[] = "#3B4252";
static char normhlcolor[] = "#EBCB8B";
static char selfgcolor[]  = "#EBCB8B";
static char selbgcolor[]  = "#4C566A";
static char selhlcolor[]  = "#E5E9F0";
static char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] 		= { normfgcolor, normbgcolor },
	[SchemeSel]  		= { selfgcolor,  selbgcolor  },
	[SchemeNormHighlight] 	= { normhlcolor, normbgcolor },
	[SchemeSelHighlight] 	= { selhlcolor,	 selbgcolor },
	[SchemeOut]  		= { "#000000",   "#00ffff" },
	[SchemeOutHighlight]  	= { normhlcolor, "#00ffff" },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm]		= { OPAQUE, alpha },
	[SchemeSel] 		= { OPAQUE, alpha },
	[SchemeOut] 		= { OPAQUE, alpha },
	[SchemeNormHighlight] 	= { OPAQUE, alpha },
	[SchemeSelHighlight] 	= { OPAQUE, alpha },
	[SchemeOutHighlight] 	= { OPAQUE, alpha },
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
	{ "font",        STRING, &font },
	{ "color12", 	 STRING, &normfgcolor },
	{ "color0", 	 STRING, &normbgcolor },
	{ "color11",  	 STRING, &normhlcolor },
	{ "color0",  	 STRING, &selfgcolor },
	{ "color12",  	 STRING, &selbgcolor },
	{ "color8",  	 STRING, &selhlcolor },
	{ "prompt",      STRING, &prompt },
};

