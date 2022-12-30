/* Smalltalk from Squeak4.6 with VMMaker 4.20.3 translated as C source on 30 December 2022 5:14:16 pm */
/* Automatically generated by
	VMPluginCodeGenerator VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
   from
	DESPlugin CryptographyPlugins-eem.12 uuid: 2945c878-6a44-4c6a-8374-b56aa6175d0f
 */
static char __buildInfo[] = "DESPlugin CryptographyPlugins-eem.12 uuid: 2945c878-6a44-4c6a-8374-b56aa6175d0f " __DATE__ ;




/* Configuration options */
#include "sqConfig.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static sqInt cookKeyto(unsigned long *rawPtr, unsigned long *cookPtr);
static sqInt encryptwith(unsigned long *dataPtr, unsigned long *key);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primitiveDESCookKey(void);
EXPORT(sqInt) primitiveDESPluginAvailable(void);
EXPORT(sqInt) primitiveDESTransform(void);
#pragma export off
static sqInt processKeymodeto(unsigned char *keyPtr, sqInt encode, unsigned long *cookedPtr);
static sqInt scrunchto(unsigned char *bytePtr, unsigned long *wordPtr);
#pragma export on
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
static sqInt unscrunchto(unsigned long *wordPtr, unsigned char *bytePtr);
/*** Variables ***/
static unsigned long bigByte[24] = { 8388608,4194304,2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1, };
static unsigned short byteBit[8] = {
128,64,32,16,8,4,2,1 };

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"DESPlugin 30 December 2022 (i)"
#else
	"DESPlugin 30 December 2022 (e)"
#endif
;
static unsigned char pc1[56] = {
		56, 48, 40, 32, 24, 16,  8,	 0, 57, 49, 41, 33, 25, 17,
		 9,  1, 58, 50, 42, 34, 26,	18, 10,  2, 59, 51, 43, 35,
		62, 54, 46, 38, 30, 22, 14,	 6, 61, 53, 45, 37, 29, 21,
		13,  5, 60, 52, 44, 36, 28,	20, 12,  4, 27, 19, 11,  3 };
static unsigned char pc2[48] = {
		13, 16, 10, 23,  0,  4,	 2, 27, 14,  5, 20,  9,
		22, 18, 11,  3, 25,  7,	15,  6, 26, 19, 12,  1,
		40, 51, 30, 36, 46, 54,	 29, 39, 50, 44, 32, 47,
		43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31 };
static unsigned long sp1[64] = {
		0x01010400L, 0x00000000L, 0x00010000L, 0x01010404L,
		0x01010004L, 0x00010404L, 0x00000004L, 0x00010000L,
		0x00000400L, 0x01010400L, 0x01010404L, 0x00000400L,
		0x01000404L, 0x01010004L, 0x01000000L, 0x00000004L,
		0x00000404L, 0x01000400L, 0x01000400L, 0x00010400L,
		0x00010400L, 0x01010000L, 0x01010000L, 0x01000404L,
		0x00010004L, 0x01000004L, 0x01000004L, 0x00010004L,
		0x00000000L, 0x00000404L, 0x00010404L, 0x01000000L,
		0x00010000L, 0x01010404L, 0x00000004L, 0x01010000L,
		0x01010400L, 0x01000000L, 0x01000000L, 0x00000400L,
		0x01010004L, 0x00010000L, 0x00010400L, 0x01000004L,
		0x00000400L, 0x00000004L, 0x01000404L, 0x00010404L,
		0x01010404L, 0x00010004L, 0x01010000L, 0x01000404L,
		0x01000004L, 0x00000404L, 0x00010404L, 0x01010400L,
		0x00000404L, 0x01000400L, 0x01000400L, 0x00000000L,
		0x00010004L, 0x00010400L, 0x00000000L, 0x01010004L };
