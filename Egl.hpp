// The MIT License (MIT)
//
// Copyright (c) 2013 Dan Ginsburg, Budirijanto Purnomo
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

//
// Book:      OpenGL(R) ES 3.0 Programming Guide, 2nd Edition
// Authors:   Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
// ISBN-10:   0-321-93388-5
// ISBN-13:   978-0-321-93388-1
// Publisher: Addison-Wesley Professional
// URLs:      http://www.opengles-book.com
//            http://my.safaribooksonline.com/book/animation-and-3d/9780133440133
//
//
/// \file ESUtil.h
/// \brief A utility library for OpenGL ES.  This library provides a
///        basic common framework for the example applications in the
///        OpenGL ES 3.0 Programming Guide.
//
#ifndef EGL_H
#define EGL_H

///
//  Includes
//
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#else
#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif

#include "WindowSystem/WindowEvent.hpp"
#include "GLEngine_src/Khr_src/Egl_src/EglWindowSystem.hpp"

/// EGL_CreateWindow flag - RGB color buffer
#define EGL_FLAG_FRAMEBUFFER_RGB           0
/// EGL_CreateWindow flag - ALPHA color buffer
#define EGL_FLAG_FRAMEBUFFER_ALPHA         1
/// EGL_CreateWindow flag - depth buffer
#define EGL_FLAG_FRAMEBUFFER_DEPTH         2
/// EGL_CreateWindow flag - stencil buffer
#define EGL_FLAG_FRAMEBUFFER_STENCIL       4
/// EGL_CreateWindow flat - multi-sample buffer
#define EGL_FLAG_FRAMEBUFFER_MULTISAMPLE   8

class Egl
{
    public:
        bool CreateSurfaceAndBindContext(const char *title, int posx, int posy, int width, int height, GLuint flags);
        void swapBuffers();

        void getEvent(WindowEvent *event) const;

    private:
        bool attachToNativeDisplay();
        bool createNativeWindow(const char *title, int posx, int posy, int width, int height);
        bool initEglOnDisplay();
        bool getFramebufferConfig(GLuint flags);
        bool createSurface();
        bool createContext();
        bool bindContextToSurface();

        WindowSystem windowSystem;
        EGLConfig config;
        EGLint majorVersion;
        EGLint minorVersion;
        EGLDisplay display;
        EGLContext context;
        EGLSurface surface;
};

#endif // EGL_H
