/* Smalltalk from Squeak4.5 with VMMaker 4.15.7 translated as C source on 9 July 2016 12:04:24 pm */
/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-dtl.384 uuid: 53635f21-7aaa-454b-bbfc-9fc2b67fb70b
   from
	MD5Plugin * CryptographyPlugins-rww.10 uuid: 8beefa4e-8411-4385-93ed-1c5d66481465
 */
static char __buildInfo[] = "MD5Plugin * CryptographyPlugins-rww.10 uuid: 8beefa4e-8411-4385-93ed-1c5d66481465 " __DATE__ ;




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
/* Configuration options */
#include "sqConfig.h"
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
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
sqInt md5ProcessBufferwithState(unsigned int*buffer, unsigned int*state);
#pragma export on
EXPORT(sqInt) primitiveDecodeState(void);
EXPORT(sqInt) primitiveInitializeState(void);
EXPORT(sqInt) primitivePluginAvailable(void);
EXPORT(sqInt) primitiveProcessBufferWithState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"MD5Plugin 9 July 2016 (i)"
#else
	"MD5Plugin 9 July 2016 (e)"
#endif
;
static sqInt simulator;
static sqInt swap;



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


/*	This method is generated. See #compileMethods on the class side. */

sqInt md5ProcessBufferwithState(unsigned int*buffer, unsigned int*state) {
	unsigned int d;
	unsigned int a;
	unsigned int c;
	unsigned int b;

	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	a += (((b & c) | ((~b) & d)) + (buffer[0])) + 3614090360U;
	a = ((a << 7) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | ((~a) & c)) + (buffer[1])) + 3905402710U;
	d = ((d << 12) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | ((~d) & b)) + (buffer[2])) + 606105819;
	c = ((c << 17) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | ((~c) & a)) + (buffer[3])) + 3250441966U;
	b = ((b << 22) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | ((~b) & d)) + (buffer[4])) + 4118548399U;
	a = ((a << 7) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | ((~a) & c)) + (buffer[5])) + 1200080426;
	d = ((d << 12) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | ((~d) & b)) + (buffer[6])) + 2821735955U;
	c = ((c << 17) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | ((~c) & a)) + (buffer[7])) + 4249261313U;
	b = ((b << 22) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | ((~b) & d)) + (buffer[8])) + 1770035416;
	a = ((a << 7) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | ((~a) & c)) + (buffer[9])) + 2336552879U;
	d = ((d << 12) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | ((~d) & b)) + (buffer[10])) + 4294925233U;
	c = ((c << 17) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | ((~c) & a)) + (buffer[11])) + 2304563134U;
	b = ((b << 22) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & c) | ((~b) & d)) + (buffer[12])) + 1804603682;
	a = ((a << 7) | (((usqInt) a) >> (32 - 7))) + b;
	d += (((a & b) | ((~a) & c)) + (buffer[13])) + 4254626195U;
	d = ((d << 12) | (((usqInt) d) >> (32 - 12))) + a;
	c += (((d & a) | ((~d) & b)) + (buffer[14])) + 2792965006U;
	c = ((c << 17) | (((usqInt) c) >> (32 - 17))) + d;
	b += (((c & d) | ((~c) & a)) + (buffer[15])) + 1236535329;
	b = ((b << 22) | (((usqInt) b) >> (32 - 22))) + c;
	a += (((b & d) | (c & (~d))) + (buffer[1])) + 4129170786U;
	a = ((a << 5) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & (~c))) + (buffer[6])) + 3225465664U;
	d = ((d << 9) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & (~b))) + (buffer[11])) + 643717713;
	c = ((c << 14) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & (~a))) + (buffer[0])) + 3921069994U;
	b = ((b << 20) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & (~d))) + (buffer[5])) + 3593408605U;
	a = ((a << 5) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & (~c))) + (buffer[10])) + 38016083;
	d = ((d << 9) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & (~b))) + (buffer[15])) + 3634488961U;
	c = ((c << 14) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & (~a))) + (buffer[4])) + 3889429448U;
	b = ((b << 20) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & (~d))) + (buffer[9])) + 568446438;
	a = ((a << 5) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & (~c))) + (buffer[14])) + 3275163606U;
	d = ((d << 9) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & (~b))) + (buffer[3])) + 4107603335U;
	c = ((c << 14) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & (~a))) + (buffer[8])) + 1163531501;
	b = ((b << 20) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b & d) | (c & (~d))) + (buffer[13])) + 2850285829U;
	a = ((a << 5) | (((usqInt) a) >> (32 - 5))) + b;
	d += (((a & c) | (b & (~c))) + (buffer[2])) + 4243563512U;
	d = ((d << 9) | (((usqInt) d) >> (32 - 9))) + a;
	c += (((d & b) | (a & (~b))) + (buffer[7])) + 1735328473;
	c = ((c << 14) | (((usqInt) c) >> (32 - 14))) + d;
	b += (((c & a) | (d & (~a))) + (buffer[12])) + 2368359562U;
	b = ((b << 20) | (((usqInt) b) >> (32 - 20))) + c;
	a += (((b ^ c) ^ d) + (buffer[5])) + 4294588738U;
	a = ((a << 4) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[8])) + 2272392833U;
	d = ((d << 11) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[11])) + 1839030562;
	c = ((c << 16) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[14])) + 4259657740U;
	b = ((b << 23) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[1])) + 2763975236U;
	a = ((a << 4) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[4])) + 1272893353;
	d = ((d << 11) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[7])) + 4139469664U;
	c = ((c << 16) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[10])) + 3200236656U;
	b = ((b << 23) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[13])) + 681279174;
	a = ((a << 4) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[0])) + 3936430074U;
	d = ((d << 11) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[3])) + 3572445317U;
	c = ((c << 16) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[6])) + 76029189;
	b = ((b << 23) | (((usqInt) b) >> (32 - 23))) + c;
	a += (((b ^ c) ^ d) + (buffer[9])) + 3654602809U;
	a = ((a << 4) | (((usqInt) a) >> (32 - 4))) + b;
	d += (((a ^ b) ^ c) + (buffer[12])) + 3873151461U;
	d = ((d << 11) | (((usqInt) d) >> (32 - 11))) + a;
	c += (((d ^ a) ^ b) + (buffer[15])) + 530742520;
	c = ((c << 16) | (((usqInt) c) >> (32 - 16))) + d;
	b += (((c ^ d) ^ a) + (buffer[2])) + 3299628645U;
	b = ((b << 23) | (((usqInt) b) >> (32 - 23))) + c;
	a += ((c ^ (b | (~d))) + (buffer[0])) + 4096336452U;
	a = ((a << 6) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | (~c))) + (buffer[7])) + 1126891415;
	d = ((d << 10) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | (~b))) + (buffer[14])) + 2878612391U;
	c = ((c << 15) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | (~a))) + (buffer[5])) + 4237533241U;
	b = ((b << 21) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | (~d))) + (buffer[12])) + 1700485571;
	a = ((a << 6) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | (~c))) + (buffer[3])) + 2399980690U;
	d = ((d << 10) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | (~b))) + (buffer[10])) + 4293915773U;
	c = ((c << 15) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | (~a))) + (buffer[1])) + 2240044497U;
	b = ((b << 21) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | (~d))) + (buffer[8])) + 1873313359;
	a = ((a << 6) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | (~c))) + (buffer[15])) + 4264355552U;
	d = ((d << 10) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | (~b))) + (buffer[6])) + 2734768916U;
	c = ((c << 15) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | (~a))) + (buffer[13])) + 1309151649;
	b = ((b << 21) | (((usqInt) b) >> (32 - 21))) + c;
	a += ((c ^ (b | (~d))) + (buffer[4])) + 4149444226U;
	a = ((a << 6) | (((usqInt) a) >> (32 - 6))) + b;
	d += ((b ^ (a | (~c))) + (buffer[11])) + 3174756917U;
	d = ((d << 10) | (((usqInt) d) >> (32 - 10))) + a;
	c += ((a ^ (d | (~b))) + (buffer[2])) + 718787259;
	c = ((c << 15) | (((usqInt) c) >> (32 - 15))) + d;
	b += ((d ^ (c | (~a))) + (buffer[9])) + 3951481745U;
	b = ((b << 21) | (((usqInt) b) >> (32 - 21))) + c;
	state[0] = ((state[0]) + a);
	state[1] = ((state[1]) + b);
	state[2] = ((state[2]) + c);
	state[3] = ((state[3]) + d);
	return null;
}


