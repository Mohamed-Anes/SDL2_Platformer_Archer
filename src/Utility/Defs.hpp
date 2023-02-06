#ifndef __DEFS_H__
#define __DEFS_H__


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

#define MS_PER_UPDATE 60 // for the main loop - make 25 ~ 30 if game is slow

#define GRAVITY 100

#define PLAYER_SPEED 100  // pixels per second
#define JUMP_SPEED 100  // pixels per second


#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define ABS(a) ( ((a) > 0) ? (a) : (-a) )
/*
#define IN_RANGE( value, min, max ) ( ((value) >= (min) && (value) <= (max)) ? 1 : 0 )

#define TO_BOOL( a )  ( (a != 0) ? true : false )
*/

/*
template <class VALUE_TYPE> void SWAP(VALUE_TYPE& a, VALUE_TYPE& b)
{
	VALUE_TYPE tmp = a;
	a = b;
	b = tmp;
}
*/


// // Joins a path and file
// inline const char* const PATH(const char* folder, const char* file)
// {
// 	static char path[MID_STR];
// 	sprintf_s(path, MID_STR, "%s/%s", folder, file);
// 	return path;
// }

// // Performance macros
// #define PERF_START(timer) timer.Start()
// #define PERF_PEEK(timer) LOG("%s took %f ms", __FUNCTION__, timer.ReadMs())

#endif	// __DEFS_H__