static unsigned long sp2[64] = {
		0x80108020L, 0x80008000L, 0x00008000L, 0x00108020L,
		0x00100000L, 0x00000020L, 0x80100020L, 0x80008020L,
		0x80000020L, 0x80108020L, 0x80108000L, 0x80000000L,
		0x80008000L, 0x00100000L, 0x00000020L, 0x80100020L,
		0x00108000L, 0x00100020L, 0x80008020L, 0x00000000L,
		0x80000000L, 0x00008000L, 0x00108020L, 0x80100000L,
		0x00100020L, 0x80000020L, 0x00000000L, 0x00108000L,
		0x00008020L, 0x80108000L, 0x80100000L, 0x00008020L,
		0x00000000L, 0x00108020L, 0x80100020L, 0x00100000L,
		0x80008020L, 0x80100000L, 0x80108000L, 0x00008000L,
		0x80100000L, 0x80008000L, 0x00000020L, 0x80108020L,
		0x00108020L, 0x00000020L, 0x00008000L, 0x80000000L,
		0x00008020L, 0x80108000L, 0x00100000L, 0x80000020L,
		0x00100020L, 0x80008020L, 0x80000020L, 0x00100020L,
		0x00108000L, 0x00000000L, 0x80008000L, 0x00008020L,
		0x80000000L, 0x80100020L, 0x80108020L, 0x00108000L };
static unsigned long sp3[64] = {
		0x00000208L, 0x08020200L, 0x00000000L, 0x08020008L,
		0x08000200L, 0x00000000L, 0x00020208L, 0x08000200L,
		0x00020008L, 0x08000008L, 0x08000008L, 0x00020000L,
		0x08020208L, 0x00020008L, 0x08020000L, 0x00000208L,
		0x08000000L, 0x00000008L, 0x08020200L, 0x00000200L,
		0x00020200L, 0x08020000L, 0x08020008L, 0x00020208L,
		0x08000208L, 0x00020200L, 0x00020000L, 0x08000208L,
		0x00000008L, 0x08020208L, 0x00000200L, 0x08000000L,
		0x08020200L, 0x08000000L, 0x00020008L, 0x00000208L,
		0x00020000L, 0x08020200L, 0x08000200L, 0x00000000L,
		0x00000200L, 0x00020008L, 0x08020208L, 0x08000200L,
		0x08000008L, 0x00000200L, 0x00000000L, 0x08020008L,
		0x08000208L, 0x00020000L, 0x08000000L, 0x08020208L,
		0x00000008L, 0x00020208L, 0x00020200L, 0x08000008L,
		0x08020000L, 0x08000208L, 0x00000208L, 0x08020000L,
		0x00020208L, 0x00000008L, 0x08020008L, 0x00020200L };
static unsigned long sp4[64] = {
		0x00802001L, 0x00002081L, 0x00002081L, 0x00000080L,
		0x00802080L, 0x00800081L, 0x00800001L, 0x00002001L,
		0x00000000L, 0x00802000L, 0x00802000L, 0x00802081L,
		0x00000081L, 0x00000000L, 0x00800080L, 0x00800001L,
		0x00000001L, 0x00002000L, 0x00800000L, 0x00802001L,
		0x00000080L, 0x00800000L, 0x00002001L, 0x00002080L,
		0x00800081L, 0x00000001L, 0x00002080L, 0x00800080L,
		0x00002000L, 0x00802080L, 0x00802081L, 0x00000081L,
		0x00800080L, 0x00800001L, 0x00802000L, 0x00802081L,
		0x00000081L, 0x00000000L, 0x00000000L, 0x00802000L,
		0x00002080L, 0x00800080L, 0x00800081L, 0x00000001L,
		0x00802001L, 0x00002081L, 0x00002081L, 0x00000080L,
		0x00802081L, 0x00000081L, 0x00000001L, 0x00002000L,
		0x00800001L, 0x00002001L, 0x00802080L, 0x00800081L,
		0x00002001L, 0x00002080L, 0x00800000L, 0x00802001L,
		0x00000080L, 0x00800000L, 0x00002000L, 0x00802080L };
