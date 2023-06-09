/* sqMemoryAccess.h -- memory accessors (and associated type definitions)
 * 
 * Author: Ian.Piumarta@squeakland.org
 * 
 * Last edited: 2007-06-10 19:16:03 by piumarta on vps2.piumarta.com
 */

/* Systematic use of the macros defined in this file within the
 * Interpreter, ObjectMemory and plugins will permit all four
 * combinations of 32/64-bit image and 32/64-bit host to compile and
 * run correctly.  (Code that uses explicit casts and/or integer
 * constants in arithmetic on object pointers will invariably fail in
 * at least one of the four possible combinations.)
 */

#ifndef __sqMemoryAccess_h
#define __sqMemoryAccess_h

#include "config.h"

#if defined(HAVE_INTERP_H)
# include "interp.h"
#else
# define SQ_VI_BYTES_PER_WORD 4		/* build a 32-bit VM */
# warning 
# warning ***************************************************
# warning *
# warning * interp.h not found -- defaulting to a 32-bit VM
# warning *
# warning * update your image-side VM sources to the latest
# warning * version to avoid this message
# warning *
# warning ***************************************************
# warning 
#endif

#if (SQ_VI_BYTES_PER_WORD == 4)
# define SQ_IMAGE32 1
#else
# define SQ_IMAGE64 1
#endif

#if (SQ_IMAGE64 || SPURVM)
# define OBJECTS_32BIT_ALIGNED 0
#else
# define OBJECTS_32BIT_ALIGNED 1
#endif

#if (SIZEOF_VOID_P == 4)
# define SQ_HOST32 1
#elif (SIZEOF_VOID_P == 8)
# define SQ_HOST64 1
#else
# error host is neither 32- nor 64-bit?
#endif

#if defined(SQ_IMAGE32)
  typedef int		sqInt;
  typedef unsigned int	usqInt;
#elif defined(SQ_HOST64)
  typedef long		sqInt;
  typedef unsigned long	usqInt;
#else
# if (SIZEOF_LONG_LONG != 8)
#   error long long integers are not 64-bits wide?
# endif 
  typedef long long		sqInt;
  typedef unsigned long long	usqInt;
#endif

#ifndef SIZEOF_LONG
#  if LLP64
#    define SIZEOF_LONG 4
#  else
#    define SIZEOF_LONG SIZEOF_VOID_P /* default is sizeof(long)==sizeof(void *) */
#  endif
#endif

/* sqLong is a signed integer with at least 64bits on both 32 and 64 bits images
   usqLong is the unsigned flavour
   SQLABS is a macro for taking absolute value of a sqLong */
#if !defined(sqLong)
#  if SIZEOF_LONG == 8
#     define sqLong long
#     define usqLong unsigned long
#     define SQLABS labs
#  elif _MSC_VER
#     define sqLong __int64
#     define usqLong unsigned __int64
#     define SQLABS llabs
#  else
#     define sqLong long long
#     define usqLong unsigned long long
#     define SQLABS llabs
#  endif
#endif /* !defined(sqLong) */

/* sqIntptr_t is a signed integer with enough bits to hold a pointer
   usqIntptr_t is the unsigned flavour
   this is essentially C99 intptr_t and uintptr_t but we support legacy compilers
   the C99 printf formats macros are also defined with SQ prefix */
#if SIZEOF_LONG == SIZEOF_VOID_P
typedef long sqIntptr_t;
typedef unsigned long usqIntptr_t;
#define PRIdSQPTR "ld"
#define PRIuSQPTR "lu"
#define PRIxSQPTR "lx"
#define PRIXSQPTR "lX"
#else
typedef long long sqIntptr_t;
typedef unsigned long long usqIntptr_t;
#define PRIdSQPTR "lld"
#define PRIuSQPTR "llu"
#define PRIxSQPTR "llx"
#define PRIXSQPTR "llX"
#endif

#if defined(SQ_HOST64) && defined(SQ_IMAGE32)
  extern char *sqMemoryBase;
# define SQ_FAKE_MEMORY_OFFSET	16 // (1*1024*1024)	/* nonzero to debug addr xlation */
#else
# define sqMemoryBase		((char *)0)
#endif

