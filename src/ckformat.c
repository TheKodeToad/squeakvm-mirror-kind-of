/* ckformat: Print the image format number on standard output */
/* for use in a shell script to test image format requirements. */
/* A non-zero return status code indicates failure. */

/* Usage: ckformat imageFileName */

/* --- DO NOT EDIT THIS FILE --- */
/* --- Automatically generated from class ImageFormat 2020-07-26T19:59:19.492+01:00--- */
/* --- Source code is in package ImageFormat in the VMMaker repository --- */
/* --- DO NOT EDIT THIS FILE --- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *f;
	unsigned char buf[8];
	int formatNumber;
	unsigned char c;
	int match;
	if (argc != 2) {
		printf("usage: ckformat imageFileName\n");
		printf("answer the image format number for an image file or 0 if not known\n");
		printf("known image formats:\n");
		printf("6502: a 32-bit V3 image with no closure support and no native platform float word order requirement\n");
		printf("6504: a 32-bit V3 image with closure support and no native platform float word order requirement\n");
		printf("6505: a 32-bit V3 image with closure support and float words stored in native platform order\n");
		printf("6521: a 32-bit Spur image with closure support and float words stored in native platform order using Spur object format\n");
		printf("7033: a 32-bit Spur image with closure support and float words stored in native platform order using Spur object format and multiple bytecode sets \n");
		printf("68000: a 64-bit V3 image with no closure support and no native platform float word order requirement\n");
		printf("68002: a 64-bit V3 image with closure support and no native platform float word order requirement\n");
		printf("68003: a 64-bit V3 image with closure support and float words stored in native platform order\n");
		printf("68004: a 64-bit V3 image with closure support and no native platform float word order requirement\n");
		printf("68019: a 64-bit Spur image with closure support and float words stored in native platform order using Spur object format (obsolete)\n");
		printf("68021: a 64-bit Spur image with closure support and float words stored in native platform order using Spur object format\n");
		printf("68533: a 64-bit Spur image with closure support and float words stored in native platform order using Spur object format and multiple bytecode sets \n");
		exit(1);
	}
	f = fopen(argv[1], "r");
	if (f == NULL) {
		perror(argv[1]);
		exit(2);
	}
	if(fseek(f, 0L, SEEK_SET) != 0) {
		fprintf(stderr, "cannot go to pos %d in %s\n", 0, argv[1]);
		exit(3);
	}
	if (fread(buf, 1, 8, f) < 8) {
		fprintf(stderr, "cannot read %s\n", argv[1]);
		exit(3);
	}
	{
	unsigned char b_6502_1[4]= { 0, 0, 25, 102};
	if (memcmp(buf, b_6502_1, 4) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_2[8]= { 0, 0, 0, 0, 0, 0, 25, 102};
	if (memcmp(buf, b_6502_2, 8) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_3[4]= { 102, 25, 0, 0};
	if (memcmp(buf, b_6502_3, 4) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_4[8]= { 102, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6502_4, 8) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6504_5[4]= { 0, 0, 25, 104};
	if (memcmp(buf, b_6504_5, 4) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_6[8]= { 0, 0, 0, 0, 0, 0, 25, 104};
	if (memcmp(buf, b_6504_6, 8) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_7[4]= { 104, 25, 0, 0};
	if (memcmp(buf, b_6504_7, 4) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_8[8]= { 104, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6504_8, 8) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6505_9[4]= { 0, 0, 25, 105};
	if (memcmp(buf, b_6505_9, 4) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_10[8]= { 0, 0, 0, 0, 0, 0, 25, 105};
	if (memcmp(buf, b_6505_10, 8) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_11[4]= { 105, 25, 0, 0};
	if (memcmp(buf, b_6505_11, 4) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_12[8]= { 105, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6505_12, 8) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6521_13[4]= { 0, 0, 25, 121};
	if (memcmp(buf, b_6521_13, 4) == 0) {
		printf("%d\n", 6521);
		exit(0);
	}
	}
	{
	unsigned char b_6521_14[4]= { 121, 25, 0, 0};
	if (memcmp(buf, b_6521_14, 4) == 0) {
		printf("%d\n", 6521);
		exit(0);
	}
	}
	{
	unsigned char b_7033_15[4]= { 0, 0, 27, 121};
	if (memcmp(buf, b_7033_15, 4) == 0) {
		printf("%d\n", 7033);
		exit(0);
	}
	}
	{
	unsigned char b_7033_16[4]= { 121, 27, 0, 0};
	if (memcmp(buf, b_7033_16, 4) == 0) {
		printf("%d\n", 7033);
		exit(0);
	}
	}
	{
	unsigned char b_68000_17[4]= { 0, 1, 9, 160};
	if (memcmp(buf, b_68000_17, 4) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_18[8]= { 0, 0, 0, 0, 0, 1, 9, 160};
	if (memcmp(buf, b_68000_18, 8) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_19[4]= { 160, 9, 1, 0};
	if (memcmp(buf, b_68000_19, 4) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_20[8]= { 160, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68000_20, 8) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68002_21[4]= { 0, 1, 9, 162};
	if (memcmp(buf, b_68002_21, 4) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_22[8]= { 0, 0, 0, 0, 0, 1, 9, 162};
	if (memcmp(buf, b_68002_22, 8) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_23[4]= { 162, 9, 1, 0};
	if (memcmp(buf, b_68002_23, 4) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_24[8]= { 162, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68002_24, 8) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68003_25[4]= { 0, 1, 9, 163};
	if (memcmp(buf, b_68003_25, 4) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_26[8]= { 0, 0, 0, 0, 0, 1, 9, 163};
	if (memcmp(buf, b_68003_26, 8) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_27[4]= { 163, 9, 1, 0};
	if (memcmp(buf, b_68003_27, 4) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_28[8]= { 163, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68003_28, 8) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68004_29[4]= { 0, 1, 9, 164};
	if (memcmp(buf, b_68004_29, 4) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_30[8]= { 0, 0, 0, 0, 0, 1, 9, 164};
	if (memcmp(buf, b_68004_30, 8) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_31[4]= { 164, 9, 1, 0};
	if (memcmp(buf, b_68004_31, 4) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_32[8]= { 164, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68004_32, 8) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68019_33[4]= { 0, 1, 9, 179};
	if (memcmp(buf, b_68019_33, 4) == 0) {
		printf("%d\n", 68019);
		exit(0);
	}
	}
	{
	unsigned char b_68019_34[4]= { 179, 9, 1, 0};
	if (memcmp(buf, b_68019_34, 4) == 0) {
		printf("%d\n", 68019);
		exit(0);
	}
	}
	{
	unsigned char b_68021_35[4]= { 0, 1, 9, 181};
	if (memcmp(buf, b_68021_35, 4) == 0) {
		printf("%d\n", 68021);
		exit(0);
	}
	}
	{
	unsigned char b_68021_36[4]= { 181, 9, 1, 0};
	if (memcmp(buf, b_68021_36, 4) == 0) {
		printf("%d\n", 68021);
		exit(0);
	}
	}
	{
	unsigned char b_68533_37[4]= { 0, 1, 11, 181};
	if (memcmp(buf, b_68533_37, 4) == 0) {
		printf("%d\n", 68533);
		exit(0);
	}
	}
	{
	unsigned char b_68533_38[4]= { 181, 11, 1, 0};
	if (memcmp(buf, b_68533_38, 4) == 0) {
		printf("%d\n", 68533);
		exit(0);
	}
	}
	if(fseek(f, 512L, SEEK_SET) != 0) {
		fprintf(stderr, "cannot go to pos %d in %s\n", 512, argv[1]);
		exit(3);
	}
	if (fread(buf, 1, 8, f) < 8) {
		fprintf(stderr, "cannot read %s\n", argv[1]);
		exit(3);
	}
	{
	unsigned char b_6502_1[4]= { 0, 0, 25, 102};
	if (memcmp(buf, b_6502_1, 4) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_2[8]= { 0, 0, 0, 0, 0, 0, 25, 102};
	if (memcmp(buf, b_6502_2, 8) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_3[4]= { 102, 25, 0, 0};
	if (memcmp(buf, b_6502_3, 4) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6502_4[8]= { 102, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6502_4, 8) == 0) {
		printf("%d\n", 6502);
		exit(0);
	}
	}
	{
	unsigned char b_6504_5[4]= { 0, 0, 25, 104};
	if (memcmp(buf, b_6504_5, 4) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_6[8]= { 0, 0, 0, 0, 0, 0, 25, 104};
	if (memcmp(buf, b_6504_6, 8) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_7[4]= { 104, 25, 0, 0};
	if (memcmp(buf, b_6504_7, 4) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6504_8[8]= { 104, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6504_8, 8) == 0) {
		printf("%d\n", 6504);
		exit(0);
	}
	}
	{
	unsigned char b_6505_9[4]= { 0, 0, 25, 105};
	if (memcmp(buf, b_6505_9, 4) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_10[8]= { 0, 0, 0, 0, 0, 0, 25, 105};
	if (memcmp(buf, b_6505_10, 8) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_11[4]= { 105, 25, 0, 0};
	if (memcmp(buf, b_6505_11, 4) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6505_12[8]= { 105, 25, 0, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_6505_12, 8) == 0) {
		printf("%d\n", 6505);
		exit(0);
	}
	}
	{
	unsigned char b_6521_13[4]= { 0, 0, 25, 121};
	if (memcmp(buf, b_6521_13, 4) == 0) {
		printf("%d\n", 6521);
		exit(0);
	}
	}
	{
	unsigned char b_6521_14[4]= { 121, 25, 0, 0};
	if (memcmp(buf, b_6521_14, 4) == 0) {
		printf("%d\n", 6521);
		exit(0);
	}
	}
	{
	unsigned char b_7033_15[4]= { 0, 0, 27, 121};
	if (memcmp(buf, b_7033_15, 4) == 0) {
		printf("%d\n", 7033);
		exit(0);
	}
	}
	{
	unsigned char b_7033_16[4]= { 121, 27, 0, 0};
	if (memcmp(buf, b_7033_16, 4) == 0) {
		printf("%d\n", 7033);
		exit(0);
	}
	}
	{
	unsigned char b_68000_17[4]= { 0, 1, 9, 160};
	if (memcmp(buf, b_68000_17, 4) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_18[8]= { 0, 0, 0, 0, 0, 1, 9, 160};
	if (memcmp(buf, b_68000_18, 8) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_19[4]= { 160, 9, 1, 0};
	if (memcmp(buf, b_68000_19, 4) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68000_20[8]= { 160, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68000_20, 8) == 0) {
		printf("%d\n", 68000);
		exit(0);
	}
	}
	{
	unsigned char b_68002_21[4]= { 0, 1, 9, 162};
	if (memcmp(buf, b_68002_21, 4) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_22[8]= { 0, 0, 0, 0, 0, 1, 9, 162};
	if (memcmp(buf, b_68002_22, 8) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_23[4]= { 162, 9, 1, 0};
	if (memcmp(buf, b_68002_23, 4) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68002_24[8]= { 162, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68002_24, 8) == 0) {
		printf("%d\n", 68002);
		exit(0);
	}
	}
	{
	unsigned char b_68003_25[4]= { 0, 1, 9, 163};
	if (memcmp(buf, b_68003_25, 4) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_26[8]= { 0, 0, 0, 0, 0, 1, 9, 163};
	if (memcmp(buf, b_68003_26, 8) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_27[4]= { 163, 9, 1, 0};
	if (memcmp(buf, b_68003_27, 4) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68003_28[8]= { 163, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68003_28, 8) == 0) {
		printf("%d\n", 68003);
		exit(0);
	}
	}
	{
	unsigned char b_68004_29[4]= { 0, 1, 9, 164};
	if (memcmp(buf, b_68004_29, 4) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_30[8]= { 0, 0, 0, 0, 0, 1, 9, 164};
	if (memcmp(buf, b_68004_30, 8) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_31[4]= { 164, 9, 1, 0};
	if (memcmp(buf, b_68004_31, 4) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68004_32[8]= { 164, 9, 1, 0, 0, 0, 0, 0};
	if (memcmp(buf, b_68004_32, 8) == 0) {
		printf("%d\n", 68004);
		exit(0);
	}
	}
	{
	unsigned char b_68019_33[4]= { 0, 1, 9, 179};
	if (memcmp(buf, b_68019_33, 4) == 0) {
		printf("%d\n", 68019);
		exit(0);
	}
	}
	{
	unsigned char b_68019_34[4]= { 179, 9, 1, 0};
	if (memcmp(buf, b_68019_34, 4) == 0) {
		printf("%d\n", 68019);
		exit(0);
	}
	}
	{
	unsigned char b_68021_35[4]= { 0, 1, 9, 181};
	if (memcmp(buf, b_68021_35, 4) == 0) {
		printf("%d\n", 68021);
		exit(0);
	}
	}
	{
	unsigned char b_68021_36[4]= { 181, 9, 1, 0};
	if (memcmp(buf, b_68021_36, 4) == 0) {
		printf("%d\n", 68021);
		exit(0);
	}
	}
	{
	unsigned char b_68533_37[4]= { 0, 1, 11, 181};
	if (memcmp(buf, b_68533_37, 4) == 0) {
		printf("%d\n", 68533);
		exit(0);
	}
	}
	{
	unsigned char b_68533_38[4]= { 181, 11, 1, 0};
	if (memcmp(buf, b_68533_38, 4) == 0) {
		printf("%d\n", 68533);
		exit(0);
	}
	}
	printf("0\n"); /* print an invalid format number */
	exit (-1); /* not found, exit with error code */
}
