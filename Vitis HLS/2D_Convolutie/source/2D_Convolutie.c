#include <stdint.h>
#include <stdlib.h>
#include "2D_Convolutie.h"

// Forward declaration of your helper
void applyConvolution(
		volatile unsigned char* image,
		volatile unsigned char* output,
		int width,
		int height,
		int channels,
		float kernel[3][3]
);

// Top level
void Convolution(
		volatile unsigned char* image,
		volatile unsigned char* output,
		int width,
		int height,
		int channels
) {
	// --- AXI master ports for both image & output buffers ---
#pragma HLS INTERFACE m_axi      port=image   offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi      port=output  offset=slave bundle=gmem

	// --- Single AXI-Lite control interface for all scalars and pointers ---
#pragma HLS INTERFACE s_axilite  port=image    bundle=control
#pragma HLS INTERFACE s_axilite  port=output   bundle=control
#pragma HLS INTERFACE s_axilite  port=width    bundle=control
#pragma HLS INTERFACE s_axilite  port=height   bundle=control
#pragma HLS INTERFACE s_axilite  port=channels bundle=control
#pragma HLS INTERFACE s_axilite  port=return   bundle=control

	// Your fixed Sobel-style kernel
	float kernel[3][3] = {
			{ 1,  0, -1},
			{ 1,  0, -1},
			{ 1,  0, -1}
	};


	applyConvolution(image, output, width, height, channels, kernel);


}

void applyConvolution(
		volatile unsigned char* image,
		volatile unsigned char* output,
		int width,
		int height,
		int channels,
		float kernel[3][3]
)
{
	int edge = 1; // Since kernel size is 3x3

	for (int y = 0; y < height; y++) {

#pragma HLS PIPELINE II=1

		for (int x = 0; x < width; x++) {
			float sum[3] = {0.0, 0.0, 0.0}; // Sum for each channel

			for (int ky = -edge; ky <= edge; ky++) {
				for (int kx = -edge; kx <= edge; kx++) {
					int ix = x + kx;
					int iy = y + ky;
					if (ix >= 0 && ix < width && iy >= 0 && iy < height) {
#pragma HLS UNROLL factor=3
						for (int ch = 0; ch < channels; ch++) {
							if (ch < 3) { // Apply convolution only to RGB channels
								sum[ch] += kernel[ky + edge][kx + edge] * image[(iy * width + ix) * channels + ch];
							}
						}
					}
				}
			}
			for (int ch = 0; ch < channels; ch++) {
				if (ch < 3) {
					int val = (int)sum[ch];
					output[(y * width + x) * channels + ch] = (unsigned char)(val > 255 ? 255 : (val < 0 ? 0 : val));
				} else {
					// Preserve the alpha channel if present
					output[(y * width + x) * channels + ch] = image[(y * width + x) * channels + ch];
				}
			}
		}
	}
}
