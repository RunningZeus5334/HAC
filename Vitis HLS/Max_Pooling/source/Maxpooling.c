#include <stdint.h>
#include <stdlib.h>
#include "Maxpooling.h"


void MaxPooling(volatile unsigned char* image,volatile unsigned char* output, int width, int height, int channels) {
    int outputWidth = width / 2;
    int outputHeight = height / 2;

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



    for (int y = 0; y < outputHeight; y++) {
#pragma HLS PIPELINE II=1
        for (int x = 0; x < outputWidth; x++) {
            for (int ch = 0; ch < channels; ch++) {
                unsigned char maxVal = 0;
                for (int dy = 0; dy < 2; dy++) {
#pragma HLS UNROLL factor=3
                    for (int dx = 0; dx < 2; dx++) {
                        int iy = y * 2 + dy;
                        int ix = x * 2 + dx;
                        unsigned char val = image[(iy * width + ix) * channels + ch];
                        if (val > maxVal) maxVal = val;
                    }
                }
                output[(y * outputWidth + x) * channels + ch] = maxVal;
            }
        }
    }
}