#ifdef USE_INLINE_MEMORY_ACCESSORS
  /* Use static inline functions when the compiler produces efficient code for small accessors.
     These are preferred because static type checking will prevent inadvertent confusion of pointers and oops. */
  static inline sqInt byteAtPointer(char *ptr)			{ return (sqInt)(*((unsigned char *)ptr)); }
  static inline sqInt byteAtPointerput(char *ptr, int val)	{ return (sqInt)(*((unsigned char *)ptr)= (unsigned char)val); }
  static inline sqInt shortAtPointer(char *ptr)			{ return (sqInt)(*((short *)ptr)); }
  static inline sqInt shortAtPointerput(char *ptr, int val)	{ return (sqInt)(*((short *)ptr)= (short)val); }
  static inline sqInt intAtPointer(char *ptr)			{ return (sqInt)(*((unsigned int *)ptr)); }
  static inline sqInt intAtPointerput(char *ptr, int val)	{ return (sqInt)(*((unsigned int *)ptr)= (int)val); }
  static inline sqInt longAtPointer(char *ptr)			{ return (sqInt)(*((sqInt *)ptr)); }
  static inline sqInt longAtPointerput(char *ptr, sqInt val)	{ return (sqInt)(*((sqInt *)ptr)= (sqInt)val); }
  static inline sqLong long64AtPointer(char *ptr)		{ return *(sqLong *)ptr; }
  static inline sqLong long64AtPointerput(char *ptr, sqLong val)	{ return *(sqLong *)ptr= val; }
  static inline sqInt oopAtPointer(char *ptr)			{ return (sqInt)(*((sqInt *)ptr)); }
  static inline sqInt oopAtPointerput(char *ptr, sqInt val)	{ return (sqInt)(*((sqInt *)ptr)= (sqInt)val); }
  static inline char *pointerForOop(usqInt oop)			{ return sqMemoryBase + oop; }
  static inline sqInt oopForPointer(char *ptr)			{ return (sqInt)(ptr - sqMemoryBase); }
  static inline sqInt byteAt(sqInt oop)				{ return byteAtPointer(pointerForOop(oop)); }
  static inline sqInt byteAtput(sqInt oop, int val)		{ return byteAtPointerput(pointerForOop(oop), val); }
  static inline sqInt shortAt(sqInt oop)			{ return shortAtPointer(pointerForOop(oop)); }
  static inline sqInt shortAtput(sqInt oop, int val)		{ return shortAtPointerput(pointerForOop(oop), val); }
  static inline sqInt intAt(sqInt oop)				{ return intAtPointer(pointerForOop(oop)); }
  static inline sqInt intAtput(sqInt oop, int val)		{ return intAtPointerput(pointerForOop(oop), val); }
  static inline sqInt longAt(sqInt oop)				{ return longAtPointer(pointerForOop(oop)); }
  static inline sqInt longAtput(sqInt oop, sqInt val)		{ return longAtPointerput(pointerForOop(oop), val); }
  static inline sqLong long64At(sqInt oop)			{ return long64AtPointer(pointerForOop(oop)); }
  static inline sqLong long64Atput(sqInt oop, sqLong val)	{ return long64AtPointerput(pointerForOop(oop), val); }
  static inline sqInt oopAt(sqInt oop)				{ return oopAtPointer(pointerForOop(oop)); }
  static inline sqInt oopAtput(sqInt oop, sqInt val)		{ return oopAtPointerput(pointerForOop(oop), val); }
#else
  /* Use macros when static inline functions aren't efficient. */
