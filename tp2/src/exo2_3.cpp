#include "exo2_3.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

void exo2_3a() {
    int width, height, channels;
    unsigned char* img = stbi_load("lena.png", &width, &height, &channels, 0);

    std::cout << "Dimension de l'image : (" << width << ", " << height << ")" << std::endl;
    std::cout << "Nombres de cannaux : " << channels << std::endl;

    stbi_write_png("lena_a.png", width, height, channels, (void*)img, 0);
    stbi_image_free(img);
}

void exo2_3b() {
    int width, height, channels;
    unsigned char* img = stbi_load("lena.png", &width, &height, &channels, 0);

    for (int i = height / 3; i < 2 * (height / 3); i++) {
        for (int j = width / 3; j < 2 * (width / 3); j++) {
            int ipixel = (i * width + j) * channels;
            img[ipixel] = 0;
            img[ipixel + 1] = 0;
            img[ipixel + 2] = 0;
        }
    }
    stbi_write_png("lena_b.png", width, height, channels, (void*)img, 0);
    stbi_image_free(img);
}

void exo2_3c() {
    int width, height, channels;
    unsigned char* img = stbi_load("lena.png", &width, &height, &channels, 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ipixel = (i * width + j) * channels;
            int moyenne = (img[ipixel] + img[ipixel + 1] + img[ipixel + 2] + img[ipixel + 3]) / 4;
            if (100 < moyenne && moyenne < 150) {
                img[ipixel] = 255; img[ipixel + 1] = 255;
                img[ipixel + 2] = 255; img[ipixel + 3] = 255;
            }
        }
    }
    stbi_write_png("lena_c.png", width, height, channels, (void*)img, 0);
    stbi_image_free(img);
}