static unsigned long sp5[64] = {
		0x00000100L, 0x02080100L, 0x02080000L, 0x42000100L,
		0x00080000L, 0x00000100L, 0x40000000L, 0x02080000L,
		0x40080100L, 0x00080000L, 0x02000100L, 0x40080100L,
		0x42000100L, 0x42080000L, 0x00080100L, 0x40000000L,
		0x02000000L, 0x40080000L, 0x40080000L, 0x00000000L,
		0x40000100L, 0x42080100L, 0x42080100L, 0x02000100L,
		0x42080000L, 0x40000100L, 0x00000000L, 0x42000000L,
		0x02080100L, 0x02000000L, 0x42000000L, 0x00080100L,
		0x00080000L, 0x42000100L, 0x00000100L, 0x02000000L,
		0x40000000L, 0x02080000L, 0x42000100L, 0x40080100L,
		0x02000100L, 0x40000000L, 0x42080000L, 0x02080100L,
		0x40080100L, 0x00000100L, 0x02000000L, 0x42080000L,
		0x42080100L, 0x00080100L, 0x42000000L, 0x42080100L,
		0x02080000L, 0x00000000L, 0x40080000L, 0x42000000L,
		0x00080100L, 0x02000100L, 0x40000100L, 0x00080000L,
		0x00000000L, 0x40080000L, 0x02080100L, 0x40000100L };
static unsigned long sp6[64] = {
		0x20000010L, 0x20400000L, 0x00004000L, 0x20404010L,
		0x20400000L, 0x00000010L, 0x20404010L, 0x00400000L,
		0x20004000L, 0x00404010L, 0x00400000L, 0x20000010L,
		0x00400010L, 0x20004000L, 0x20000000L, 0x00004010L,
		0x00000000L, 0x00400010L, 0x20004010L, 0x00004000L,
		0x00404000L, 0x20004010L, 0x00000010L, 0x20400010L,
		0x20400010L, 0x00000000L, 0x00404010L, 0x20404000L,
		0x00004010L, 0x00404000L, 0x20404000L, 0x20000000L,
		0x20004000L, 0x00000010L, 0x20400010L, 0x00404000L,
		0x20404010L, 0x00400000L, 0x00004010L, 0x20000010L,
		0x00400000L, 0x20004000L, 0x20000000L, 0x00004010L,
		0x20000010L, 0x20404010L, 0x00404000L, 0x20400000L,
		0x00404010L, 0x20404000L, 0x00000000L, 0x20400010L,
		0x00000010L, 0x00004000L, 0x20400000L, 0x00404010L,
		0x00004000L, 0x00400010L, 0x20004010L, 0x00000000L,
		0x20404000L, 0x20000000L, 0x00400010L, 0x20004010L };
static unsigned long sp7[64] = {
		0x00200000L, 0x04200002L, 0x04000802L, 0x00000000L,
		0x00000800L, 0x04000802L, 0x00200802L, 0x04200800L,
		0x04200802L, 0x00200000L, 0x00000000L, 0x04000002L,
		0x00000002L, 0x04000000L, 0x04200002L, 0x00000802L,
		0x04000800L, 0x00200802L, 0x00200002L, 0x04000800L,
		0x04000002L, 0x04200000L, 0x04200800L, 0x00200002L,
		0x04200000L, 0x00000800L, 0x00000802L, 0x04200802L,
		0x00200800L, 0x00000002L, 0x04000000L, 0x00200800L,
		0x04000000L, 0x00200800L, 0x00200000L, 0x04000802L,
		0x04000802L, 0x04200002L, 0x04200002L, 0x00000002L,
		0x00200002L, 0x04000000L, 0x04000800L, 0x00200000L,
		0x04200800L, 0x00000802L, 0x00200802L, 0x04200800L,
		0x00000802L, 0x04000002L, 0x04200802L, 0x04200000L,
		0x00200800L, 0x00000000L, 0x00000002L, 0x04200802L,
		0x00000000L, 0x00200802L, 0x04200000L, 0x00000800L,
		0x04000002L, 0x04000800L, 0x00000800L, 0x00200002L };
