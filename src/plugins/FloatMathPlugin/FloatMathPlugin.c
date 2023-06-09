/* Smalltalk from Squeak4.6 with VMMaker 4.20.3 translated as C source on 30 December 2022 5:14:16 pm */
/* Automatically generated by
	VMPluginCodeGenerator VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
   from
	FloatMathPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
 */
static char __buildInfo[] = "FloatMathPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7 " __DATE__ ;




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
#include "FloatMathPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primitiveArcCos(void);
EXPORT(sqInt) primitiveArcCosH(void);
EXPORT(sqInt) primitiveArcSin(void);
EXPORT(sqInt) primitiveArcSinH(void);
EXPORT(sqInt) primitiveArcTan(void);
EXPORT(sqInt) primitiveArcTan2(void);
EXPORT(sqInt) primitiveArcTanH(void);
EXPORT(sqInt) primitiveCos(void);
EXPORT(sqInt) primitiveCosH(void);
EXPORT(sqInt) primitiveExp(void);
EXPORT(sqInt) primitiveFMod(void);
EXPORT(sqInt) primitiveFractionalPart(void);
EXPORT(sqInt) primitiveHypot(void);
EXPORT(sqInt) primitiveLog10(void);
EXPORT(sqInt) primitiveLogN(void);
EXPORT(sqInt) primitiveRaisedToPower(void);
EXPORT(sqInt) primitiveSin(void);
EXPORT(sqInt) primitiveSinH(void);
EXPORT(sqInt) primitiveSqrt(void);
EXPORT(sqInt) primitiveTan(void);
EXPORT(sqInt) primitiveTanH(void);
EXPORT(sqInt) primitiveTimesTwoPower(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FloatMathPlugin 30 December 2022 (i)"
#else
	"FloatMathPlugin 30 December 2022 (e)"
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


/*	Computes acos(receiver) */

EXPORT(sqInt) primitiveArcCos(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_acos(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes acosh(receiver) */

EXPORT(sqInt) primitiveArcCosH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_acosh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes asin(receiver) */

EXPORT(sqInt) primitiveArcSin(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_asin(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes asinh(receiver) */

EXPORT(sqInt) primitiveArcSinH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_asinh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes atan(receiver) */

EXPORT(sqInt) primitiveArcTan(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atan(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes atan2(receiver, arg) */

EXPORT(sqInt) primitiveArcTan2(void) {
    double arg;
    double rcvr;
    double result;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atan2(rcvr, arg);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes atanh(receiver) */

EXPORT(sqInt) primitiveArcTanH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_atanh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes cos(receiver) */

EXPORT(sqInt) primitiveCos(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_cos(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes cosh(receiver) */

EXPORT(sqInt) primitiveCosH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_cosh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes E raised to the receiver power. */

EXPORT(sqInt) primitiveExp(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_exp(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes receiver \\ arg */

EXPORT(sqInt) primitiveFMod(void) {
    double arg;
    double rcvr;
    double result;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_fmod(rcvr, arg);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes receiver \\ 1.0 */

EXPORT(sqInt) primitiveFractionalPart(void) {
    double rcvr;
    double result;
    double trunc;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_modf(rcvr, &trunc);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	hypot(x,y) returns sqrt(x^2+y^2) with error less  than 1 ulps */

EXPORT(sqInt) primitiveHypot(void) {
    double arg;
    double rcvr;
    double result;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_hypot(rcvr, arg);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes log10(receiver) */

EXPORT(sqInt) primitiveLog10(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_log10(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes log(receiver) */

EXPORT(sqInt) primitiveLogN(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_log(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes receiver**arg */

EXPORT(sqInt) primitiveRaisedToPower(void) {
    double arg;
    double rcvr;
    double result;

	arg = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_pow(rcvr, arg);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes sin(receiver) */

EXPORT(sqInt) primitiveSin(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_sin(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes sinh(receiver) */

EXPORT(sqInt) primitiveSinH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_sinh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes sqrt(receiver) */

EXPORT(sqInt) primitiveSqrt(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (rcvr < 0.0) {
		return interpreterProxy->primitiveFail();
	}
	result = __ieee754_sqrt(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes tan(receiver) */

EXPORT(sqInt) primitiveTan(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_tan(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes tanh(receiver) */

EXPORT(sqInt) primitiveTanH(void) {
    double rcvr;
    double result;

	rcvr = interpreterProxy->stackFloatValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_tanh(rcvr);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
	return null;
}


/*	Computes E raised to the receiver power. */

EXPORT(sqInt) primitiveTimesTwoPower(void) {
    sqInt arg;
    double rcvr;
    double result;

	arg = interpreterProxy->stackIntegerValue(0);
	rcvr = interpreterProxy->stackFloatValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = __ieee754_ldexp(rcvr, arg);
	if (isnan(result)) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->pop((interpreterProxy->methodArgumentCount()) + 1);
	interpreterProxy->pushFloat(result);
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


void* FloatMathPlugin_exports[][3] = {
	{"FloatMathPlugin", "primitiveLogN", (void*)primitiveLogN},
	{"FloatMathPlugin", "primitiveTan", (void*)primitiveTan},
	{"FloatMathPlugin", "primitiveSinH", (void*)primitiveSinH},
	{"FloatMathPlugin", "primitiveArcSin", (void*)primitiveArcSin},
	{"FloatMathPlugin", "primitiveLog10", (void*)primitiveLog10},
	{"FloatMathPlugin", "primitiveArcCos", (void*)primitiveArcCos},
	{"FloatMathPlugin", "primitiveArcCosH", (void*)primitiveArcCosH},
	{"FloatMathPlugin", "primitiveArcTanH", (void*)primitiveArcTanH},
	{"FloatMathPlugin", "primitiveTimesTwoPower", (void*)primitiveTimesTwoPower},
	{"FloatMathPlugin", "primitiveTanH", (void*)primitiveTanH},
	{"FloatMathPlugin", "primitiveSin", (void*)primitiveSin},
	{"FloatMathPlugin", "primitiveFMod", (void*)primitiveFMod},
	{"FloatMathPlugin", "primitiveCosH", (void*)primitiveCosH},
	{"FloatMathPlugin", "primitiveHypot", (void*)primitiveHypot},
	{"FloatMathPlugin", "primitiveArcTan2", (void*)primitiveArcTan2},
	{"FloatMathPlugin", "primitiveCos", (void*)primitiveCos},
	{"FloatMathPlugin", "primitiveArcSinH", (void*)primitiveArcSinH},
	{"FloatMathPlugin", "primitiveArcTan", (void*)primitiveArcTan},
	{"FloatMathPlugin", "primitiveExp", (void*)primitiveExp},
	{"FloatMathPlugin", "setInterpreter", (void*)setInterpreter},
	{"FloatMathPlugin", "primitiveFractionalPart", (void*)primitiveFractionalPart},
	{"FloatMathPlugin", "getModuleName", (void*)getModuleName},
	{"FloatMathPlugin", "primitiveRaisedToPower", (void*)primitiveRaisedToPower},
	{"FloatMathPlugin", "primitiveSqrt", (void*)primitiveSqrt},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

