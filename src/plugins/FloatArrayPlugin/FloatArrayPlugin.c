/* Smalltalk from Squeak4.6 with VMMaker 4.20.3 translated as C source on 30 December 2022 5:14:16 pm */
/* Automatically generated by
	VMPluginCodeGenerator VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
   from
	FloatArrayPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7
 */
static char __buildInfo[] = "FloatArrayPlugin VMMaker-dtl.437 uuid: 720c8b4b-1edc-4154-8f0e-dfb30db137a7 " __DATE__ ;




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
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primitiveAddFloatArray(void);
EXPORT(sqInt) primitiveAddScalar(void);
EXPORT(sqInt) primitiveAt(void);
EXPORT(sqInt) primitiveAtPut(void);
EXPORT(sqInt) primitiveDivFloatArray(void);
EXPORT(sqInt) primitiveDivScalar(void);
EXPORT(sqInt) primitiveDotProduct(void);
EXPORT(sqInt) primitiveEqual(void);
EXPORT(sqInt) primitiveHashArray(void);
EXPORT(sqInt) primitiveLength(void);
EXPORT(sqInt) primitiveMulFloatArray(void);
EXPORT(sqInt) primitiveMulScalar(void);
EXPORT(sqInt) primitiveNormalize(void);
EXPORT(sqInt) primitiveSubFloatArray(void);
EXPORT(sqInt) primitiveSubScalar(void);
EXPORT(sqInt) primitiveSum(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FloatArrayPlugin 30 December 2022 (i)"
#else
	"FloatArrayPlugin 30 December 2022 (e)"
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


/*	Primitive. Add the receiver and the argument, both FloatArrays and store the result into the receiver. */

EXPORT(sqInt) primitiveAddFloatArray(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(arg);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvr)));
	if (interpreterProxy->failed()) {
		return null;
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) + (((double) (argPtr[i]))));
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a FloatArray */

EXPORT(sqInt) primitiveAddScalar(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  value;

	value = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) + value);
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveAt(void) {
    float *floatPtr;
    double  floatValue;
    sqInt index;
    sqInt rcvr;

	index = interpreterProxy->stackIntegerValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	interpreterProxy->success((index > 0) && (index <= (interpreterProxy->slotSizeOf(rcvr))));
	if (interpreterProxy->failed()) {
		return null;
	}
	floatPtr = interpreterProxy->firstIndexableField(rcvr);
	floatValue = ((double) (floatPtr[index - 1]) );
	interpreterProxy->pop(2);
	interpreterProxy->pushFloat(floatValue);
	return null;
}

EXPORT(sqInt) primitiveAtPut(void) {
    float *floatPtr;
    double  floatValue;
    sqInt index;
    sqInt rcvr;
    sqInt value;

	value = interpreterProxy->stackValue(0);
	if ((value & 1)) {
		floatValue = ((double) ((value >> 1)) );
	} else {
		floatValue = interpreterProxy->floatValueOf(value);
	}
	index = interpreterProxy->stackIntegerValue(1);
	rcvr = interpreterProxy->stackObjectValue(2);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	interpreterProxy->success((index > 0) && (index <= (interpreterProxy->slotSizeOf(rcvr))));
	if (interpreterProxy->failed()) {
		return null;
	}
	floatPtr = interpreterProxy->firstIndexableField(rcvr);
	floatPtr[index - 1] = (((float) floatValue));
	if (!(interpreterProxy->failed())) {
		interpreterProxy->popthenPush(3, value);
	}
	return null;
}


/*	Primitive. Add the receiver and the argument, both FloatArrays and store the result into the receiver. */

EXPORT(sqInt) primitiveDivFloatArray(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(arg);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvr)));
	if (interpreterProxy->failed()) {
		return null;
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));

	/* Check if any of the argument's values is zero */

	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		if ((intAtPointer(((char*) (argPtr + i)))) == 0) {
			return interpreterProxy->primitiveFail();
		}
	}
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) / (((double) (argPtr[i]))));
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a FloatArray */

EXPORT(sqInt) primitiveDivScalar(void) {
    sqInt i;
    double  inverse;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  value;

	value = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (value == 0.0) {
		return interpreterProxy->primitiveFail();
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	inverse = 1.0 / value;
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * inverse);
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Compute the dot product of the receiver and the argument.
	The dot product is defined as the sum of the products of the individual elements. */

EXPORT(sqInt) primitiveDotProduct(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  result;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(arg);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvr)));
	if (interpreterProxy->failed()) {
		return null;
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	result = 0.0;
	for (i = 0; i <= (length - 1); i += 1) {
		result += (((double) (rcvrPtr[i]))) * (((double) (argPtr[i])));
	}
	interpreterProxy->pop(2);
	interpreterProxy->pushFloat(result);
	return null;
}

EXPORT(sqInt) primitiveEqual(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	length = interpreterProxy->stSizeOf(arg);
	if (!(length == (interpreterProxy->stSizeOf(rcvr)))) {
		return interpreterProxy->pushBool(0);
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((rcvrPtr[i]) == (argPtr[i]))) {
			return interpreterProxy->pushBool(0);
		}
	}
	return interpreterProxy->pushBool(1);
}

