#if !defined(_DRI_GENDEFH_)
#define _DRI_GENDEFH_

#define PRIVATE static
#define PUBLIC

#define INIT(init_func) void _dri_init() { init_func(); } /* reserved */

#endif