# define byteAtPointer(ptr)		((sqInt)(*((unsigned char *)(ptr))))
# define byteAtPointerput(ptr, val)	((sqInt)(*((unsigned char *)(ptr))= (unsigned char)(val)))
# define shortAtPointer(ptr)		((sqInt)(*((short *)(ptr))))
# define shortAtPointerput(ptr, val)	((sqInt)(*((short *)(ptr))= (short)(val)))
# define intAtPointer(ptr)		((sqInt)(*((unsigned int *)(ptr))))
# define intAtPointerput(ptr, val)	((sqInt)(*((unsigned int *)(ptr))= (int)(val)))
# define longAtPointer(ptr)		((sqInt)(*((sqInt *)(ptr))))
# define longAtPointerput(ptr, val)	((sqInt)(*((sqInt *)(ptr))= (sqInt)(val)))
# define long64AtPointer(ptr)		(*(sqLong *)(ptr))
# define long64AtPointerput(ptr,val)	(*(sqLong *)(ptr)= (sqLong)(val))
# define oopAtPointer(ptr)		(sqInt)(*((sqInt *)ptr))
# define oopAtPointerput(ptr, val)	(sqInt)(*((sqInt *)ptr)= (sqInt)val)
# define pointerForOop(oop)		((char *)(sqMemoryBase + ((usqInt)(oop))))
# define oopForPointer(ptr)		((sqInt)(((char *)(ptr)) - (sqMemoryBase)))
# define byteAt(oop)			byteAtPointer(pointerForOop(oop))
# define byteAtput(oop, val)		byteAtPointerput(pointerForOop(oop), (val))
# define shortAt(oop)			shortAtPointer(pointerForOop(oop))
# define shortAtput(oop, val)		shortAtPointerput(pointerForOop(oop), (val))
# define longAt(oop)			longAtPointer(pointerForOop(oop))
# define longAtput(oop, val)		longAtPointerput(pointerForOop(oop), (val))
# define long64At(oop)			long64AtPointer(pointerForOop(oop))
# define long64Atput(oop,val)		long64AtPointerput(pointerForOop(oop), val)
# define intAt(oop)			intAtPointer(pointerForOop(oop))
# define intAtput(oop, val)		intAtPointerput(pointerForOop(oop), (val))
# define oopAt(oop)			oopAtPointer(pointerForOop(oop))
# define oopAtput(oop, val)		oopAtPointerput(pointerForOop(oop), (val))
#endif

#define long32At	intAt
#define long32Atput	intAtput

/* platform-dependent float conversion macros */
/* Note: Second argument must be a variable name, not an expression! */
/* Note: Floats in image are always in PowerPC word order; change
   these macros to swap words if necessary. This costs no extra and
   obviates sometimes having to word-swap floats when reading an image.
*/
#if defined(OBJECTS_32BIT_ALIGNED) || defined(DOUBLE_WORD_ORDER)
/* this is to allow strict aliasing assumption in the optimizer */
typedef union { double d; int i[sizeof(double) / sizeof(int)]; } _swapper;
# ifdef DOUBLE_WORD_ORDER
/* word-based copy with swapping for non-PowerPC order */
#   define storeFloatAtPointerfrom(intPointerToFloat, floatVarName) \
	*((int *)(intPointerToFloat) + 0) = ((_swapper *)(&floatVarName))->i[1]; \
	*((int *)(intPointerToFloat) + 1) = ((_swapper *)(&floatVarName))->i[0];
#   define fetchFloatAtPointerinto(intPointerToFloat, floatVarName) \
	((_swapper *)(&floatVarName))->i[1] = *((int *)(intPointerToFloat) + 0); \
	((_swapper *)(&floatVarName))->i[0] = *((int *)(intPointerToFloat) + 1);
# else /*!DOUBLE_WORD_ORDER*/
/* word-based copy for machines with alignment restrictions */
#   define storeFloatAtPointerfrom(intPointerToFloat, floatVarName) \
	*((int *)(intPointerToFloat) + 0) = ((_swapper *)(&floatVarName))->i[0]; \
	*((int *)(intPointerToFloat) + 1) = ((_swapper *)(&floatVarName))->i[1];
#   define fetchFloatAtPointerinto(intPointerToFloat, floatVarName) \
	((_swapper *)(&floatVarName))->i[0] = *((int *)(intPointerToFloat) + 0); \
	((_swapper *)(&floatVarName))->i[1] = *((int *)(intPointerToFloat) + 1);
# endif /*!DOUBLE_WORD_ORDER*/
#else /*!(DOUBLE_WORD_ORDER||OBJECTS_32BIT_ALIGNED)*/
/* for machines that allow doubles to be on any word boundary */
# define storeFloatAtPointerfrom(i, floatVarName) \
	*((double *) (i)) = (floatVarName);
# define fetchFloatAtPointerinto(i, floatVarName) \
	(floatVarName) = *((double *) (i));
#endif

#define storeFloatAtfrom(i, floatVarName)	storeFloatAtPointerfrom(pointerForOop(i), floatVarName)
#define fetchFloatAtinto(i, floatVarName)	fetchFloatAtPointerinto(pointerForOop(i), floatVarName)


/* This doesn't belong here, but neither do 'self flag: ...'s belong in the image. */

static inline void flag(char *ignored)
{
  (void)ignored;
}


#endif /* __sqMemoryAccess_h */
