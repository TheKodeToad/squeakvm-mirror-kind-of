/* Smalltalk from Squeak4.5 with VMMaker 4.15.7 translated as C source on 9 July 2016 12:04:23 pm */
/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-dtl.384 uuid: 53635f21-7aaa-454b-bbfc-9fc2b67fb70b
   from
	JPEGReadWriter2Plugin VMMaker-dtl.384 uuid: 53635f21-7aaa-454b-bbfc-9fc2b67fb70b
 */
static char __buildInfo[] = "JPEGReadWriter2Plugin VMMaker-dtl.384 uuid: 53635f21-7aaa-454b-bbfc-9fc2b67fb70b " __DATE__ ;




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
#include "JPEGReadWriter2Plugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primImageHeight(void);
EXPORT(sqInt) primImageNumComponents(void);
EXPORT(sqInt) primImageWidth(void);
EXPORT(sqInt) primJPEGCompressStructSize(void);
EXPORT(sqInt) primJPEGDecompressStructSize(void);
EXPORT(sqInt) primJPEGErrorMgr2StructSize(void);
EXPORT(sqInt) primJPEGPluginIsPresent(void);
EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void);
EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void);
EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void);
EXPORT(sqInt) primSupports8BitGrayscaleJPEGs(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"JPEGReadWriter2Plugin 9 July 2016 (i)"
#else
	"JPEGReadWriter2Plugin 9 July 2016 (e)"
#endif
;
static sqInt simulator;



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

EXPORT(sqInt) initialiseModule(void) {
	return 1;
}

EXPORT(sqInt) primImageHeight(void) {
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	;
	_return_value = interpreterProxy->integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_height));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primImageNumComponents(void) {
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	;
	_return_value = interpreterProxy->integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->num_components));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primImageWidth(void) {
	char *aJPEGDecompressStruct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	
		interpreterProxy->success
			((interpreterProxy->stSizeOf(interpreterProxy->stackValue(0))) >= (sizeof(struct jpeg_decompress_struct))); 
		if (interpreterProxy->failed()) return null;
	;
	_return_value = interpreterProxy->integerObjectOf((((j_decompress_ptr)aJPEGDecompressStruct)->image_width));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGCompressStructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct jpeg_compress_struct)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGDecompressStructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct jpeg_decompress_struct)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGErrorMgr2StructSize(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sizeof(struct error_mgr2)));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGPluginIsPresent(void) {
	sqInt _return_value;

	_return_value = (1? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primJPEGReadHeaderfromByteArrayerrorMgr(void) {
	sqInt sourceSize;
	char *aJPEGDecompressStruct;
	char *source;
	char *aJPEGErrorMgr2Struct;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(2)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(2))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	source = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(2)) >= (sizeof(struct jpeg_decompress_struct)));
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(0)) >= (sizeof(struct error_mgr2)));
	if (interpreterProxy->failed()) {
		return null;
	}
	sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(1));
	if (sourceSize > 0) {
		primJPEGReadHeaderfromByteArraysizeerrorMgrReadHeader(aJPEGDecompressStruct, source, sourceSize, aJPEGErrorMgr2Struct);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr(void) {
	sqInt formWidth;
	sqInt formBitmapOOP;
	sqInt formComponents;
	sqInt formDepth;
	sqInt formNativeDepth;
	sqInt pixelsPerWord;
	sqInt formPitch;
	sqInt formBitmapSizeInBytes;
	sqInt formHeight;
	sqInt sourceSize;
	sqInt wordsPerRow;
	unsigned int*formBitmap;
	sqInt formComponentBitSize;
	char *aJPEGDecompressStruct;
	char *source;
	sqInt form;
	sqInt ditherFlag;
	char *aJPEGErrorMgr2Struct;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(4)));
	aJPEGDecompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(4))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(3)));
	source = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(2), "Form"));
	form = interpreterProxy->stackValue(2);
	ditherFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	formBitmapOOP = interpreterProxy->fetchPointerofObject(0, form);
	formNativeDepth = interpreterProxy->fetchIntegerofObject(3, form);
	formWidth = interpreterProxy->fetchIntegerofObject(1, form);
	formHeight = interpreterProxy->fetchIntegerofObject(2, form);

	/* Various parameter checks */

	formDepth = abs(formNativeDepth);
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(4)) >= (sizeof(struct jpeg_decompress_struct)));
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(0)) >= (sizeof(struct error_mgr2)));
	if (interpreterProxy->failed()) {
		return null;
	}
	formComponents = (formDepth != 8
		? 4
		: 1);
	formComponentBitSize = (formDepth != 16
		? 8
		: 4);
	pixelsPerWord = 32 / (formComponents * formComponentBitSize);
	wordsPerRow = ((formWidth + pixelsPerWord) - 1) / pixelsPerWord;
	formPitch = ((formWidth + (pixelsPerWord - 1)) / pixelsPerWord) * 4;
	formBitmapSizeInBytes = interpreterProxy->byteSizeOf(formBitmapOOP);
	interpreterProxy->success((interpreterProxy->isWordsOrBytes(formBitmapOOP)) && (formBitmapSizeInBytes >= (formPitch * formHeight)));
	if (interpreterProxy->failed()) {
		return null;
	}
	sourceSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(3));
	interpreterProxy->success(sourceSize != 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	formBitmap = interpreterProxy->firstIndexableField(formBitmapOOP);
	primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgrReadScanlines(
			aJPEGDecompressStruct,
    			aJPEGErrorMgr2Struct,
			source,
    			sourceSize,
    			ditherFlag,
    			formBitmap,
   			pixelsPerWord,
   			wordsPerRow,
    			formNativeDepth);;
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(5);
	return null;
}

