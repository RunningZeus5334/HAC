#include <stdio.h>
#include <stdlib.h>



int main() {
    // Example: 5x5 RGB image (channels = 3)
    int width = 16;
    int height = 16;
    int channels = 3;
    int size = width * height * channels;

    // Allocate and initialize the input image with sequential values
    unsigned char *image = (unsigned char *)malloc(size * sizeof(unsigned char));
    for (int i = 0; i < size; ++i) {
        image[i] = (unsigned char)(i % 256);
    }

    // Allocate output buffer and zero it
    unsigned char *output = (unsigned char *)malloc(size * sizeof(unsigned char));
    for (int i = 0; i < size; ++i) {
        output[i] = 0;
    }

    // Call the convolution function
    Convolution(image, output, width, height, channels);

    // Print input and output for verification
    printf("Input image (%dx%d, %d channels):\n", width, height, channels);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printf("(");
            for (int c = 0; c < channels; ++c) {
                int idx = (y * width + x) * channels + c;
                printf("%3d", image[idx]);
                if (c < channels - 1) printf(",");
            }
            printf(") ");
        }
        printf("\n");
    }


    printf("\nOutput image after convolution:\n");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            printf("(");
            for (int c = 0; c < channels; ++c) {
                int idx = (y * width + x) * channels + c;
                printf("%3d", output[idx]);
                if (c < channels - 1) printf(",");
            }
            printf(") ");
        }
        printf("\n");
    }

    // Clean up
    free(image);
    free(output);

    return 0;
}