static unsigned long sp8[64] = {
		0x10001040L, 0x00001000L, 0x00040000L, 0x10041040L,
		0x10000000L, 0x10001040L, 0x00000040L, 0x10000000L,
		0x00040040L, 0x10040000L, 0x10041040L, 0x00041000L,
		0x10041000L, 0x00041040L, 0x00001000L, 0x00000040L,
		0x10040000L, 0x10000040L, 0x10001000L, 0x00001040L,
		0x00041000L, 0x00040040L, 0x10040040L, 0x10041000L,
		0x00001040L, 0x00000000L, 0x00000000L, 0x10040040L,
		0x10000040L, 0x10001000L, 0x00041040L, 0x00040000L,
		0x00041040L, 0x00040000L, 0x10041000L, 0x00001000L,
		0x00000040L, 0x10040040L, 0x00001000L, 0x00041040L,
		0x10001000L, 0x00000040L, 0x10000040L, 0x10040000L,
		0x10040040L, 0x10000000L, 0x00040000L, 0x10001040L,
		0x00000000L, 0x10041040L, 0x00040040L, 0x10000040L,
		0x10040000L, 0x10001000L, 0x10001040L, 0x00000000L,
		0x10041040L, 0x00041000L, 0x00041000L, 0x00001040L,
		0x00001040L, 0x00040040L, 0x10000000L, 0x10041000L };
static unsigned char totRot[16] = { 1,2,4,6,8,10,12,14,15,17,19,21,23,25,27,28 };



/*	preprocess the key to more useful format */

static sqInt cookKeyto(unsigned long *rawPtr, unsigned long *cookPtr) {
    unsigned long cook;
    sqInt i;
    unsigned long raw0;
    unsigned long raw1;


	/* 32 words */
	/* 32 words */

	for (i = 0; i <= 15; i += 1) {
		raw0 = rawPtr[i * 2];
		raw1 = rawPtr[(i * 2) + 1];
		cook = (raw0 & 0xFC0000) << 6;
		cook = cook | ((raw0 & 0xFC0) << 10);
		cook = cook | (((usqInt) (raw1 & 0xFC0000)) >> 10);
		cook = cook | (((usqInt) (raw1 & 0xFC0)) >> 6);
		cookPtr[i * 2] = cook;
		cook = (raw0 & 0x3F000) << 12;
		cook = cook | ((raw0 & 0x3F) << 16);
		cook = cook | (((usqInt) (raw1 & 0x3F000)) >> 4);
		cook = cook | (raw1 & 0x3F);
		cookPtr[(i * 2) + 1] = cook;
	}
	return null;
}

