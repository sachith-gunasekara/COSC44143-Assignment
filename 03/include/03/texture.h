#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/gl.h>
#include <stb_image.h>

#include <iostream>

class Texture {
public:
    unsigned int ID;

    Texture() {
        glGenTextures(1, &ID);
    }

    void bind() {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void setWrapS(GLenum value) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, value);
    }

    void setWrapT(GLenum value) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, value);
    }

    void setMinFilter(GLenum value) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, value);
    }

    void setMagFilter(GLenum value) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, value);
    }

    void generate(const char* path) {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
        if (data) {
            GLenum format;
            if (nrChannels == 1) {
                format = GL_RED;
            }
            else if (nrChannels == 3) {
                format = GL_RGB;
            }
            else if (nrChannels == 4) {
                format = GL_RGBA;
            }

            bind();
            setWrapS(GL_REPEAT);
            setWrapT(GL_REPEAT);
            setMinFilter(GL_LINEAR_MIPMAP_LINEAR);
            setMagFilter(GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }
};

#endif