EXPORT(sqInt) primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr(void) {
	sqInt formWidth;
	unsigned int destinationSize;
	sqInt formBitmapOOP;
	sqInt formComponents;
	sqInt formNativeDepth;
	sqInt formDepth;
	sqInt pixelsPerWord;
	sqInt formPitch;
	sqInt formBitmapSizeInBytes;
	sqInt formHeight;
	sqInt wordsPerRow;
	unsigned int *formBitmap;
	sqInt formComponentBitSize;
	char *aJPEGCompressStruct;
	char *destination;
	sqInt form;
	sqInt quality;
	sqInt progressiveFlag;
	char *aJPEGErrorMgr2Struct;
	sqInt _return_value;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(5)));
	aJPEGCompressStruct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(5))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(4)));
	destination = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(4))));
	interpreterProxy->success(interpreterProxy->isKindOf(interpreterProxy->stackValue(3), "Form"));
	form = interpreterProxy->stackValue(3);
	quality = interpreterProxy->stackIntegerValue(2);
	progressiveFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(1));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	aJPEGErrorMgr2Struct = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	formBitmapOOP = interpreterProxy->fetchPointerofObject(0, form);
	formWidth = interpreterProxy->fetchIntegerofObject(1, form);
	formHeight = interpreterProxy->fetchIntegerofObject(2, form);
	formNativeDepth = interpreterProxy->fetchIntegerofObject(3, form);

	/* Various parameter checks */

	formDepth = abs(formNativeDepth);
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(5)) >= (sizeof(struct jpeg_compress_struct)));
	interpreterProxy->success(interpreterProxy->stSizeOf(interpreterProxy->stackValue(0)) >= (sizeof(struct error_mgr2)));
	if (interpreterProxy->failed()) {
		return null;
	}
	formComponents = (formDepth != 8
		? 4
		: 1);
	formComponentBitSize = (formDepth != 16
		? 8
		: 4);
	pixelsPerWord = 32 / (formComponents * formComponentBitSize);
	wordsPerRow = ((formWidth + pixelsPerWord) - 1) / pixelsPerWord;
	formPitch = wordsPerRow * 4;
	formBitmapSizeInBytes = interpreterProxy->byteSizeOf(formBitmapOOP);
	interpreterProxy->success((interpreterProxy->isWordsOrBytes(formBitmapOOP)) && (formBitmapSizeInBytes >= (formPitch * formHeight)));
	if (interpreterProxy->failed()) {
		return null;
	}
	formBitmap = interpreterProxy->firstIndexableField(formBitmapOOP);
	destinationSize = interpreterProxy->stSizeOf(interpreterProxy->stackValue(4));
	if (!(destinationSize == 0)) {
		 primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgrWriteScanlines(
				formWidth, 
				formHeight, 
				formNativeDepth, 
				formBitmap, 
				aJPEGCompressStruct,
				aJPEGErrorMgr2Struct,
				quality,
				progressiveFlag,
				pixelsPerWord, 
				wordsPerRow, 
				destination,
				&destinationSize);;
	}
	_return_value = interpreterProxy->integerObjectOf((destinationSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(7, _return_value);
	return null;
}

EXPORT(sqInt) primSupports8BitGrayscaleJPEGs(void) {
	sqInt _return_value;

	_return_value = (1? interpreterProxy->trueObject(): interpreterProxy->falseObject());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
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

EXPORT(sqInt) shutdownModule(void) {
	return 1;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* JPEGReadWriter2Plugin_exports[][3] = {
	{"JPEGReadWriter2Plugin", "primImageWidth", (void*)primImageWidth},
	{"JPEGReadWriter2Plugin", "getModuleName", (void*)getModuleName},
	{"JPEGReadWriter2Plugin", "primImageNumComponents", (void*)primImageNumComponents},
	{"JPEGReadWriter2Plugin", "primJPEGCompressStructSize", (void*)primJPEGCompressStructSize},
	{"JPEGReadWriter2Plugin", "primJPEGErrorMgr2StructSize", (void*)primJPEGErrorMgr2StructSize},
	{"JPEGReadWriter2Plugin", "primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr", (void*)primJPEGWriteImageonByteArrayformqualityprogressiveJPEGerrorMgr},
	{"JPEGReadWriter2Plugin", "setInterpreter", (void*)setInterpreter},
	{"JPEGReadWriter2Plugin", "primSupports8BitGrayscaleJPEGs", (void*)primSupports8BitGrayscaleJPEGs},
	{"JPEGReadWriter2Plugin", "primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr", (void*)primJPEGReadImagefromByteArrayonFormdoDitheringerrorMgr},
	{"JPEGReadWriter2Plugin", "primImageHeight", (void*)primImageHeight},
	{"JPEGReadWriter2Plugin", "primJPEGReadHeaderfromByteArrayerrorMgr", (void*)primJPEGReadHeaderfromByteArrayerrorMgr},
	{"JPEGReadWriter2Plugin", "primJPEGPluginIsPresent", (void*)primJPEGPluginIsPresent},
	{"JPEGReadWriter2Plugin", "shutdownModule", (void*)shutdownModule},
	{"JPEGReadWriter2Plugin", "initialiseModule", (void*)initialiseModule},
	{"JPEGReadWriter2Plugin", "primJPEGDecompressStructSize", (void*)primJPEGDecompressStructSize},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