static sqInt encryptwith(unsigned long *dataPtr, unsigned long *key) {
    unsigned long fVal;
    unsigned long left;
    unsigned long right;
    sqInt round;
    unsigned long work;

	left = dataPtr[0];

	/* perform required but otherwise pointless bit twizzling */

	right = dataPtr[1];
	work = ((((usqInt) left) >> 4) ^ right) & 252645135;
	right = right ^ work;
	left = left ^ (work << 4);
	work = ((((usqInt) left) >> 16) ^ right) & 0xFFFF;
	right = right ^ work;
	left = left ^ (work << 16);
	work = ((((usqInt) right) >> 2) ^ left) & 858993459;
	left = left ^ work;
	right = right ^ (work << 2);
	work = ((((usqInt) right) >> 8) ^ left) & 16711935;
	left = left ^ work;
	right = right ^ (work << 8);
	right = ((right << 1) | ((((usqInt) right) >> 0x1F) & 1)) & 0xFFFFFFFFU;
	work = (left ^ right) & 2863311530U;
	left = left ^ work;
	right = right ^ work;

	/* perform the 8 rounds of real encryption */

	left = ((left << 1) | ((((usqInt) left) >> 0x1F) & 1)) & 0xFFFFFFFFU;
	for (round = 0; round <= 28; round += 4) {
		work = (right << 28) | (((usqInt) right) >> 4);
		work = work ^ (key[round]);
		fVal = sp7[work & 0x3F];
		fVal = fVal | (sp5[(((usqInt) work) >> 8) & 0x3F]);
		fVal = fVal | (sp3[(((usqInt) work) >> 16) & 0x3F]);
		fVal = fVal | (sp1[(((usqInt) work) >> 24) & 0x3F]);
		work = right ^ (key[round + 1]);
		fVal = fVal | (sp8[work & 0x3F]);
		fVal = fVal | (sp6[(((usqInt) work) >> 8) & 0x3F]);
		fVal = fVal | (sp4[(((usqInt) work) >> 16) & 0x3F]);
		fVal = fVal | (sp2[(((usqInt) work) >> 24) & 0x3F]);
		left = left ^ fVal;
		work = (left << 28) | (((usqInt) left) >> 4);
		work = work ^ (key[round + 2]);
		fVal = sp7[work & 0x3F];
		fVal = fVal | (sp5[(((usqInt) work) >> 8) & 0x3F]);
		fVal = fVal | (sp3[(((usqInt) work) >> 16) & 0x3F]);
		fVal = fVal | (sp1[(((usqInt) work) >> 24) & 0x3F]);
		work = left ^ (key[round + 3]);
		fVal = fVal | (sp8[work & 0x3F]);
		fVal = fVal | (sp6[(((usqInt) work) >> 8) & 0x3F]);
		fVal = fVal | (sp4[(((usqInt) work) >> 16) & 0x3F]);
		fVal = fVal | (sp2[(((usqInt) work) >> 24) & 0x3F]);
		right = right ^ fVal;
	}
	right = (right << 0x1F) | (((usqInt) right) >> 1);
	work = (left ^ right) & 2863311530U;
	left = left ^ work;
	right = right ^ work;
	left = (left << 0x1F) | (((usqInt) left) >> 1);
	work = ((((usqInt) left) >> 8) ^ right) & 16711935;
	right = right ^ work;
	left = left ^ (work << 8);
	work = ((((usqInt) left) >> 2) ^ right) & 858993459;
	right = right ^ work;
	left = left ^ (work << 2);
	work = ((((usqInt) right) >> 16) ^ left) & 0xFFFF;
	left = left ^ work;
	right = right ^ (work << 16);
	work = ((((usqInt) right) >> 4) ^ left) & 252645135;
	left = left ^ work;
	right = right ^ (work << 4);
	dataPtr[0] = right;
	dataPtr[1] = left;
	return null;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
	return null;
}


/*	preprocess the key to more useful format

	param1 = raw key: ByteArray[8]
	param2 = 1->encode 0->decode
	param3 = cooked key:  WordArray[32] */

EXPORT(sqInt) primitiveDESCookKey(void) {
    unsigned long * cooked;
    sqInt encode;
    unsigned char * raw;
    sqInt oop;
    sqInt oop1;

	if (!((interpreterProxy->methodArgumentCount()) == 3)) {
		return interpreterProxy->primitiveFail();
	}
	/* begin checkedBytePtrOf: */
	oop = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(oop));
	raw = ((unsigned char *) (interpreterProxy->firstIndexableField(oop)));
	encode = interpreterProxy->stackIntegerValue(1);
	/* begin checkedWordPtrOf: */
	oop1 = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isWords(oop1));
	cooked = ((unsigned long *) (interpreterProxy->firstIndexableField(oop1)));
	if (interpreterProxy->failed()) {
		return null;
	}
	processKeymodeto(raw, encode, cooked);
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitiveDESPluginAvailable(void) {
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(1);
	return null;
}


/*	encrypt/decrypt some data

	param1 = data key: ByteArray[8]
	param2 = cooked key:  WordArray[32] */

EXPORT(sqInt) primitiveDESTransform(void) {
    unsigned long * cooked;
    unsigned char * data;
    unsigned long work[2];
    sqInt oop;
    sqInt oop1;

	/* Hi ho, Hi ho...*/;
	if (!((interpreterProxy->methodArgumentCount()) == 2)) {
		return interpreterProxy->primitiveFail();
	}
	/* begin checkedBytePtrOf: */
	oop = interpreterProxy->stackValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(oop));
	data = ((unsigned char *) (interpreterProxy->firstIndexableField(oop)));
	/* begin checkedWordPtrOf: */
	oop1 = interpreterProxy->stackValue(0);
	interpreterProxy->success(interpreterProxy->isWords(oop1));
	cooked = ((unsigned long *) (interpreterProxy->firstIndexableField(oop1)));
	if (interpreterProxy->failed()) {
		return null;
	}
	scrunchto(data, work);
	encryptwith(work, cooked);
	unscrunchto(work, data);
	interpreterProxy->pop(2);
	return null;
}

