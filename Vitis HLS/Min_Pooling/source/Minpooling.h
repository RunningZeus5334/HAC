#ifndef MINPOOLING
#define MINPOOLING

void min_pooling(
		volatile unsigned char* image,
		volatile unsigned char* output,
		int width,
		int height,
		int channels
);
#endif
