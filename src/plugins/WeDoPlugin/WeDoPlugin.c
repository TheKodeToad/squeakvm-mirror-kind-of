/* Smalltalk from Squeak4.6 with VMMaker 4.20.3 translated as C source on 30 December 2022 5:14:20 pm */
/* Automatically generated by
	VMPluginCodeGenerator VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
   from
	WeDoPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
 */
static char __buildInfo[] = "WeDoPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7 " __DATE__ ;




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
#include "WeDoPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primClosePort(void);
EXPORT(sqInt) primOpenPort(void);
EXPORT(sqInt) primRead(void);
EXPORT(sqInt) primWrite(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"WeDoPlugin 30 December 2022 (i)"
#else
	"WeDoPlugin 30 December 2022 (e)"
#endif
;



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


/*	Close the WeDo port. */

EXPORT(sqInt) primClosePort(void) {
	interpreterProxy->success(WeDoClosePort());
	return 0;
}


/*	Open the WeDo port. */

EXPORT(sqInt) primOpenPort(void) {
	interpreterProxy->success(WeDoOpenPort());
	return 0;
}


/*	Read data from the WeDo port into the given buffer (a ByteArray or String). Answer the number of bytes read. */

EXPORT(sqInt) primRead(void) {
    sqInt bufOop;
    char *bufPtr;
    sqInt bufSize;
    sqInt byteCount;

	bufOop = interpreterProxy->stackValue(0);
	if (((bufOop & 1)) || (!(interpreterProxy->isBytes(bufOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	bufPtr = ((char *) (interpreterProxy->firstIndexableField(bufOop)));
	bufSize = interpreterProxy->stSizeOf(bufOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	byteCount = WeDoRead(bufPtr, bufSize);
	if (byteCount < 0) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(byteCount);
	return 0;
}


/*	Write data to the WeDo port from the given buffer (a ByteArray or String). Answer the number of bytes written. */

EXPORT(sqInt) primWrite(void) {
    sqInt bufOop;
    char *bufPtr;
    sqInt bufSize;
    sqInt byteCount;

	bufOop = interpreterProxy->stackValue(0);
	if (((bufOop & 1)) || (!(interpreterProxy->isBytes(bufOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	bufPtr = ((char *) (interpreterProxy->firstIndexableField(bufOop)));
	bufSize = interpreterProxy->stSizeOf(bufOop);
	if (interpreterProxy->failed()) {
		return 0;
	}
	byteCount = WeDoWrite(bufPtr, bufSize);
	if (byteCount < 0) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushInteger(byteCount);
	return 0;
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


void* WeDoPlugin_exports[][3] = {
	{"WeDoPlugin", "primOpenPort", (void*)primOpenPort},
	{"WeDoPlugin", "primRead", (void*)primRead},
	{"WeDoPlugin", "primWrite", (void*)primWrite},
	{"WeDoPlugin", "setInterpreter", (void*)setInterpreter},
	{"WeDoPlugin", "primClosePort", (void*)primClosePort},
	{"WeDoPlugin", "getModuleName", (void*)getModuleName},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