static sqInt processKeymodeto(unsigned char *keyPtr, sqInt encode, unsigned long *cookedPtr) {
    sqInt i;
    sqInt j;
    sqInt l;
    sqInt m;
    sqInt n;
    unsigned char pc1m[56];
    unsigned char pcr[56];
    unsigned long rawKey[32];

	/* Who is Keyser Soze? */;
	for (j = 0; j <= 55; j += 1) {
		l = pc1[j];
		m = l & 7;
		if (((keyPtr[((usqInt) l) >> 3]) & (byteBit[m])) != 0) {
			pc1m[j] = 1;
		} else {
			pc1m[j] = 0;
		}
	}
	for (i = 0; i <= 15; i += 1) {
		if (encode) {
			m = i << 1;
		} else {
			m = (15 - i) << 1;
		}
		n = m + 1;
		rawKey[m] = (rawKey[n] = 0);
		for (j = 0; j <= 27; j += 1) {
			l = j + (totRot[i]);
			if (l < 28) {
				pcr[j] = (pc1m[l]);
			} else {
				pcr[j] = (pc1m[l - 28]);
			}
		}
		for (j = 28; j <= 55; j += 1) {
			l = j + (totRot[i]);
			if (l < 56) {
				pcr[j] = (pc1m[l]);
			} else {
				pcr[j] = (pc1m[l - 28]);
			}
		}
		for (j = 0; j <= 23; j += 1) {
			if ((pcr[pc2[j]]) != 0) {
				rawKey[m] = ((rawKey[m]) | (bigByte[j]));
			}
			if ((pcr[pc2[j + 24]]) != 0) {
				rawKey[n] = ((rawKey[n]) | (bigByte[j]));
			}
		}
	}
	cookKeyto(rawKey, cookedPtr);
	return null;
}

static sqInt scrunchto(unsigned char *bytePtr, unsigned long *wordPtr) {
	wordPtr[0] = (((((bytePtr[0]) << 24) + ((bytePtr[1]) << 16)) + ((bytePtr[2]) << 8)) + (bytePtr[3]));
	wordPtr[1] = (((((bytePtr[4]) << 24) + ((bytePtr[5]) << 16)) + ((bytePtr[6]) << 8)) + (bytePtr[7]));
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

static sqInt unscrunchto(unsigned long *wordPtr, unsigned char *bytePtr) {
	bytePtr[0] = ((((usqInt) (wordPtr[0])) >> 24) & 0xFF);
	bytePtr[1] = ((((usqInt) (wordPtr[0])) >> 16) & 0xFF);
	bytePtr[2] = ((((usqInt) (wordPtr[0])) >> 8) & 0xFF);
	bytePtr[3] = ((wordPtr[0]) & 0xFF);
	bytePtr[4] = ((((usqInt) (wordPtr[1])) >> 24) & 0xFF);
	bytePtr[5] = ((((usqInt) (wordPtr[1])) >> 16) & 0xFF);
	bytePtr[6] = ((((usqInt) (wordPtr[1])) >> 8) & 0xFF);
	bytePtr[7] = ((wordPtr[1]) & 0xFF);
	return null;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* DESPlugin_exports[][3] = {
	{"DESPlugin", "setInterpreter", (void*)setInterpreter},
	{"DESPlugin", "primitiveDESPluginAvailable", (void*)primitiveDESPluginAvailable},
	{"DESPlugin", "primitiveDESCookKey", (void*)primitiveDESCookKey},
	{"DESPlugin", "primitiveDESTransform", (void*)primitiveDESTransform},
	{"DESPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

