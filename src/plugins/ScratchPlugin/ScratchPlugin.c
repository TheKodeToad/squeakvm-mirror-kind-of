/* Automatically generated from Squeak on 4 January 2013 12:29:07 am 
   by VMMaker 4.10.8
 */

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
#include "ScratchPlugin.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) primClose(void);
EXPORT(sqInt) primGetOption(void);
EXPORT(sqInt) primIsPortOpen(void);
EXPORT(sqInt) primOpenPortNamed(void);
EXPORT(sqInt) primPortCount(void);
EXPORT(sqInt) primPortName(void);
EXPORT(sqInt) primRead(void);
EXPORT(sqInt) primSetOption(void);
EXPORT(sqInt) primWrite(void);
EXPORT(sqInt) primitiveBlur(void);
EXPORT(sqInt) primitiveBrightnessShift(void);
EXPORT(sqInt) primitiveCondenseSound(void);
EXPORT(sqInt) primitiveDoubleSize(void);
EXPORT(sqInt) primitiveExtractChannel(void);
EXPORT(sqInt) primitiveFisheye(void);
EXPORT(sqInt) primitiveGetFolderPath(void);
EXPORT(sqInt) primitiveHalfSizeAverage(void);
EXPORT(sqInt) primitiveHalfSizeDiagonal(void);
EXPORT(sqInt) primitiveHueShift(void);
EXPORT(sqInt) primitiveInterpolate(void);
EXPORT(sqInt) primitiveIsHidden(void);
EXPORT(sqInt) primitiveOpenURL(void);
EXPORT(sqInt) primitiveSaturationShift(void);
EXPORT(sqInt) primitiveScale(void);
EXPORT(sqInt) primitiveSetUnicodePasteBuffer(void);
EXPORT(sqInt) primitiveSetWindowTitle(void);
EXPORT(sqInt) primitiveShortToLongPath(void);
EXPORT(sqInt) primitiveWaterRipples1(void);
EXPORT(sqInt) primitiveWhirl(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
#pragma export off
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"ScratchPlugin 4 January 2013 (i)"
#else
	"ScratchPlugin 4 January 2013 (e)"
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
}


/*	Close the given serial port. */

EXPORT(sqInt) primClose(void) {
    sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	SerialPortClose(portNum);
	interpreterProxy->pop(1);
	return 0;
}


/*	Return the given option value for the given serial port. */

EXPORT(sqInt) primGetOption(void) {
    sqInt attrNum;
    sqInt portNum;
    sqInt result;

	portNum = interpreterProxy->stackIntegerValue(1);
	attrNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = SerialPortGetOption(portNum, attrNum);
	if (result == -1) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(result);
	return 0;
}


/*	Answer the true if the given port is open. */

EXPORT(sqInt) primIsPortOpen(void) {
    sqInt portNum;
    sqInt result;

	portNum = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return 0;
	}
	result = SerialPortIsOpen(portNum);
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(result != 0);
	return 0;
}


/*	Open the port with the given name and baud rate. */