/*	This method is generated. See #compileMethods on the class side. */

EXPORT(sqInt) primitiveDecodeState(void) {
	char *state;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	state = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveInitializeState(void) {
	char *state;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	state = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin md5InitializeState: */
	(((unsigned int*) state))[0] = 1732584193;
	(((unsigned int*) state))[1] = 4023233417U;
	(((unsigned int*) state))[2] = 2562383102U;
	(((unsigned int*) state))[3] = 271733878;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitivePluginAvailable(void) {
	sqInt _return_value;

	_return_value = (1? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveProcessBufferWithState(void) {
	char *buffer;
	char *state;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	buffer = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	state = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	md5ProcessBufferwithState(((unsigned int*) buffer), ((unsigned int*) state));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
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


#ifdef SQUEAK_BUILTIN_PLUGIN


void* MD5Plugin_exports[][3] = {
	{"MD5Plugin", "getModuleName", (void*)getModuleName},
	{"MD5Plugin", "setInterpreter", (void*)setInterpreter},
	{"MD5Plugin", "primitivePluginAvailable", (void*)primitivePluginAvailable},
	{"MD5Plugin", "primitiveInitializeState", (void*)primitiveInitializeState},
	{"MD5Plugin", "primitiveProcessBufferWithState", (void*)primitiveProcessBufferWithState},
	{"MD5Plugin", "primitiveDecodeState", (void*)primitiveDecodeState},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

