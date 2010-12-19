//
//  AFKMacros.h
//  A handy set of macros for the iOS developer
//  Include in your .pch file for maximum enjoyment
//
//  Created by Marco Tabini on 10-12-17.
//  Copyright © 2010 AFK Studio Partnership. All rights reserved.
//

// Returns the location of the app's cache directory

static inline NSString *AFKCachesDirectory() {
	return [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0];
}

// Macros to extract the individual elements of a CGRect

#define NSOriginX(rect) rect.origin.x
#define NSOriginY(rect) rect.origin.y
#define NSWidth(rect) rect.size.width
#define NSHeight(rect) rect.size.height

// Extract the centre of a CGRect

#define CGRectCenter(rect) CGPointMake(NSOriginX(rect) + NSWidth(rect) / 2, NSOriginY(rect) + NSHeight(rect) / 2)

// Modify a rectangle by the given deltas

#define CGRectModify(rect,dx,dy,dw,dh) CGRectMake(rect.origin.x + dx, rect.origin.y + dy, rect.size.width + dw, rect.size.height + dh)

// NSLog macro to output a CGRect, CGSize, CGPoint

#define NSLogR(rect) NSLog(@"%@", NSStringFromCGRect(rect))
#define NSLogS(size) NSLog(@"%@", NSStringFromCGSize(size))
#define NSLogP(point) NSLog(@"%@", NSStringFromCGPoint(point))

// Convert degrees to radians

#define degreesToRadians(degrees) degrees / 180.0 * M_PI

// Drop-in replacement for NSLog - outputs the filename and line number.
// In release mode, it's defined away (so no output will be produced).

#ifndef __OPTIMIZE__
# define NSLog(...) NSLog(@"[%s:%d]: %@", __FILE__, __LINE__, [NSString stringWithFormat:__VA_ARGS__])
#else
# define NSLog(...) /* */
#endif