EXPORT(sqInt) primitiveHashArray(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    int *rcvrPtr;
    sqInt result;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((int *) (interpreterProxy->firstIndexableField(rcvr)));
	result = 0;
	for (i = 0; i <= (length - 1); i += 1) {
		result += rcvrPtr[i];
	}
	interpreterProxy->pop(1);
	return interpreterProxy->pushInteger(result & 0x1FFFFFFF);
}


/*	Primitive. Compute the length of the argument (sqrt of sum of component squares). */

EXPORT(sqInt) primitiveLength(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  result;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	interpreterProxy->success(1);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	result = 0.0;
	for (i = 0; i <= (length - 1); i += 1) {
		result += (((double) (rcvrPtr[i]))) * (((double) (rcvrPtr[i])));
	}
	result = sqrt(result);
	interpreterProxy->popthenPush(1, interpreterProxy->floatObjectOf(result));
	return null;
}


/*	Primitive. Add the receiver and the argument, both FloatArrays and store the result into the receiver. */

EXPORT(sqInt) primitiveMulFloatArray(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(arg);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvr)));
	if (interpreterProxy->failed()) {
		return null;
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * (((double) (argPtr[i]))));
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a FloatArray */

EXPORT(sqInt) primitiveMulScalar(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  value;

	value = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) * value);
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Normalize the argument (A FloatArray) in place. */

EXPORT(sqInt) primitiveNormalize(void) {
    sqInt i;
    double  len;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	interpreterProxy->success(1);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	len = 0.0;
	for (i = 0; i <= (length - 1); i += 1) {
		len += (((double) (rcvrPtr[i]))) * (((double) (rcvrPtr[i])));
	}
	interpreterProxy->success(len > 0.0);
	if (interpreterProxy->failed()) {
		return null;
	}
	len = sqrt(len);
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) / len);
	}
	return null;
}


/*	Primitive. Add the receiver and the argument, both FloatArrays and store the result into the receiver. */

EXPORT(sqInt) primitiveSubFloatArray(void) {
    sqInt arg;
    float *argPtr;
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;

	arg = interpreterProxy->stackObjectValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(arg));
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(arg);
	interpreterProxy->success(length == (interpreterProxy->stSizeOf(rcvr)));
	if (interpreterProxy->failed()) {
		return null;
	}
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	argPtr = ((float *) (interpreterProxy->firstIndexableField(arg)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) - (((double) (argPtr[i]))));
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Add the argument, a scalar value to the receiver, a FloatArray */

EXPORT(sqInt) primitiveSubScalar(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  value;

	value = interpreterProxy->stackFloatValue(0);
	rcvr = interpreterProxy->stackObjectValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	for (i = 0; i <= (length - 1); i += 1) {
		rcvrPtr[i] = ((((double) (rcvrPtr[i]))) - value);
	}
	interpreterProxy->pop(1);
	return null;
}


/*	Primitive. Find the sum of each float in the receiver, a FloatArray, and stash the result into the argument Float. */

EXPORT(sqInt) primitiveSum(void) {
    sqInt i;
    sqInt length;
    sqInt rcvr;
    float *rcvrPtr;
    double  sum;

	rcvr = interpreterProxy->stackObjectValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->isWords(rcvr));
	if (interpreterProxy->failed()) {
		return null;
	}
	length = interpreterProxy->stSizeOf(rcvr);
	rcvrPtr = ((float *) (interpreterProxy->firstIndexableField(rcvr)));
	sum = 0.0;
	for (i = 0; i <= (length - 1); i += 1) {
		sum += ((double) (rcvrPtr[i]));
	}
	interpreterProxy->popthenPush(1, interpreterProxy->floatObjectOf(sum));
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


void* FloatArrayPlugin_exports[][3] = {
	{"FloatArrayPlugin", "primitiveMulFloatArray", (void*)primitiveMulFloatArray},
	{"FloatArrayPlugin", "primitiveEqual", (void*)primitiveEqual},
	{"FloatArrayPlugin", "primitiveAtPut", (void*)primitiveAtPut},
	{"FloatArrayPlugin", "primitiveAt", (void*)primitiveAt},
	{"FloatArrayPlugin", "primitiveNormalize", (void*)primitiveNormalize},
	{"FloatArrayPlugin", "primitiveSubFloatArray", (void*)primitiveSubFloatArray},
	{"FloatArrayPlugin", "primitiveDivFloatArray", (void*)primitiveDivFloatArray},
	{"FloatArrayPlugin", "primitiveAddScalar", (void*)primitiveAddScalar},
	{"FloatArrayPlugin", "primitiveDotProduct", (void*)primitiveDotProduct},
	{"FloatArrayPlugin", "primitiveSubScalar", (void*)primitiveSubScalar},
	{"FloatArrayPlugin", "setInterpreter", (void*)setInterpreter},
	{"FloatArrayPlugin", "primitiveSum", (void*)primitiveSum},
	{"FloatArrayPlugin", "getModuleName", (void*)getModuleName},
	{"FloatArrayPlugin", "primitiveHashArray", (void*)primitiveHashArray},
	{"FloatArrayPlugin", "primitiveMulScalar", (void*)primitiveMulScalar},
	{"FloatArrayPlugin", "primitiveLength", (void*)primitiveLength},
	{"FloatArrayPlugin", "primitiveAddFloatArray", (void*)primitiveAddFloatArray},
	{"FloatArrayPlugin", "primitiveDivScalar", (void*)primitiveDivScalar},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