EXPORT(sqInt) primOpenPortNamed(void) {
    sqInt baudRate;
    sqInt count;
    sqInt i;
    sqInt nameOop;
    char nameStr[1000];
    sqInt portNum;
    char * src;

	nameOop = interpreterProxy->stackValue(1);
	baudRate = interpreterProxy->stackIntegerValue(0);
	if (((nameOop & 1)) || (!(interpreterProxy->isBytes(nameOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	if (interpreterProxy->failed()) {
		return 0;
	}
	src = ((char *) (interpreterProxy->firstIndexableField(nameOop)));
	count = interpreterProxy->stSizeOf(nameOop);
	for (i = 0; i <= (count - 1); i += 1) {
		nameStr[i] = (src[i]);
	}
	nameStr[count] = 0;
	portNum = SerialPortOpenPortNamed(nameStr, baudRate);
	if (portNum == -1) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->popthenPush(3, ((portNum << 1) | 1));
	return 0;
}


/*	Answer the number of serial ports. */

EXPORT(sqInt) primPortCount(void) {
    sqInt result;

	result = SerialPortCount();
	if (result == -1) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->popthenPush(1, ((result << 1) | 1));
	return 0;
}


/*	Get the name for the port with the given number. Fail if the port number is greater than the number of available ports. Port numbering starts with 1. */

EXPORT(sqInt) primPortName(void) {
    sqInt count;
    char* dst;
    sqInt i;
    char nameStr[1000];
    sqInt portIndex;
    sqInt resultOop;

	portIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return 0;
	}
	SerialPortName(portIndex, nameStr, 1000);
	count = strlen(nameStr);
	if (count == 0) {
		interpreterProxy->success(0);
		return 0;
	}
	resultOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), count);
	dst = ((char *) (interpreterProxy->firstIndexableField(resultOop)));
	for (i = 0; i <= (count - 1); i += 1) {
		dst[i] = (nameStr[i]);
	}
	interpreterProxy->popthenPush(2, resultOop);
	return 0;
}


/*	Read data from the given serial port into the given buffer (a ByteArray or String). Answer the number of bytes read. */

EXPORT(sqInt) primRead(void) {
    sqInt bufOop;
    char *bufPtr;
    sqInt bufSize;
    sqInt bytesRead;
    sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(1);
	bufOop = interpreterProxy->stackValue(0);
	if (((bufOop & 1)) || (!(interpreterProxy->isBytes(bufOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	bufPtr = ((char *) (interpreterProxy->firstIndexableField(bufOop)));
	bufSize = interpreterProxy->stSizeOf(bufOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	bytesRead = SerialPortRead(portNum, bufPtr, bufSize);
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(bytesRead);
	return 0;
}


/*	Return the given option value for the given serial port. */

EXPORT(sqInt) primSetOption(void) {
    sqInt attrNum;
    sqInt attrValue;
    sqInt portNum;
    sqInt result;

	portNum = interpreterProxy->stackIntegerValue(2);
	attrNum = interpreterProxy->stackIntegerValue(1);
	attrValue = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	result = SerialPortSetOption(portNum, attrNum, attrValue);
	if (result == -1) {
		interpreterProxy->success(0);
		return 0;
	}
	interpreterProxy->pop(3);
	return 0;
}


/*	Write data to the given serial port from the given buffer (a ByteArray or String). Answer the number of bytes written. */

EXPORT(sqInt) primWrite(void) {
    sqInt bufOop;
    char *bufPtr;
    sqInt bufSize;
    sqInt bytesWritten;
    sqInt portNum;

	portNum = interpreterProxy->stackIntegerValue(1);
	bufOop = interpreterProxy->stackValue(0);
	if (((bufOop & 1)) || (!(interpreterProxy->isBytes(bufOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	bufPtr = ((char *) (interpreterProxy->firstIndexableField(bufOop)));
	bufSize = interpreterProxy->stSizeOf(bufOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	bytesWritten = SerialPortWrite(portNum, bufPtr, bufSize);
	interpreterProxy->pop(3);
	interpreterProxy->pushInteger(bytesWritten);
	return 0;
}

EXPORT(sqInt) primitiveBlur(void) {
    sqInt bTotal;
    sqInt dX;
    sqInt dY;
    sqInt gTotal;
    sqInt height;
    unsigned int * in;
    sqInt inOop;
    sqInt n;
    unsigned int * out;
    sqInt outOop;
    sqInt outPix;
    sqInt pix;
    sqInt rTotal;
    sqInt sz;
    sqInt width;
    sqInt x;
    sqInt y;

	inOop = interpreterProxy->stackValue(2);
	outOop = interpreterProxy->stackValue(1);
	width = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	height = sz / width;
	for (y = 1; y <= (height - 2); y += 1) {
		for (x = 1; x <= (width - 2); x += 1) {
			n = (rTotal = (gTotal = (bTotal = 0)));
			for (dY = -1; dY <= 1; dY += 1) {
				for (dX = -1; dX <= 1; dX += 1) {

					/* add 1 when testing in Squeak */

					pix = (in[((y + dY) * width) + (x + dX)]) & 16777215;
					if (!(pix == 0)) {

						/* skip transparent pixels */

						rTotal += (((usqInt) pix >> 16)) & 255;
						gTotal += (((usqInt) pix >> 8)) & 255;
						bTotal += pix & 255;
						n += 1;
					}
				}
			}
			if (n == 0) {
				outPix = 0;
			} else {
				outPix = ((((usqInt) (rTotal / n) << 16)) + (((usqInt) (gTotal / n) << 8))) + (bTotal / n);
			}
			out[(y * width) + x] = outPix;
		}
	}
	interpreterProxy->pop(3);
	return 0;
}

EXPORT(sqInt) primitiveBrightnessShift(void) {
    sqInt b;
    sqInt brightness;
    sqInt g;
    sqInt hue;
    sqInt i;
    unsigned int * in;
    sqInt inOop;
    sqInt max;
    sqInt min;
    unsigned int * out;
    sqInt outOop;
    sqInt pix;
    sqInt r;
    sqInt saturation;
    sqInt shift;
    sqInt sz;
    sqInt result;
    sqInt span;
    sqInt hF;
    sqInt hI;
    sqInt outPix;
    sqInt p;
    sqInt q;
    sqInt t;
    sqInt v;

	inOop = interpreterProxy->stackValue(2);
	outOop = interpreterProxy->stackValue(1);
	shift = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l2;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l3;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l3:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (i = 0; i <= (sz - 1); i += 1) {
		pix = (in[i]) & 16777215;
		if (!(pix == 0)) {

			/* skip pixel values of 0 (transparent) */

			r = (((usqInt) pix >> 16)) & 255;
			g = (((usqInt) pix >> 8)) & 255;

			/* find min and max color components */

			b = pix & 255;
			max = (min = r);
			if (g > max) {
				max = g;
			}
			if (b > max) {
				max = b;
			}
			if (g < min) {
				min = g;
			}
			if (b < min) {
				min = b;
			}
			/* begin hueFromR:G:B:min:max: */
			span = max - min;
			if (span == 0) {
				hue = 0;
				goto l1;
			}
			if (r == max) {
				result = (60 * (g - b)) / span;
			} else {
				if (g == max) {
					result = 120 + ((60 * (b - r)) / span);
				} else {
					result = 240 + ((60 * (r - g)) / span);
				}
			}
			if (result < 0) {
				hue = result + 360;
				goto l1;
			}
			hue = result;
		l1:	/* end hueFromR:G:B:min:max: */;
			if (max == 0) {
				saturation = 0;
			} else {
				saturation = ((max - min) * 1000) / max;
			}

			/* compute new brigthness */

			brightness = (max * 1000) / 255;
			brightness += shift * 10;
			if (brightness > 1000) {
				brightness = 1000;
			}
			if (brightness < 0) {
				brightness = 0;
			}
			/* begin bitmap:at:putH:s:v: */
			hI = hue / 60;
			hF = hue % 60;
			p = (1000 - saturation) * brightness;
			q = (1000 - ((saturation * hF) / 60)) * brightness;
			t = (1000 - ((saturation * (60 - hF)) / 60)) * brightness;
			v = (brightness * 1000) / 3922;
			p = p / 3922;
			q = q / 3922;
			t = t / 3922;
			if (0 == hI) {
				outPix = ((((usqInt) v << 16)) + (((usqInt) t << 8))) + p;
			}
			if (1 == hI) {
				outPix = ((((usqInt) q << 16)) + (((usqInt) v << 8))) + p;
			}
			if (2 == hI) {
				outPix = ((((usqInt) p << 16)) + (((usqInt) v << 8))) + t;
			}
			if (3 == hI) {
				outPix = ((((usqInt) p << 16)) + (((usqInt) q << 8))) + v;
			}
			if (4 == hI) {
				outPix = ((((usqInt) t << 16)) + (((usqInt) p << 8))) + v;
			}
			if (5 == hI) {
				outPix = ((((usqInt) v << 16)) + (((usqInt) p << 8))) + q;
			}
			if (outPix == 0) {
				outPix = 1;
			}
			out[i] = outPix;
		}
	}
	interpreterProxy->pop(3);
	return 0;
}

EXPORT(sqInt) primitiveCondenseSound(void) {
    sqInt count;
    short *dst;
    sqInt dstOop;
    sqInt factor;
    sqInt i;
    sqInt j;
    sqInt max;
    short *src;
    sqInt srcOop;
    sqInt sz;
    sqInt v;

	srcOop = interpreterProxy->stackValue(2);
	dstOop = interpreterProxy->stackValue(1);
	factor = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success(interpreterProxy->isWords(srcOop));
	interpreterProxy->success(interpreterProxy->isWords(dstOop));
	count = (2 * (interpreterProxy->stSizeOf(srcOop))) / factor;
	sz = 2 * (interpreterProxy->stSizeOf(dstOop));
	interpreterProxy->success(sz >= count);
	if (interpreterProxy->failed()) {
		return null;
	}
	src = ((short *) (interpreterProxy->firstIndexableField(srcOop)));
	dst = ((short *) (interpreterProxy->firstIndexableField(dstOop)));
	for (i = 1; i <= count; i += 1) {
		max = 0;
		for (j = 1; j <= factor; j += 1) {
			v = *src++;
			if (v < 0) {
				v = 0 - v;
			}
			if (v > max) {
				max = v;
			}
		}
		*dst++ = max;
	}
	interpreterProxy->pop(3);
	return 0;
}

EXPORT(sqInt) primitiveDoubleSize(void) {
    sqInt baseIndex;
    sqInt dstX;
    sqInt dstY;
    sqInt i;
    unsigned int * in;
    sqInt inH;
    sqInt inOop;
    sqInt inW;
    unsigned int * out;
    sqInt outH;
    sqInt outOop;
    sqInt outW;
    sqInt pix;
    sqInt x;
    sqInt y;

	inOop = interpreterProxy->stackValue(7);
	inW = interpreterProxy->stackIntegerValue(6);
	inH = interpreterProxy->stackIntegerValue(5);
	outOop = interpreterProxy->stackValue(4);
	outW = interpreterProxy->stackIntegerValue(3);
	outH = interpreterProxy->stackIntegerValue(2);
	dstX = interpreterProxy->stackIntegerValue(1);
	dstY = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((dstX + (2 * inW)) < outW);
	interpreterProxy->success((dstY + (2 * inH)) < outH);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (y = 0; y <= (inH - 1); y += 1) {
		baseIndex = ((dstY + (2 * y)) * outW) + dstX;
		for (x = 0; x <= (inW - 1); x += 1) {
			pix = in[x + (y * inW)];
			i = baseIndex + (2 * x);
			out[i] = pix;
			out[i + 1] = pix;
			out[i + outW] = pix;
			out[(i + outW) + 1] = pix;
		}
	}
	interpreterProxy->pop(8);
	return 0;
}

EXPORT(sqInt) primitiveExtractChannel(void) {
    short *dst;
    sqInt dstOop;
    sqInt i;
    sqInt rightFlag;
    short *src;
    sqInt srcOop;
    sqInt sz;

	srcOop = interpreterProxy->stackValue(2);
	dstOop = interpreterProxy->stackValue(1);
	rightFlag = interpreterProxy->booleanValueOf(interpreterProxy->stackValue(0));
	interpreterProxy->success(interpreterProxy->isWords(srcOop));
	interpreterProxy->success(interpreterProxy->isWords(dstOop));
	sz = interpreterProxy->stSizeOf(srcOop);
	interpreterProxy->success((interpreterProxy->stSizeOf(dstOop)) >= (((sqInt) sz >> 1)));
	if (interpreterProxy->failed()) {
		return null;
	}
	src = ((short *) (interpreterProxy->firstIndexableField(srcOop)));
	dst = ((short *) (interpreterProxy->firstIndexableField(dstOop)));
	if (rightFlag) {
		src++;
	}
	for (i = 1; i <= sz; i += 1) {
		*dst++ = *src; src += 2;
	}
	interpreterProxy->pop(3);
	return 0;
}

EXPORT(sqInt) primitiveFisheye(void) {
    double ang;
    sqInt centerX;
    sqInt centerY;
    double dx;
    double dy;
    sqInt height;
    unsigned int * in;
    sqInt inOop;
    unsigned int * out;
    sqInt outOop;
    sqInt pix;
    sqInt power;
    double r;
    double scaledPower;
    sqInt srcX;
    sqInt srcY;
    sqInt sz;
    sqInt width;
    sqInt x;
    sqInt y;
    sqInt bottomPix;
    sqInt index;
    sqInt topPix;
    sqInt x1;
    sqInt xFrac;
    sqInt y1;
    sqInt yFrac;
    sqInt b;
    sqInt frac1;
    sqInt g;
    sqInt r1;
    sqInt result;
    sqInt b1;
    sqInt frac11;
    sqInt g1;
    sqInt r2;
    sqInt result1;
    sqInt b2;
    sqInt frac12;
    sqInt g2;
    sqInt r3;
    sqInt result2;

	inOop = interpreterProxy->stackValue(3);
	outOop = interpreterProxy->stackValue(2);
	width = interpreterProxy->stackIntegerValue(1);
	power = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l2;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l3;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l3:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	height = sz / width;
	centerX = ((sqInt) width >> 1);
	centerY = ((sqInt) height >> 1);
	height = sz / width;
	centerX = ((sqInt) width >> 1);
	centerY = ((sqInt) height >> 1);
	scaledPower = power / 100.0;
	for (x = 0; x <= (width - 1); x += 1) {
		for (y = 0; y <= (height - 1); y += 1) {
			dx = (x - centerX) / (((double) centerX ));
			dy = (y - centerY) / (((double) centerY ));
			r = pow((sqrt((dx * dx) + (dy * dy))),scaledPower);
			if (r <= 1.0) {
				ang = atan2(dy,dx);
				srcX = ((sqInt)(1024 * (centerX + ((r * (cos(ang))) * centerX))));
				srcY = ((sqInt)(1024 * (centerY + ((r * (sin(ang))) * centerY))));
			} else {
				srcX = 1024 * x;
				srcY = 1024 * y;
			}
			/* begin interpolatedFrom:x:y:width:height: */
			x1 = ((usqInt) srcX >> 10);
			if ((x1 < -1) || (x1 >= width)) {
				pix = 0;
				goto l1;
			}
			y1 = ((usqInt) srcY >> 10);
			if ((y1 < -1) || (y1 >= height)) {
				pix = 0;
				goto l1;
			}
			xFrac = srcX & 1023;
			if (x1 == -1) {
				x1 = 0;
				xFrac = 0;
			}
			if (x1 == (width - 1)) {
				xFrac = 0;
			}
			yFrac = srcY & 1023;
			if (y1 == -1) {
				y1 = 0;
				yFrac = 0;
			}
			if (y1 == (height - 1)) {
				yFrac = 0;
			}
			index = (y1 * width) + x1;
			topPix = (in[index]) & 16777215;
			if (xFrac > 0) {
				/* begin interpolate:and:frac: */
				if (topPix == 0) {
					topPix = (in[index + 1]) & 16777215;
					goto l4;
				}
				if (((in[index + 1]) & 16777215) == 0) {
					topPix = topPix;
					goto l4;
				}
				frac1 = 1024 - xFrac;
				r1 = ((sqInt) ((frac1 * ((((usqInt) topPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
				g = ((sqInt) ((frac1 * ((((usqInt) topPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
				b = ((sqInt) ((frac1 * (topPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
				result = ((((usqInt) r1 << 16)) + (((usqInt) g << 8))) + b;
				if (result == 0) {
					result = 1;
				}
				topPix = result;
			l4:	/* end interpolate:and:frac: */;
			}
			if (yFrac == 0) {
				pix = topPix;
				goto l1;
			}
			index = ((y1 + 1) * width) + x1;
			bottomPix = (in[index]) & 16777215;
			if (xFrac > 0) {
				/* begin interpolate:and:frac: */
				if (bottomPix == 0) {
					bottomPix = (in[index + 1]) & 16777215;
					goto l5;
				}
				if (((in[index + 1]) & 16777215) == 0) {
					bottomPix = bottomPix;
					goto l5;
				}
				frac11 = 1024 - xFrac;
				r2 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
				g1 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
				b1 = ((sqInt) ((frac11 * (bottomPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
				result1 = ((((usqInt) r2 << 16)) + (((usqInt) g1 << 8))) + b1;
				if (result1 == 0) {
					result1 = 1;
				}
				bottomPix = result1;
			l5:	/* end interpolate:and:frac: */;
			}
			/* begin interpolate:and:frac: */
			if (topPix == 0) {
				pix = bottomPix;
				goto l6;
			}
			if (bottomPix == 0) {
				pix = topPix;
				goto l6;
			}
			frac12 = 1024 - yFrac;
			r3 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 16)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 16)) & 255))) >> 10);
			g2 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 8)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 8)) & 255))) >> 10);
			b2 = ((sqInt) ((frac12 * (topPix & 255)) + (yFrac * (bottomPix & 255))) >> 10);
			result2 = ((((usqInt) r3 << 16)) + (((usqInt) g2 << 8))) + b2;
			if (result2 == 0) {
				result2 = 1;
			}
			pix = result2;
		l6:	/* end interpolate:and:frac: */;
		l1:	/* end interpolatedFrom:x:y:width:height: */;
			out[(y * width) + x] = pix;
		}
	}
	interpreterProxy->pop(4);
	return 0;
}


/*	Get the path for the special folder with given ID. Fail if the folder ID is out of range. */

EXPORT(sqInt) primitiveGetFolderPath(void) {
    sqInt count;
    char* dst;
    sqInt folderID;
    sqInt i;
    char nameStr[2000];
    sqInt resultOop;

	folderID = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return 0;
	}
	GetFolderPathForID(folderID, nameStr, 2000);
	count = strlen(nameStr);
	resultOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), count);
	dst = ((char *) (interpreterProxy->firstIndexableField(resultOop)));
	for (i = 0; i <= (count - 1); i += 1) {
		dst[i] = (nameStr[i]);
	}
	interpreterProxy->popthenPush(2, resultOop);
	return 0;
}

EXPORT(sqInt) primitiveHalfSizeAverage(void) {
    sqInt b;
    sqInt dstH;
    sqInt dstIndex;
    sqInt dstW;
    sqInt dstX;
    sqInt dstY;
    sqInt g;
    unsigned int * in;
    sqInt inH;
    sqInt inW;
    unsigned int * out;
    sqInt outH;
    sqInt outW;
    sqInt pixel;
    sqInt r;
    sqInt srcIndex;
    sqInt srcX;
    sqInt srcY;
    sqInt x;
    sqInt y;
    sqInt oop;
    sqInt oop1;

	/* begin checkedUnsignedIntPtrOf: */
	oop = interpreterProxy->stackValue(11);
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(oop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	inW = interpreterProxy->stackIntegerValue(10);
	inH = interpreterProxy->stackIntegerValue(9);
	/* begin checkedUnsignedIntPtrOf: */
	oop1 = interpreterProxy->stackValue(8);
	interpreterProxy->success(interpreterProxy->isWords(oop1));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(oop1)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	outW = interpreterProxy->stackIntegerValue(7);
	outH = interpreterProxy->stackIntegerValue(6);
	srcX = interpreterProxy->stackIntegerValue(5);
	srcY = interpreterProxy->stackIntegerValue(4);
	dstX = interpreterProxy->stackIntegerValue(3);
	dstY = interpreterProxy->stackIntegerValue(2);
	dstW = interpreterProxy->stackIntegerValue(1);
	dstH = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success((srcX >= 0) && (srcY >= 0));
	interpreterProxy->success((srcX + (2 * dstW)) <= inW);
	interpreterProxy->success((srcY + (2 * dstH)) <= inH);
	interpreterProxy->success((dstX >= 0) && (dstY >= 0));
	interpreterProxy->success((dstX + dstW) <= outW);
	interpreterProxy->success((dstY + dstH) <= outH);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (y = 0; y <= (dstH - 1); y += 1) {
		srcIndex = (inW * (srcY + (2 * y))) + srcX;
		dstIndex = (outW * (dstY + y)) + dstX;
		for (x = 0; x <= (dstW - 1); x += 1) {
			pixel = in[srcIndex];
			r = pixel & 16711680;
			g = pixel & 65280;
			b = pixel & 255;
			pixel = in[srcIndex + 1];
			r += pixel & 16711680;
			g += pixel & 65280;
			b += pixel & 255;
			pixel = in[srcIndex + inW];
			r += pixel & 16711680;
			g += pixel & 65280;
			b += pixel & 255;
			pixel = in[(srcIndex + inW) + 1];
			r += pixel & 16711680;
			g += pixel & 65280;

			/* store combined RGB into target bitmap */

			b += pixel & 255;
			out[dstIndex] = (((((usqInt) r >> 2)) & 16711680) | (((((usqInt) g >> 2)) & 65280) | (((usqInt) b >> 2))));
			srcIndex += 2;
			dstIndex += 1;
		}
	}
	interpreterProxy->pop(12);
	return 0;
}

EXPORT(sqInt) primitiveHalfSizeDiagonal(void) {
    sqInt b;
    sqInt dstH;
    sqInt dstIndex;
    sqInt dstW;
    sqInt dstX;
    sqInt dstY;
    sqInt g;
    unsigned int * in;
    sqInt inH;
    sqInt inW;
    unsigned int * out;
    sqInt outH;
    sqInt outW;
    sqInt p1;
    sqInt p2;
    sqInt r;
    sqInt srcIndex;
    sqInt srcX;
    sqInt srcY;
    sqInt x;
    sqInt y;
    sqInt oop;
    sqInt oop1;

	/* begin checkedUnsignedIntPtrOf: */
	oop = interpreterProxy->stackValue(11);
	interpreterProxy->success(interpreterProxy->isWords(oop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(oop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	inW = interpreterProxy->stackIntegerValue(10);
	inH = interpreterProxy->stackIntegerValue(9);
	/* begin checkedUnsignedIntPtrOf: */
	oop1 = interpreterProxy->stackValue(8);
	interpreterProxy->success(interpreterProxy->isWords(oop1));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(oop1)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	outW = interpreterProxy->stackIntegerValue(7);
	outH = interpreterProxy->stackIntegerValue(6);
	srcX = interpreterProxy->stackIntegerValue(5);
	srcY = interpreterProxy->stackIntegerValue(4);
	dstX = interpreterProxy->stackIntegerValue(3);
	dstY = interpreterProxy->stackIntegerValue(2);
	dstW = interpreterProxy->stackIntegerValue(1);
	dstH = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success((srcX >= 0) && (srcY >= 0));
	interpreterProxy->success((srcX + (2 * dstW)) <= inW);
	interpreterProxy->success((srcY + (2 * dstH)) <= inH);
	interpreterProxy->success((dstX >= 0) && (dstY >= 0));
	interpreterProxy->success((dstX + dstW) <= outW);
	interpreterProxy->success((dstY + dstH) <= outH);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (y = 0; y <= (dstH - 1); y += 1) {
		srcIndex = (inW * (srcY + (2 * y))) + srcX;
		dstIndex = (outW * (dstY + y)) + dstX;
		for (x = 0; x <= (dstW - 1); x += 1) {
			p1 = in[srcIndex];
			p2 = in[(srcIndex + inW) + 1];
			r = (((usqInt) ((p1 & 16711680) + (p2 & 16711680)) >> 1)) & 16711680;
			g = (((usqInt) ((p1 & 65280) + (p2 & 65280)) >> 1)) & 65280;

			/* store combined RGB into target bitmap */

			b = ((usqInt) ((p1 & 255) + (p2 & 255)) >> 1);
			out[dstIndex] = (r | (g | b));
			srcIndex += 2;
			dstIndex += 1;
		}
	}
	interpreterProxy->pop(12);
	return 0;
}

EXPORT(sqInt) primitiveHueShift(void) {
    sqInt b;
    sqInt brightness;
    sqInt g;
    sqInt hue;
    sqInt i;
    unsigned int * in;
    sqInt inOop;
    sqInt max;
    sqInt min;
    unsigned int * out;
    sqInt outOop;
    sqInt pix;
    sqInt r;
    sqInt saturation;
    sqInt shift;
    sqInt sz;
    sqInt result;
    sqInt span;
    sqInt hF;
    sqInt hI;
    sqInt outPix;
    sqInt p;
    sqInt q;
    sqInt t;
    sqInt v;

	inOop = interpreterProxy->stackValue(2);
	outOop = interpreterProxy->stackValue(1);
	shift = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l2;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l3;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l3:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (i = 0; i <= (sz - 1); i += 1) {
		pix = (in[i]) & 16777215;
		if (!(pix == 0)) {

			/* skip pixel values of 0 (transparent) */

			r = (((usqInt) pix >> 16)) & 255;
			g = (((usqInt) pix >> 8)) & 255;

			/* find min and max color components */

			b = pix & 255;
			max = (min = r);
			if (g > max) {
				max = g;
			}
			if (b > max) {
				max = b;
			}
			if (g < min) {
				min = g;
			}
			if (b < min) {
				min = b;
			}
			brightness = (max * 1000) / 255;
			if (max == 0) {
				saturation = 0;
			} else {
				saturation = ((max - min) * 1000) / max;
			}
			if (brightness < 110) {

				/* force black to a very dark, saturated gray */

				brightness = 110;
				saturation = 1000;
			}
			if (saturation < 90) {
				saturation = 90;
			}
			if ((brightness == 110) || (saturation == 90)) {

				/* tint all blacks and grays the same */

				hue = 0;
			} else {
				/* begin hueFromR:G:B:min:max: */
				span = max - min;
				if (span == 0) {
					hue = 0;
					goto l1;
				}
				if (r == max) {
					result = (60 * (g - b)) / span;
				} else {
					if (g == max) {
						result = 120 + ((60 * (b - r)) / span);
					} else {
						result = 240 + ((60 * (r - g)) / span);
					}
				}
				if (result < 0) {
					hue = result + 360;
					goto l1;
				}
				hue = result;
			l1:	/* end hueFromR:G:B:min:max: */;
			}

			/* compute new hue */

			hue = ((hue + shift) + 360000000) % 360;
			/* begin bitmap:at:putH:s:v: */
			hI = hue / 60;
			hF = hue % 60;
			p = (1000 - saturation) * brightness;
			q = (1000 - ((saturation * hF) / 60)) * brightness;
			t = (1000 - ((saturation * (60 - hF)) / 60)) * brightness;
			v = (brightness * 1000) / 3922;
			p = p / 3922;
			q = q / 3922;
			t = t / 3922;
			if (0 == hI) {
				outPix = ((((usqInt) v << 16)) + (((usqInt) t << 8))) + p;
			}
			if (1 == hI) {
				outPix = ((((usqInt) q << 16)) + (((usqInt) v << 8))) + p;
			}
			if (2 == hI) {
				outPix = ((((usqInt) p << 16)) + (((usqInt) v << 8))) + t;
			}
			if (3 == hI) {
				outPix = ((((usqInt) p << 16)) + (((usqInt) q << 8))) + v;
			}
			if (4 == hI) {
				outPix = ((((usqInt) t << 16)) + (((usqInt) p << 8))) + v;
			}
			if (5 == hI) {
				outPix = ((((usqInt) v << 16)) + (((usqInt) p << 8))) + q;
			}
			if (outPix == 0) {
				outPix = 1;
			}
			out[i] = outPix;
		}
	}
	interpreterProxy->pop(3);
	return 0;
}

EXPORT(sqInt) primitiveInterpolate(void) {
    unsigned int * in;
    sqInt inOop;
    sqInt result;
    sqInt sz;
    sqInt width;
    sqInt xFixed;
    sqInt yFixed;
    sqInt bottomPix;
    sqInt index;
    sqInt topPix;
    sqInt x;
    sqInt xFrac;
    sqInt y;
    sqInt yFrac;
    sqInt b;
    sqInt frac1;
    sqInt g;
    sqInt r;
    sqInt result1;
    sqInt b1;
    sqInt frac11;
    sqInt g1;
    sqInt r1;
    sqInt result2;
    sqInt b2;
    sqInt frac12;
    sqInt g2;
    sqInt r2;
    sqInt result3;

	inOop = interpreterProxy->stackValue(3);
	width = interpreterProxy->stackIntegerValue(2);
	xFixed = interpreterProxy->stackIntegerValue(1);
	yFixed = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	if (interpreterProxy->failed()) {
		return null;
	}
	/* begin interpolatedFrom:x:y:width:height: */
	x = ((usqInt) xFixed >> 10);
	if ((x < -1) || (x >= width)) {
		result = 0;
		goto l2;
	}
	y = ((usqInt) yFixed >> 10);
	if ((y < -1) || (y >= (sz / width))) {
		result = 0;
		goto l2;
	}
	xFrac = xFixed & 1023;
	if (x == -1) {
		x = 0;
		xFrac = 0;
	}
	if (x == (width - 1)) {
		xFrac = 0;
	}
	yFrac = yFixed & 1023;
	if (y == -1) {
		y = 0;
		yFrac = 0;
	}
	if (y == ((sz / width) - 1)) {
		yFrac = 0;
	}
	index = (y * width) + x;
	topPix = (in[index]) & 16777215;
	if (xFrac > 0) {
		/* begin interpolate:and:frac: */
		if (topPix == 0) {
			topPix = (in[index + 1]) & 16777215;
			goto l3;
		}
		if (((in[index + 1]) & 16777215) == 0) {
			topPix = topPix;
			goto l3;
		}
		frac1 = 1024 - xFrac;
		r = ((sqInt) ((frac1 * ((((usqInt) topPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
		g = ((sqInt) ((frac1 * ((((usqInt) topPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
		b = ((sqInt) ((frac1 * (topPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
		result1 = ((((usqInt) r << 16)) + (((usqInt) g << 8))) + b;
		if (result1 == 0) {
			result1 = 1;
		}
		topPix = result1;
	l3:	/* end interpolate:and:frac: */;
	}
	if (yFrac == 0) {
		result = topPix;
		goto l2;
	}
	index = ((y + 1) * width) + x;
	bottomPix = (in[index]) & 16777215;
	if (xFrac > 0) {
		/* begin interpolate:and:frac: */
		if (bottomPix == 0) {
			bottomPix = (in[index + 1]) & 16777215;
			goto l4;
		}
		if (((in[index + 1]) & 16777215) == 0) {
			bottomPix = bottomPix;
			goto l4;
		}
		frac11 = 1024 - xFrac;
		r1 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
		g1 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
		b1 = ((sqInt) ((frac11 * (bottomPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
		result2 = ((((usqInt) r1 << 16)) + (((usqInt) g1 << 8))) + b1;
		if (result2 == 0) {
			result2 = 1;
		}
		bottomPix = result2;
	l4:	/* end interpolate:and:frac: */;
	}
	/* begin interpolate:and:frac: */
	if (topPix == 0) {
		result = bottomPix;
		goto l5;
	}
	if (bottomPix == 0) {
		result = topPix;
		goto l5;
	}
	frac12 = 1024 - yFrac;
	r2 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 16)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 16)) & 255))) >> 10);
	g2 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 8)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 8)) & 255))) >> 10);
	b2 = ((sqInt) ((frac12 * (topPix & 255)) + (yFrac * (bottomPix & 255))) >> 10);
	result3 = ((((usqInt) r2 << 16)) + (((usqInt) g2 << 8))) + b2;
	if (result3 == 0) {
		result3 = 1;
	}
	result = result3;
l5:	/* end interpolate:and:frac: */;
l2:	/* end interpolatedFrom:x:y:width:height: */;
	interpreterProxy->pop(5);
	interpreterProxy->pushInteger(result);
	return 0;
}


/*	Answer true if the file or folder with the given path should be hidden from the user. On Windows, this is the value of the 'hidden' file property. */

EXPORT(sqInt) primitiveIsHidden(void) {
    sqInt count;
    char fullPath[1000];
    sqInt i;
    sqInt pathOop;
    sqInt result;
    char * src;

	pathOop = interpreterProxy->stackValue(0);
	if (((pathOop & 1)) || (!(interpreterProxy->isBytes(pathOop)))) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return 0;
	}
	src = ((char *) (interpreterProxy->firstIndexableField(pathOop)));
	count = interpreterProxy->stSizeOf(pathOop);
	if (count >= 1000) {
		interpreterProxy->success(0);
		return 0;
	}
	for (i = 0; i <= (count - 1); i += 1) {
		fullPath[i] = (src[i]);
	}
	fullPath[count] = 0;
	result = IsFileOrFolderHidden(fullPath);
	interpreterProxy->pop(2);
	interpreterProxy->pushBool(result != 0);
	return 0;
}


/*	Open a web browser on the given URL. */

EXPORT(sqInt) primitiveOpenURL(void) {
    sqInt count;
    sqInt i;
    char * src;
    sqInt urlOop;
    char urlStr[2000];

	urlOop = interpreterProxy->stackValue(0);
	if (((urlOop & 1)) || (!(interpreterProxy->isBytes(urlOop)))) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return 0;
	}
	src = ((char *) (interpreterProxy->firstIndexableField(urlOop)));
	count = interpreterProxy->stSizeOf(urlOop);
	if (count >= 2000) {
		interpreterProxy->success(0);
		return 0;
	}
	for (i = 0; i <= (count - 1); i += 1) {
		urlStr[i] = (src[i]);
	}
	urlStr[count] = 0;
	OpenURL(urlStr);
	interpreterProxy->pop(1);
	return 0;
}

EXPORT(sqInt) primitiveSaturationShift(void) {
    sqInt b;
    sqInt brightness;
    sqInt g;
    sqInt hue;
    sqInt i;
    unsigned int * in;
    sqInt inOop;
    sqInt max;
    sqInt min;
    unsigned int * out;
    sqInt outOop;
    sqInt pix;
    sqInt r;
    sqInt saturation;
    sqInt shift;
    sqInt sz;
    sqInt result;
    sqInt span;
    sqInt hF;
    sqInt hI;
    sqInt outPix;
    sqInt p;
    sqInt q;
    sqInt t;
    sqInt v;

	inOop = interpreterProxy->stackValue(2);
	outOop = interpreterProxy->stackValue(1);
	shift = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l2;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l3;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l3:	/* end checkedUnsignedIntPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	for (i = 0; i <= (sz - 1); i += 1) {
		pix = (in[i]) & 16777215;
		if (!(pix < 2)) {

			/* skip pixel values of 0 (transparent) and 1 (black) */

			r = (((usqInt) pix >> 16)) & 255;
			g = (((usqInt) pix >> 8)) & 255;

			/* find min and max color components */

			b = pix & 255;
			max = (min = r);
			if (g > max) {
				max = g;
			}
			if (b > max) {
				max = b;
			}
			if (g < min) {
				min = g;
			}
			if (b < min) {
				min = b;
			}
			brightness = (max * 1000) / 255;
			if (max == 0) {
				saturation = 0;
			} else {
				saturation = ((max - min) * 1000) / max;
			}
			if (saturation > 0) {

				/* do nothing if pixel is unsaturated (gray) */

				/* begin hueFromR:G:B:min:max: */
				span = max - min;
				if (span == 0) {
					hue = 0;
					goto l1;
				}
				if (r == max) {
					result = (60 * (g - b)) / span;
				} else {
					if (g == max) {
						result = 120 + ((60 * (b - r)) / span);
					} else {
						result = 240 + ((60 * (r - g)) / span);
					}
				}
				if (result < 0) {
					hue = result + 360;
					goto l1;
				}
				hue = result;
			l1:	/* end hueFromR:G:B:min:max: */;
				saturation += shift * 10;
				if (saturation > 1000) {
					saturation = 1000;
				}
				if (saturation < 0) {
					saturation = 0;
				}
				/* begin bitmap:at:putH:s:v: */
				hI = hue / 60;
				hF = hue % 60;
				p = (1000 - saturation) * brightness;
				q = (1000 - ((saturation * hF) / 60)) * brightness;
				t = (1000 - ((saturation * (60 - hF)) / 60)) * brightness;
				v = (brightness * 1000) / 3922;
				p = p / 3922;
				q = q / 3922;
				t = t / 3922;
				if (0 == hI) {
					outPix = ((((usqInt) v << 16)) + (((usqInt) t << 8))) + p;
				}
				if (1 == hI) {
					outPix = ((((usqInt) q << 16)) + (((usqInt) v << 8))) + p;
				}
				if (2 == hI) {
					outPix = ((((usqInt) p << 16)) + (((usqInt) v << 8))) + t;
				}
				if (3 == hI) {
					outPix = ((((usqInt) p << 16)) + (((usqInt) q << 8))) + v;
				}
				if (4 == hI) {
					outPix = ((((usqInt) t << 16)) + (((usqInt) p << 8))) + v;
				}
				if (5 == hI) {
					outPix = ((((usqInt) v << 16)) + (((usqInt) p << 8))) + q;
				}
				if (outPix == 0) {
					outPix = 1;
				}
				out[i] = outPix;
			}
		}
	}
	interpreterProxy->pop(3);
	return 0;
}


/*	Scale using bilinear interpolation. */

EXPORT(sqInt) primitiveScale(void) {
    unsigned int * in;
    sqInt inH;
    sqInt inOop;
    sqInt inW;
    sqInt inX;
    sqInt inY;
    unsigned int * out;
    sqInt outH;
    sqInt outOop;
    sqInt outPix;
    sqInt outW;
    sqInt outX;
    sqInt outY;
    sqInt p1;
    sqInt p2;
    sqInt p3;
    sqInt p4;
    sqInt t;
    sqInt tWeight;
    sqInt w1;
    sqInt w2;
    sqInt w3;
    sqInt w4;
    sqInt xIncr;
    sqInt yIncr;

	inOop = interpreterProxy->stackValue(5);
	inW = interpreterProxy->stackIntegerValue(4);
	inH = interpreterProxy->stackIntegerValue(3);
	outOop = interpreterProxy->stackValue(2);
	outW = interpreterProxy->stackIntegerValue(1);
	outH = interpreterProxy->stackIntegerValue(0);
	interpreterProxy->success((interpreterProxy->stSizeOf(inOop)) == (inW * inH));
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == (outW * outH));
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	if (interpreterProxy->failed()) {
		return null;
	}

	/* source x and y, scaled by 1024 */

	inX = (inY = 0);

	/* source x increment, scaled by 1024 */

	xIncr = (inW * 1024) / outW;

	/* source y increment, scaled by 1024 */

	yIncr = (inH * 1024) / outH;
	for (outY = 0; outY <= (outH - 1); outY += 1) {
		inX = 0;
		for (outX = 0; outX <= (outW - 1); outX += 1) {

			/* compute weights, scaled by 2^20 */

			w1 = (1024 - (inX & 1023)) * (1024 - (inY & 1023));
			w2 = (inX & 1023) * (1024 - (inY & 1023));
			w3 = (1024 - (inX & 1023)) * (inY & 1023);

			/* get source pixels */

			w4 = (inX & 1023) * (inY & 1023);
			t = ((((usqInt) inY) >> 10) * inW) + (((usqInt) inX) >> 10);
			p1 = in[t];
			if ((((usqInt) inX) >> 10) < (inW - 1)) {
				p2 = in[t + 1];
			} else {
				p2 = p1;
			}
			if ((((usqInt) inY) >> 10) < (inH - 1)) {
				t += inW;
			}
			p3 = in[t];
			if ((((usqInt) inX) >> 10) < (inW - 1)) {
				p4 = in[t + 1];
			} else {
				p4 = p3;
			}
			tWeight = 0;
			if (p1 == 0) {
				p1 = p2;
				tWeight += w1;
			}
			if (p2 == 0) {
				p2 = p1;
				tWeight += w2;
			}
			if (p3 == 0) {
				p3 = p4;
				tWeight += w3;
			}
			if (p4 == 0) {
				p4 = p3;
				tWeight += w4;
			}
			if (p1 == 0) {
				p1 = p3;
				p2 = p4;
			}
			if (p3 == 0) {
				p3 = p1;
				p4 = p2;
			}
			outPix = 0;
			if (tWeight < 500000) {

				/* compute an (opaque) output pixel if less than 50% transparent */

				t = (((w1 * ((((usqInt) p1) >> 16) & 255)) + (w2 * ((((usqInt) p2) >> 16) & 255))) + (w3 * ((((usqInt) p3) >> 16) & 255))) + (w4 * ((((usqInt) p4) >> 16) & 255));
				outPix = ((((usqInt) t) >> 20) & 255) << 16;
				t = (((w1 * ((((usqInt) p1) >> 8) & 255)) + (w2 * ((((usqInt) p2) >> 8) & 255))) + (w3 * ((((usqInt) p3) >> 8) & 255))) + (w4 * ((((usqInt) p4) >> 8) & 255));
				outPix = outPix | (((((usqInt) t) >> 20) & 255) << 8);
				t = (((w1 * (p1 & 255)) + (w2 * (p2 & 255))) + (w3 * (p3 & 255))) + (w4 * (p4 & 255));
				outPix = outPix | ((((usqInt) t) >> 20) & 255);
				if (outPix == 0) {
					outPix = 1;
				}
			}
			out[(outY * outW) + outX] = outPix;
			inX += xIncr;
		}
		inY += yIncr;
	}
	interpreterProxy->pop(6);
	return 0;
}


/*	Set the Mac OS X Unicode paste buffer. */

EXPORT(sqInt) primitiveSetUnicodePasteBuffer(void) {
    sqInt count;
    sqInt strOop;
    short int *utf16;

	strOop = interpreterProxy->stackValue(0);
	if (((strOop & 1)) || (!(interpreterProxy->isBytes(strOop)))) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return 0;
	}
	utf16 = ((short int *) (interpreterProxy->firstIndexableField(strOop)));
	count = interpreterProxy->stSizeOf(strOop);
	SetUnicodePasteBuffer(utf16, count);
	interpreterProxy->pop(1);
	return 0;
}


/*	Set the title of the Scratch window. */

EXPORT(sqInt) primitiveSetWindowTitle(void) {
    sqInt count;
    sqInt i;
    char * src;
    sqInt titleOop;
    char titleStr[1000];

	titleOop = interpreterProxy->stackValue(0);
	if (((titleOop & 1)) || (!(interpreterProxy->isBytes(titleOop)))) {
		interpreterProxy->success(0);
	}
	if (interpreterProxy->failed()) {
		return 0;
	}
	src = ((char *) (interpreterProxy->firstIndexableField(titleOop)));
	count = interpreterProxy->stSizeOf(titleOop);
	if (count >= 1000) {
		interpreterProxy->success(0);
		return 0;
	}
	for (i = 0; i <= (count - 1); i += 1) {
		titleStr[i] = (src[i]);
	}
	titleStr[count] = 0;
	SetScratchWindowTitle(titleStr);
	interpreterProxy->pop(1);
	return 0;
}


/*	On Windows, convert a short file/path name into a long one. Fail on other platforms. */

EXPORT(sqInt) primitiveShortToLongPath(void) {
    sqInt count;
    sqInt i;
    char longPath[1000];
    char * ptr;
    sqInt result;
    sqInt resultOop;
    char shortPath[1000];
    sqInt shortPathOop;

	shortPathOop = interpreterProxy->stackValue(0);
	if (((shortPathOop & 1)) || (!(interpreterProxy->isBytes(shortPathOop)))) {
		interpreterProxy->success(0);
		return 0;
	}
	ptr = ((char *) (interpreterProxy->firstIndexableField(shortPathOop)));
	count = interpreterProxy->stSizeOf(shortPathOop);
	if (count >= 1000) {
		interpreterProxy->success(0);
		return 0;
	}
	for (i = 0; i <= (count - 1); i += 1) {
		shortPath[i] = (ptr[i]);
	}
	shortPath[count] = 0;
	result = WinShortToLongPath(shortPath, longPath, 1000);
	if (result == -1) {
		interpreterProxy->success(0);
		return 0;
	}
	count = strlen(longPath);
	resultOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), count);
	ptr = ((char *) (interpreterProxy->firstIndexableField(resultOop)));
	for (i = 0; i <= (count - 1); i += 1) {
		ptr[i] = (longPath[i]);
	}
	interpreterProxy->popthenPush(2, resultOop);
	return 0;
}

EXPORT(sqInt) primitiveWaterRipples1(void) {
    sqInt aArOop;
    double * aArray;
    sqInt allPix;
    sqInt bArOop;
    double * bArray;
    sqInt blops;
    sqInt d;
    double dist;
    sqInt dx;
    double dx2;
    sqInt dy;
    double dy2;
    sqInt f;
    sqInt g;
    sqInt h;
    sqInt height;
    sqInt i;
    unsigned int * in;
    sqInt inOop;
    sqInt j;
    sqInt newLoc;
    unsigned int * out;
    sqInt outOop;
    unsigned int pix;
    sqInt power;
    sqInt q;
    int ripply;
    sqInt t;
    sqInt t1;
    double temp;
    sqInt val;
    sqInt val2;
    sqInt width;
    sqInt x;
    sqInt y;

	inOop = interpreterProxy->stackValue(5);
	outOop = interpreterProxy->stackValue(4);
	width = interpreterProxy->stackIntegerValue(3);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l1;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l1:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l2;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	allPix = interpreterProxy->stSizeOf(inOop);
	ripply = interpreterProxy->stackIntegerValue(2);
	aArOop = interpreterProxy->stackValue(1);
	bArOop = interpreterProxy->stackValue(0);
	/* begin checkedFloatPtrOf: */
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(aArOop));
	if (interpreterProxy->failed()) {
		aArray = 0;
		goto l3;
	}
	aArray = ((double *) (interpreterProxy->firstIndexableField(aArOop)));
l3:	/* end checkedFloatPtrOf: */;
	/* begin checkedFloatPtrOf: */
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(bArOop));
	if (interpreterProxy->failed()) {
		bArray = 0;
		goto l4;
	}
	bArray = ((double *) (interpreterProxy->firstIndexableField(bArOop)));
l4:	/* end checkedFloatPtrOf: */;
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == allPix);
	if (interpreterProxy->failed()) {
		return null;
	}
	height = allPix / width;
	t1 = rand();
	blops = (t1 % ripply) - 1;
	for (t = 0; t <= ((((sqInt) blops >> 1)) - 1); t += 1) {
		t1 = rand();
		x = t1 % width;
		t1 = rand();
		y = t1 % height;
		t1 = rand();
		power = t1 % 8;
		for (g = -4; g <= 4; g += 1) {
			for (h = -4; h <= 4; h += 1) {
				dist = ((double) ((g * g) + (h * h)) );
				if ((dist < 25) && (dist > 0)) {
					dx = ((sqInt)(x + g));
					dy = ((sqInt)(y + h));
					if ((dx > 0) && ((dy > 0) && ((dy < height) && (dx < width)))) {
						aArray[(dy * width) + dx] = (power * (((double) ((((double) 1.0 )) - (dist / (((double) 25.0 )))) )));
					}
				}
			}
		}
	}
	for (f = 1; f <= (width - 2); f += 1) {
		for (d = 1; d <= (height - 2); d += 1) {
			val = (d * width) + f;
			aArray[val] = ((((sqInt) ((((((((bArray[val + 1]) + (bArray[val - 1])) + (bArray[val + width])) + (bArray[val - width])) + (((sqInt) (bArray[(val - 1) - width]) >> 1))) + (((sqInt) (bArray[(val - 1) + width]) >> 1))) + (((sqInt) (bArray[(val + 1) - width]) >> 1))) + (((sqInt) (bArray[(val + 1) + width]) >> 1))) >> 2)) - (aArray[val]));
			aArray[val] = ((aArray[val]) * (((double) 0.9 )));
		}
	}
	for (q = 0; q <= (width * height); q += 1) {
		temp = bArray[q];
		bArray[q] = (aArray[q]);
		aArray[q] = temp;
	}
	for (j = 0; j <= (height - 1); j += 1) {
		for (i = 0; i <= (width - 1); i += 1) {
			if ((i > 1) && ((i < (width - 1)) && ((j > 1) && (j < (height - 1))))) {
				val2 = (j * width) + i;
				dx2 = ((double) ((((aArray[val2]) - (aArray[val2 - 1])) + ((aArray[val2 + 1]) - (aArray[val2]))) * 64) );
				dy2 = ((double) (((sqInt) (((aArray[val2]) - (aArray[val2 - width])) + ((aArray[val2 + width]) - (aArray[val2]))) >> 6)) );
				if (dx2 < -2) {
					dx2 = -2;
				}
				if (dx2 > 2) {
					dx2 = 2;
				}
				if (dy2 < -2) {
					dy2 = -2;
				}
				if (dy2 > 2) {
					dy2 = 2;
				}
				newLoc = ((sqInt)(((j + dy2) * width) + (i + dx2)));
				if ((newLoc < (width * height)) && (newLoc >= 0)) {
					pix = in[newLoc];
				} else {
					pix = in[i + (j * width)];
				}
			} else {
				pix = in[i + (j * width)];
			}
			out[i + (j * width)] = pix;
		}
	}
	interpreterProxy->pop(6);
	return 0;
}

EXPORT(sqInt) primitiveWhirl(void) {
    double ang;
    sqInt centerX;
    sqInt centerY;
    double cosa;
    double d;
    sqInt degrees;
    double dx;
    double dy;
    double factor;
    sqInt height;
    unsigned int * in;
    sqInt inOop;
    unsigned int * out;
    sqInt outOop;
    sqInt pix;
    sqInt radius;
    double radiusSquared;
    double scaleX;
    double scaleY;
    double sina;
    sqInt sz;
    double whirlRadians;
    sqInt width;
    sqInt x;
    sqInt y;
    sqInt bottomPix;
    sqInt index;
    sqInt topPix;
    sqInt x1;
    sqInt xFrac;
    sqInt y1;
    sqInt yFrac;
    sqInt b;
    sqInt frac1;
    sqInt g;
    sqInt r;
    sqInt result;
    sqInt b1;
    sqInt frac11;
    sqInt g1;
    sqInt r1;
    sqInt result1;
    sqInt b2;
    sqInt frac12;
    sqInt g2;
    sqInt r2;
    sqInt result2;

	inOop = interpreterProxy->stackValue(3);
	outOop = interpreterProxy->stackValue(2);
	width = interpreterProxy->stackIntegerValue(1);
	degrees = interpreterProxy->stackIntegerValue(0);
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(inOop));
	if (interpreterProxy->failed()) {
		in = 0;
		goto l2;
	}
	in = ((unsigned int *) (interpreterProxy->firstIndexableField(inOop)));
l2:	/* end checkedUnsignedIntPtrOf: */;
	/* begin checkedUnsignedIntPtrOf: */
	interpreterProxy->success(interpreterProxy->isWords(outOop));
	if (interpreterProxy->failed()) {
		out = 0;
		goto l3;
	}
	out = ((unsigned int *) (interpreterProxy->firstIndexableField(outOop)));
l3:	/* end checkedUnsignedIntPtrOf: */;
	sz = interpreterProxy->stSizeOf(inOop);
	interpreterProxy->success((interpreterProxy->stSizeOf(outOop)) == sz);
	if (interpreterProxy->failed()) {
		return null;
	}
	height = sz / width;
	centerX = ((sqInt) width >> 1);
	centerY = ((sqInt) height >> 1);
	if (centerX < centerY) {
		radius = centerX;
		scaleX = (((double) centerY )) / centerX;
		scaleY = 1.0;
	} else {
		radius = centerY;
		scaleX = 1.0;
		if (centerY < centerX) {
			scaleY = (((double) centerX )) / centerY;
		} else {
			scaleY = 1.0;
		}
	}
	whirlRadians = (-3.141592653589793 * degrees) / 180.0;
	radiusSquared = ((double) (radius * radius) );
	for (x = 0; x <= (width - 1); x += 1) {
		for (y = 0; y <= (height - 1); y += 1) {
			dx = scaleX * (((double) (x - centerX) ));
			dy = scaleY * (((double) (y - centerY) ));
			d = (dx * dx) + (dy * dy);
			if (d < radiusSquared) {

				/* inside the whirl circle */

				factor = 1.0 - ((sqrt(d)) / radius);
				ang = whirlRadians * (factor * factor);
				sina = sin(ang);
				cosa = cos(ang);
				/* begin interpolatedFrom:x:y:width:height: */
				x1 = ((usqInt) (((sqInt)(1024.0 * ((((cosa * dx) - (sina * dy)) / scaleX) + centerX)))) >> 10);
				if ((x1 < -1) || (x1 >= width)) {
					pix = 0;
					goto l1;
				}
				y1 = ((usqInt) (((sqInt)(1024.0 * ((((sina * dx) + (cosa * dy)) / scaleY) + centerY)))) >> 10);
				if ((y1 < -1) || (y1 >= height)) {
					pix = 0;
					goto l1;
				}
				xFrac = (((sqInt)(1024.0 * ((((cosa * dx) - (sina * dy)) / scaleX) + centerX)))) & 1023;
				if (x1 == -1) {
					x1 = 0;
					xFrac = 0;
				}
				if (x1 == (width - 1)) {
					xFrac = 0;
				}
				yFrac = (((sqInt)(1024.0 * ((((sina * dx) + (cosa * dy)) / scaleY) + centerY)))) & 1023;
				if (y1 == -1) {
					y1 = 0;
					yFrac = 0;
				}
				if (y1 == (height - 1)) {
					yFrac = 0;
				}
				index = (y1 * width) + x1;
				topPix = (in[index]) & 16777215;
				if (xFrac > 0) {
					/* begin interpolate:and:frac: */
					if (topPix == 0) {
						topPix = (in[index + 1]) & 16777215;
						goto l4;
					}
					if (((in[index + 1]) & 16777215) == 0) {
						topPix = topPix;
						goto l4;
					}
					frac1 = 1024 - xFrac;
					r = ((sqInt) ((frac1 * ((((usqInt) topPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
					g = ((sqInt) ((frac1 * ((((usqInt) topPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
					b = ((sqInt) ((frac1 * (topPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
					result = ((((usqInt) r << 16)) + (((usqInt) g << 8))) + b;
					if (result == 0) {
						result = 1;
					}
					topPix = result;
				l4:	/* end interpolate:and:frac: */;
				}
				if (yFrac == 0) {
					pix = topPix;
					goto l1;
				}
				index = ((y1 + 1) * width) + x1;
				bottomPix = (in[index]) & 16777215;
				if (xFrac > 0) {
					/* begin interpolate:and:frac: */
					if (bottomPix == 0) {
						bottomPix = (in[index + 1]) & 16777215;
						goto l5;
					}
					if (((in[index + 1]) & 16777215) == 0) {
						bottomPix = bottomPix;
						goto l5;
					}
					frac11 = 1024 - xFrac;
					r1 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 16)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 16)) & 255))) >> 10);
					g1 = ((sqInt) ((frac11 * ((((usqInt) bottomPix >> 8)) & 255)) + (xFrac * ((((usqInt) ((in[index + 1]) & 16777215) >> 8)) & 255))) >> 10);
					b1 = ((sqInt) ((frac11 * (bottomPix & 255)) + (xFrac * (((in[index + 1]) & 16777215) & 255))) >> 10);
					result1 = ((((usqInt) r1 << 16)) + (((usqInt) g1 << 8))) + b1;
					if (result1 == 0) {
						result1 = 1;
					}
					bottomPix = result1;
				l5:	/* end interpolate:and:frac: */;
				}
				/* begin interpolate:and:frac: */
				if (topPix == 0) {
					pix = bottomPix;
					goto l6;
				}
				if (bottomPix == 0) {
					pix = topPix;
					goto l6;
				}
				frac12 = 1024 - yFrac;
				r2 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 16)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 16)) & 255))) >> 10);
				g2 = ((sqInt) ((frac12 * ((((usqInt) topPix >> 8)) & 255)) + (yFrac * ((((usqInt) bottomPix >> 8)) & 255))) >> 10);
				b2 = ((sqInt) ((frac12 * (topPix & 255)) + (yFrac * (bottomPix & 255))) >> 10);
				result2 = ((((usqInt) r2 << 16)) + (((usqInt) g2 << 8))) + b2;
				if (result2 == 0) {
					result2 = 1;
				}
				pix = result2;
			l6:	/* end interpolate:and:frac: */;
			l1:	/* end interpolatedFrom:x:y:width:height: */;
				out[(width * y) + x] = pix;
			}
		}
	}
	interpreterProxy->pop(4);
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


void* ScratchPlugin_exports[][3] = {
	{"ScratchPlugin", "primitiveExtractChannel", (void*)primitiveExtractChannel},
	{"ScratchPlugin", "primGetOption", (void*)primGetOption},
	{"ScratchPlugin", "primClose", (void*)primClose},
	{"ScratchPlugin", "primitiveHalfSizeAverage", (void*)primitiveHalfSizeAverage},
	{"ScratchPlugin", "primitiveFisheye", (void*)primitiveFisheye},
	{"ScratchPlugin", "primitiveDoubleSize", (void*)primitiveDoubleSize},
	{"ScratchPlugin", "primitiveSaturationShift", (void*)primitiveSaturationShift},
	{"ScratchPlugin", "primitiveInterpolate", (void*)primitiveInterpolate},
	{"ScratchPlugin", "primIsPortOpen", (void*)primIsPortOpen},
	{"ScratchPlugin", "primWrite", (void*)primWrite},
	{"ScratchPlugin", "primPortName", (void*)primPortName},
	{"ScratchPlugin", "primPortCount", (void*)primPortCount},
	{"ScratchPlugin", "primitiveShortToLongPath", (void*)primitiveShortToLongPath},
	{"ScratchPlugin", "primitiveWaterRipples1", (void*)primitiveWaterRipples1},
	{"ScratchPlugin", "primitiveHueShift", (void*)primitiveHueShift},
	{"ScratchPlugin", "primitiveIsHidden", (void*)primitiveIsHidden},
	{"ScratchPlugin", "primitiveWhirl", (void*)primitiveWhirl},
	{"ScratchPlugin", "primitiveCondenseSound", (void*)primitiveCondenseSound},
	{"ScratchPlugin", "primOpenPortNamed", (void*)primOpenPortNamed},
	{"ScratchPlugin", "primitiveBrightnessShift", (void*)primitiveBrightnessShift},
	{"ScratchPlugin", "primitiveHalfSizeDiagonal", (void*)primitiveHalfSizeDiagonal},
	{"ScratchPlugin", "primitiveOpenURL", (void*)primitiveOpenURL},
	{"ScratchPlugin", "primitiveBlur", (void*)primitiveBlur},
	{"ScratchPlugin", "primitiveGetFolderPath", (void*)primitiveGetFolderPath},
	{"ScratchPlugin", "primitiveSetWindowTitle", (void*)primitiveSetWindowTitle},
	{"ScratchPlugin", "setInterpreter", (void*)setInterpreter},
	{"ScratchPlugin", "primRead", (void*)primRead},
	{"ScratchPlugin", "getModuleName", (void*)getModuleName},
	{"ScratchPlugin", "primitiveScale", (void*)primitiveScale},
	{"ScratchPlugin", "primitiveSetUnicodePasteBuffer", (void*)primitiveSetUnicodePasteBuffer},
	{"ScratchPlugin", "primSetOption", (void*)primSetOption},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */

