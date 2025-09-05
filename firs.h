/*  FIRSLIB - Fanatical Independent Refined Small 2D Game Development Library

VERSION

    0.0.0

AUTHOR

    Wolf Carol <wolfcarol@126.com>

LICENSE

    MIT License or Public Domain

MIN REQUIRED OS

    Windows 7 SP1

TARGET ARCHITECTURE

    x64

RECOMMENDED USE

    Compile with gcc (MinGW-w64) and make C# binding with P/Invoke

    firs.c:
        #define FIRSAPI_EXPORT
        #define FIRSLIB_IMPLEMENTATION
        #include "firs.h"

    Makefile:
        firs.dll: firs.c
        gcc -shared -s -Os -flto -fPIC firs.c -o firs.dll -luser32 -lgdi32 -lopengl32 -lxaudio2_8 -lxinput -lole32
*/

#ifndef FIRS_H
#define FIRS_H

#ifdef FIRSAPI_EXPORT
#define FIRSAPI __declspec(dllexport)
#else
#define FIRSAPI __declspec(dllimport)
#endif

// Input

typedef enum KeyCode
{
    MouseLeft = 0x01,
    MouseRight = 0x02,
    MouseMiddle = 0x04,
    Backspace = 0x08,
    Tab = 0x09,
    Return = 0x0D,
    Pause = 0x13,
    CapsLock = 0x14,
    Esc = 0x1B,
    Space = 0x20,
    PageUp = 0x21,
    PageDown = 0x22,
    End = 0x23,
    Home = 0x24,
    LeftArrow = 0x25,
    UpArrow = 0x26,
    RightArrow = 0x27,
    DownArrow = 0x28,
    Insert = 0x2D,
    Delete = 0x2E,
    Alpha0 = 0x30,
    Alpha1 = 0x31,
    Alpha2 = 0x32,
    Alpha3 = 0x33,
    Alpha4 = 0x34,
    Alpha5 = 0x35,
    Alpha6 = 0x36,
    Alpha7 = 0x37,
    Alpha8 = 0x38,
    Alpha9 = 0x39,
    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44,
    E = 0x45,
    F = 0x46,
    G = 0x47,
    H = 0x48,
    I = 0x49,
    J = 0x4A,
    K = 0x4B,
    L = 0x4C,
    M = 0x4D,
    N = 0x4E,
    O = 0x4F,
    P = 0x50,
    Q = 0x51,
    R = 0x52,
    S = 0x53,
    T = 0x54,
    U = 0x55,
    V = 0x56,
    W = 0x57,
    X = 0x58,
    Y = 0x59,
    Z = 0x5A,
    LeftWin = 0x5B,
    RightWin = 0x5C,
    Menu = 0x5D,
    Keypad0 = 0x60,
    Keypad1 = 0x61,
    Keypad2 = 0x62,
    Keypad3 = 0x63,
    Keypad4 = 0x64,
    Keypad5 = 0x65,
    Keypad6 = 0x66,
    Keypad7 = 0x67,
    Keypad8 = 0x68,
    Keypad9 = 0x69,
    KeypadMultiply = 0x6A,
    KeypadPlus = 0x6B,
    KeypadMinus = 0x6D,
    KeypadPeriod = 0x6E,
    KeypadDevide = 0x6F,
    F1 = 0x70,
    F2 = 0x71,
    F3 = 0x72,
    F4 = 0x73,
    F5 = 0x74,
    F6 = 0x75,
    F7 = 0x76,
    F8 = 0x77,
    F9 = 0x78,
    F10 = 0x79,
    F11 = 0x7A,
    F12 = 0x7B,
    NumLock = 0x90,
    ScrollLock = 0x91,
    LeftShift = 0xA0,
    RightShift = 0xA1,
    LeftCtrl = 0xA2,
    RightCtrl = 0xA3,
    LeftAlt = 0xA4,
    RightAlt = 0xA5,
    Semicolon = 0xBA,
    Equals = 0xBB,
    Comma = 0xBC,
    Minus = 0xBD,
    Period = 0xBE,
    Slash = 0xBF,
    BackQuote = 0xC0,
    LeftBracket = 0xDB,
    BackSlash = 0xDC,
    RightBracket = 0xDD,
    Quote = 0xDE
} KeyCode;

typedef enum GamepadKey
{
    GamepadUp = 0x0001,
    GamepadDown = 0x0002,
    GamepadLeft = 0x0004,
    GamepadRight = 0x0008,
    GamepadStart = 0x0010,
    GamepadBack = 0x0020,
    GamepadLeftThumb = 0x0040,
    GamepadRightThumb = 0x0080,
    GamepadLeftShoulder = 0x0100,
    GamepadRightShoulder = 0x0200,
    GamepadA = 0x1000,
    GamepadB = 0x2000,
    GamepadX = 0x4000,
    GamepadY = 0x8000
} GamepadKey;

typedef enum GamepadAxis
{
    GamepadLeftStickHorizontal = 0,
    GamepadLeftStickVertical = 1,
    GamepadRightStickHorizontal = 2,
    GamepadRightStickVertical = 3,
    GamepadLeftTrigger = 4,
    GamepadRightTrigger = 5
} GamepadAxis;

FIRSAPI int isKeyPressed(int key);
FIRSAPI void getMousePosition(int *x, int *y);
FIRSAPI float getMouseWheelScroll();
FIRSAPI int isGamepadValid(unsigned int padID);
FIRSAPI int isGamepadKeyPressed(unsigned int padID, GamepadKey key);
FIRSAPI float getGamepadAxis(unsigned int padID, GamepadAxis axis);
FIRSAPI void setGamepadVibration(unsigned int padID, float leftMotor, float rightMotor);

// Window

FIRSAPI void initWindow(const unsigned short *title, unsigned int width, unsigned int height);
FIRSAPI void closeWindow();
FIRSAPI int shouldClose();
FIRSAPI int isWindowHidden();
FIRSAPI void setWindowTitle(unsigned short *title);
FIRSAPI void setFullscreen();
FIRSAPI void setWindowed(unsigned int width, unsigned int height);
FIRSAPI void getClientSize(unsigned int *width, unsigned int *height);
FIRSAPI int isWindowFocused();
FIRSAPI int isCursorHidden();
FIRSAPI void setCursorVisible(int visible);
FIRSAPI void pollInputEvents();
FIRSAPI void swapScreenBuffers();

// Audio

FIRSAPI void initAudioEngine(unsigned int maxSourceCount);
FIRSAPI void shutdownAudioEngine();
FIRSAPI void setMasterVolume(float volume);
FIRSAPI float getMasterVolume();
FIRSAPI int createSource(unsigned int *sourceID, unsigned int channels, unsigned int sampleRate, unsigned int bitsPerSample, const unsigned char *data, unsigned int size, int loop);
FIRSAPI void destroySource(unsigned int sourceID);
FIRSAPI int isSourcePlaying(unsigned int sourceID);
FIRSAPI float getSourceAudioLength(unsigned int sourceID);
FIRSAPI float getSourceCurrentTime(unsigned int sourceID);
FIRSAPI void setSourceCurrentTime(unsigned int sourceID, float time);
FIRSAPI void playSource(unsigned int sourceID);
FIRSAPI void pauseSource(unsigned int sourceID);
FIRSAPI void stopSource(unsigned int sourceID);
FIRSAPI void setSourceVolume(unsigned int sourceID, float volume);
FIRSAPI float getSourceVolume(unsigned int sourceID);
FIRSAPI void setSourcePitch(unsigned int sourceID, float pitch);
FIRSAPI float getSourcePitch(unsigned int sourceID);
FIRSAPI void setSourcePan(unsigned int sourceID, float pan);
FIRSAPI float getSourcePan(unsigned int sourceID);

// Render

FIRSAPI void setViewport(int x, int y, int w, int h);
FIRSAPI void clearBackground(float r, float g, float b, float a);
FIRSAPI void drawElements(unsigned int vertexID, int count);
FIRSAPI void drawElementsInstanced(unsigned int vertexID, int count, int instanceCount);
FIRSAPI unsigned int getGLErrorCode();

// Texture

FIRSAPI int createTexture(unsigned int *textureID, unsigned int width, unsigned int height, unsigned int channels, const unsigned char *data, int linear);
FIRSAPI void destroyTexture(unsigned int textureID);
FIRSAPI void bindTexture(unsigned int textureID, unsigned int slot);
FIRSAPI int updateTexture(unsigned int textureID, unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height, unsigned int channels, const unsigned char *data);

// Buffer

FIRSAPI unsigned int createBuffer(const void *data, long long size, int type, int dynamic);
FIRSAPI void destroyBuffer(unsigned int bufferID, int type);
FIRSAPI void bindBuffer(unsigned int bufferID, int type);
FIRSAPI void updateBuffer(unsigned int bufferID, const void *data, long long size, long long offset, int type);

// Vertex

FIRSAPI unsigned int createVertex(unsigned int elementID);
FIRSAPI void destroyVertex(unsigned int vertexID);
FIRSAPI void bindVertex(unsigned int vertexID);
FIRSAPI void setAttribute(unsigned int vertexID, unsigned int arrayID, int location, int size, int offset, int stride, int divisor);

// Shader

FIRSAPI int createShader(unsigned int *shaderID, const char *vertSource, const char *fragSource);
FIRSAPI const char *getShaderInfo();
FIRSAPI void destroyShader(unsigned int shaderID);
FIRSAPI void bindShader(unsigned int shaderID);
FIRSAPI int setUniform(unsigned int shaderID, const char *name, const void *value, unsigned int dimension, unsigned int count, int type, int matrix);

// Frame

FIRSAPI unsigned int createFrame();
FIRSAPI void destroyFrame(unsigned int frameID);
FIRSAPI void bindFrame(unsigned int frameID);
FIRSAPI void attachTexture(unsigned int frameID, unsigned int textureID, unsigned int layoutID);

#endif

#ifdef FIRSLIB_IMPLEMENTATION

#define UNICODE
#define _UNICODE
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/gl.h>
#include <xaudio2.h>
#include <xinput.h>

// OpenGL

#define APIENTRYP __stdcall *

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31

#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82

#define GL_CLAMP_TO_EDGE 0x812F

#define GL_TEXTURE0 0x84C0

#define GL_COLOR_ATTACHMENT0 0x8CE0

#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893

#define GL_FRAMEBUFFER 0x8D40

#define GL_STREAM_DRAW 0x88E0
#define GL_STATIC_DRAW 0x88E4

#define GL_RG 0x8227
#define GL_R8 0x8229
#define GL_RG8 0x822B

typedef char GLchar;
typedef signed long long int GLsizeiptr;
typedef signed long long int GLintptr;

typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
typedef void(APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length);
typedef void(APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void(APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef void(APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
typedef void(APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void(APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void(APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void(APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void(APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void(APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void(APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
typedef void(APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void(APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void(APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void(APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void(APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void(APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void(APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void(APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void(APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void(APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void(APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void(APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void(APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void(APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void(APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void(APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
typedef void(APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void(APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void(APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void(APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void(APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void(APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void(APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void(APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void(APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);

static PFNGLCREATESHADERPROC glCreateShader;
static PFNGLSHADERSOURCEPROC glShaderSource;
static PFNGLCOMPILESHADERPROC glCompileShader;
static PFNGLGETSHADERIVPROC glGetShaderiv;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
static PFNGLCREATEPROGRAMPROC glCreateProgram;
static PFNGLATTACHSHADERPROC glAttachShader;
static PFNGLLINKPROGRAMPROC glLinkProgram;
static PFNGLGETPROGRAMIVPROC glGetProgramiv;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
static PFNGLUSEPROGRAMPROC glUseProgram;
static PFNGLDELETEPROGRAMPROC glDeleteProgram;
static PFNGLDELETESHADERPROC glDeleteShader;
static PFNGLDETACHSHADERPROC glDetachShader;
static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
static PFNGLUNIFORM1FVPROC glUniform1fv;
static PFNGLUNIFORM2FVPROC glUniform2fv;
static PFNGLUNIFORM3FVPROC glUniform3fv;
static PFNGLUNIFORM4FVPROC glUniform4fv;
static PFNGLUNIFORM1IVPROC glUniform1iv;
static PFNGLUNIFORM2IVPROC glUniform2iv;
static PFNGLUNIFORM3IVPROC glUniform3iv;
static PFNGLUNIFORM4IVPROC glUniform4iv;
static PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
static PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
static PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
static PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
static PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
static PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
static PFNGLGENBUFFERSPROC glGenBuffers;
static PFNGLBINDBUFFERPROC glBindBuffer;
static PFNGLBUFFERDATAPROC glBufferData;
static PFNGLDELETEBUFFERSPROC glDeleteBuffers;
static PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
static PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
static PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
static PFNGLACTIVETEXTUREPROC glActiveTexture;
static PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
static PFNGLBUFFERSUBDATAPROC glBufferSubData;
static PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
static PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
static PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
static PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
static PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
static PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;

static void loadGLFunc()
{
    glCreateShader = (PFNGLCREATESHADERPROC)(uintptr_t)(uintptr_t)wglGetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)(uintptr_t)wglGetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)(uintptr_t)wglGetProcAddress("glCompileShader");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)(uintptr_t)wglGetProcAddress("glGetShaderiv");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)(uintptr_t)wglGetProcAddress("glGetShaderInfoLog");
    glCreateProgram = (PFNGLCREATEPROGRAMPROC)(uintptr_t)wglGetProcAddress("glCreateProgram");
    glAttachShader = (PFNGLATTACHSHADERPROC)(uintptr_t)wglGetProcAddress("glAttachShader");
    glLinkProgram = (PFNGLLINKPROGRAMPROC)(uintptr_t)wglGetProcAddress("glLinkProgram");
    glGetProgramiv = (PFNGLGETPROGRAMIVPROC)(uintptr_t)wglGetProcAddress("glGetProgramiv");
    glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)(uintptr_t)wglGetProcAddress("glGetProgramInfoLog");
    glUseProgram = (PFNGLUSEPROGRAMPROC)(uintptr_t)wglGetProcAddress("glUseProgram");
    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)(uintptr_t)wglGetProcAddress("glDeleteProgram");
    glDeleteShader = (PFNGLDELETESHADERPROC)(uintptr_t)wglGetProcAddress("glDeleteShader");
    glDetachShader = (PFNGLDETACHSHADERPROC)(uintptr_t)wglGetProcAddress("glDetachShader");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)(uintptr_t)wglGetProcAddress("glGetUniformLocation");
    glUniform1fv = (PFNGLUNIFORM1FVPROC)(uintptr_t)wglGetProcAddress("glUniform1fv");
    glUniform2fv = (PFNGLUNIFORM2FVPROC)(uintptr_t)wglGetProcAddress("glUniform2fv");
    glUniform3fv = (PFNGLUNIFORM3FVPROC)(uintptr_t)wglGetProcAddress("glUniform3fv");
    glUniform4fv = (PFNGLUNIFORM4FVPROC)(uintptr_t)wglGetProcAddress("glUniform4fv");
    glUniform1iv = (PFNGLUNIFORM1IVPROC)(uintptr_t)wglGetProcAddress("glUniform1iv");
    glUniform2iv = (PFNGLUNIFORM2IVPROC)(uintptr_t)wglGetProcAddress("glUniform2iv");
    glUniform3iv = (PFNGLUNIFORM3IVPROC)(uintptr_t)wglGetProcAddress("glUniform3iv");
    glUniform4iv = (PFNGLUNIFORM4IVPROC)(uintptr_t)wglGetProcAddress("glUniform4iv");
    glUniformMatrix2fv = (PFNGLUNIFORMMATRIX4FVPROC)(uintptr_t)wglGetProcAddress("glUniformMatrix2fv");
    glUniformMatrix3fv = (PFNGLUNIFORMMATRIX4FVPROC)(uintptr_t)wglGetProcAddress("glUniformMatrix3fv");
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)(uintptr_t)wglGetProcAddress("glUniformMatrix4fv");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)(uintptr_t)wglGetProcAddress("glEnableVertexAttribArray");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)(uintptr_t)wglGetProcAddress("glVertexAttribPointer");
    glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)(uintptr_t)wglGetProcAddress("glVertexAttribDivisor");
    glGenBuffers = (PFNGLGENBUFFERSPROC)(uintptr_t)wglGetProcAddress("glGenBuffers");
    glBindBuffer = (PFNGLBINDBUFFERPROC)(uintptr_t)wglGetProcAddress("glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)(uintptr_t)wglGetProcAddress("glBufferData");
    glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)(uintptr_t)wglGetProcAddress("glDeleteBuffers");
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)(uintptr_t)wglGetProcAddress("glGenVertexArrays");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)(uintptr_t)wglGetProcAddress("glBindVertexArray");
    glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)(uintptr_t)wglGetProcAddress("glDeleteVertexArrays");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)(uintptr_t)wglGetProcAddress("glActiveTexture");
    glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)(uintptr_t)wglGetProcAddress("glGenerateMipmap");
    glBufferSubData = (PFNGLBUFFERSUBDATAPROC)(uintptr_t)wglGetProcAddress("glBufferSubData");
    glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)(uintptr_t)wglGetProcAddress("glDrawArraysInstanced");
    glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)(uintptr_t)wglGetProcAddress("glDrawElementsInstanced");
    glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)(uintptr_t)wglGetProcAddress("glGenFramebuffers");
    glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)(uintptr_t)wglGetProcAddress("glBindFramebuffer");
    glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)(uintptr_t)wglGetProcAddress("glDeleteFramebuffers");
    glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)(uintptr_t)wglGetProcAddress("glFramebufferTexture2D");
}

// Input

static unsigned char _currKeys[256] = {0};
static float _mouseWheelScroll = 0.0f;
static POINT _mousePos = {0};
static BOOL _gamepadValid[4] = {0};
static XINPUT_STATE _currGamepadState[4] = {0};

BOOL isKeyPressed(int key)
{
    return _currKeys[key] & 0x80;
}

void getMousePosition(int *x, int *y)
{
    *x = _mousePos.x;
    *y = _mousePos.y;
}

float getMouseWheelScroll()
{
    return _mouseWheelScroll;
}

BOOL isGamepadValid(unsigned int padID)
{
    return padID <= 3 ? _gamepadValid[padID] : FALSE;
}

BOOL isGamepadKeyPressed(unsigned int padID, GamepadKey key)
{
    return _currGamepadState[padID].Gamepad.wButtons & key;
}

float getGamepadAxis(unsigned int padID, GamepadAxis axis)
{
    if (axis == GamepadLeftStickHorizontal)
    {
        return _currGamepadState[padID].Gamepad.sThumbLX / 32767.0f;
    }
    else if (axis == GamepadLeftStickVertical)
    {
        return _currGamepadState[padID].Gamepad.sThumbLY / 32767.0f;
    }
    else if (axis == GamepadRightStickHorizontal)
    {
        return _currGamepadState[padID].Gamepad.sThumbRX / 32767.0f;
    }
    else if (axis == GamepadRightStickVertical)
    {
        return _currGamepadState[padID].Gamepad.sThumbRY / 32767.0f;
    }
    else if (axis == GamepadLeftTrigger)
    {
        return _currGamepadState[padID].Gamepad.bLeftTrigger / 255.0f;
    }
    else if (axis == GamepadRightTrigger)
    {
        return _currGamepadState[padID].Gamepad.bRightTrigger / 255.0f;
    }
    return 0.0f;
}

void setGamepadVibration(unsigned int padID, float leftMotor, float rightMotor)
{
    XINPUT_VIBRATION vibration = {0};
    vibration.wLeftMotorSpeed = (WORD)(leftMotor * 65535);
    vibration.wRightMotorSpeed = (WORD)(rightMotor * 65535);
    XInputSetState(padID, &vibration);
}

// Window

static BOOL _isDragging = FALSE;
static POINT _mouseStartPos = {0};
static BOOL _cursorHidden = FALSE;
static HWND _window = NULL;
static HDC _deviceContext = NULL;
static HGLRC _renderContext = NULL;
static BOOL _shouldClose = FALSE;

typedef BOOL(__stdcall *PFNWGLSWAPINTERVALEXTPROC)(int interval);
static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

static LRESULT CALLBACK WP(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_CREATE || msg == WM_DEVICECHANGE)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            _gamepadValid[i] = XInputGetState(i, &_currGamepadState[i]) == ERROR_SUCCESS;
        }
    }
    else if (msg == WM_DESTROY)
    {
        _shouldClose = TRUE;
        wglMakeCurrent(NULL, NULL);
        if (_renderContext != NULL)
        {
            wglDeleteContext(_renderContext);
            _renderContext = NULL;
        }
        if (_window != NULL && _deviceContext != NULL)
        {
            ReleaseDC(_window, _deviceContext);
        }
        PostQuitMessage(0);
    }
    else if (msg == WM_NCDESTROY)
    {
        if (_window != NULL)
        {
            _window = NULL;
        }
    }
    else if (msg == WM_SYSCOMMAND)
    {
        switch (wParam & 0xFFF0)
        {
        case SC_MOVE:
        case SC_SIZE:
        case SC_MOUSEMENU:
        case SC_KEYMENU:
            return 0;
        }
    }
    else if (msg == WM_NCLBUTTONDOWN)
    {
        if (wParam == HTSYSMENU || wParam == HTCAPTION)
        {
            _isDragging = TRUE;
            GetCursorPos(&_mouseStartPos);
            SetCapture(hWnd);
        }
    }
    else if (msg == WM_NCRBUTTONDOWN || msg == WM_NCLBUTTONDBLCLK)
    {
        return 0;
    }
    else if (msg == WM_MOUSEMOVE)
    {
        if (_isDragging)
        {
            POINT mouseCurrentPos = {0};
            GetCursorPos(&mouseCurrentPos);
            RECT windowRect;
            GetWindowRect(hWnd, &windowRect);
            int x = windowRect.left + mouseCurrentPos.x - _mouseStartPos.x;
            int y = windowRect.top + mouseCurrentPos.y - _mouseStartPos.y;
            _mouseStartPos = mouseCurrentPos;
            SetWindowPos(hWnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        }
    }
    else if (msg == WM_LBUTTONUP)
    {
        if (_isDragging)
        {
            _isDragging = FALSE;
            ReleaseCapture();
        }
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

static void initOpenGL()
{
    _deviceContext = GetDC(_window);
    PIXELFORMATDESCRIPTOR pfd = {0};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = LPD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat(_deviceContext, &pfd);
    SetPixelFormat(_deviceContext, format, &pfd);
    _renderContext = wglCreateContext(_deviceContext);
    wglMakeCurrent(_deviceContext, _renderContext);
    loadGLFunc();
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)(uintptr_t)wglGetProcAddress("wglSwapIntervalEXT");
    wglSwapIntervalEXT(1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void initWindow(const unsigned short *title, unsigned int width, unsigned int height)
{
    LONG_PTR style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
    RECT rect = {0, 0, width, height};
    AdjustWindowRect(&rect, style, FALSE);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WP;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"FIRSWND";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
    RegisterClass(&wc);
    _window = CreateWindow(
        wc.lpszClassName,
        title,
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        wc.hInstance,
        NULL);
    ShowWindow(_window, SW_SHOW);
    UpdateWindow(_window);
    initOpenGL();
}

void closeWindow()
{
    _shouldClose = TRUE;
}

BOOL shouldClose()
{
    return _shouldClose;
}

BOOL isWindowHidden()
{
    return IsIconic(_window);
}

void setWindowTitle(unsigned short *title)
{
    SetWindowText(_window, title);
}

void setFullscreen()
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    SetWindowLongPtr(_window, GWL_STYLE, WS_POPUP);
    SetWindowPos(_window, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_SHOWWINDOW);
}

void setWindowed(unsigned int width, unsigned int height)
{
    LONG_PTR style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
    SetWindowLongPtr(_window, GWL_STYLE, style);
    RECT rect = {0, 0, width, height};
    AdjustWindowRect(&rect, style, FALSE);
    SetWindowPos(_window, HWND_TOP, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
}

void getClientSize(unsigned int *width, unsigned int *height)
{
    RECT rect = {0};
    GetClientRect(_window, &rect);
    *width = rect.right - rect.left;
    *height = rect.bottom - rect.top;
}

BOOL isWindowFocused()
{
    return GetFocus() == _window;
}

BOOL isCursorHidden()
{
    return _cursorHidden;
}

void setCursorVisible(BOOL visible)
{
    if (visible == _cursorHidden)
    {
        ShowCursor(visible);
        _cursorHidden = !visible;
    }
}

void pollInputEvents()
{
    if (_shouldClose)
    {
        SendMessage(_window, WM_CLOSE, 0, 0);
    }
    _mouseWheelScroll = 0.0f;
    GetKeyboardState(_currKeys);
    GetCursorPos(&_mousePos);
    ScreenToClient(_window, &_mousePos);
    for (int i = 0; i < 4; i++)
    {
        if (_gamepadValid[i] == TRUE)
        {
            _gamepadValid[i] = XInputGetState(i, &_currGamepadState[i]) == ERROR_SUCCESS;
        }
    }
    MSG msg = {0};
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_MOUSEWHEEL)
        {
            short delta = HIWORD(msg.wParam);
            _mouseWheelScroll = delta / 120.0f;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void swapScreenBuffers()
{
    SwapBuffers(_deviceContext);
}

// Audio

typedef struct SourceData
{
    IXAudio2VoiceCallback _callback;
    BOOL _used;
    unsigned int _length;
    float _time;
    float _volume;
    float _pitch;
    float _pan;
    BOOL _isPlaying;
    BOOL _end;
    IXAudio2SourceVoice *_sourceVoice;
    WAVEFORMATEX _format;
    XAUDIO2_BUFFER _buffer;
} SourceData;

static IXAudio2 *_audioEngine = NULL;
static IXAudio2MasteringVoice *_masterVoice = NULL;
static SourceData *_sourceList = NULL;
static unsigned int _sourceCount = 0;

static void STDMETHODCALLTYPE voiceCallback1(IXAudio2VoiceCallback *This, UINT32 i)
{
    (void)This;
    (void)i;
}
static void STDMETHODCALLTYPE voiceCallback2(IXAudio2VoiceCallback *This, void *p)
{
    (void)This;
    (void)p;
}
static void STDMETHODCALLTYPE voiceCallback3(IXAudio2VoiceCallback *This, void *p, HRESULT err)
{
    (void)This;
    (void)p;
    (void)err;
}

static void STDMETHODCALLTYPE onVoiceProcessingPassEnd(IXAudio2VoiceCallback *This)
{
    SourceData *data = (SourceData *)This;
    XAUDIO2_VOICE_STATE state;
    data->_sourceVoice->lpVtbl->GetState(data->_sourceVoice, &state, 0);
    data->_time = 1.0f * state.SamplesPlayed / data->_format.nSamplesPerSec;
}

static void STDMETHODCALLTYPE onStreamEnd(IXAudio2VoiceCallback *This)
{
    SourceData *data = (SourceData *)This;
    data->_sourceVoice->lpVtbl->Stop(data->_sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    data->_sourceVoice->lpVtbl->FlushSourceBuffers(data->_sourceVoice);
    data->_time = 0.0f;
    data->_isPlaying = FALSE;
    data->_end = TRUE;
}

static IXAudio2VoiceCallbackVtbl _voiceCallback_vtbl = {
    voiceCallback1,
    onVoiceProcessingPassEnd,
    onStreamEnd,
    voiceCallback2,
    voiceCallback2,
    voiceCallback2,
    voiceCallback3};

static BOOL getSource(unsigned int *sourceID)
{
    for (unsigned int i = 0; i < _sourceCount; i++)
    {
        if (_sourceList[i]._used == FALSE)
        {
            _sourceList[i]._used = TRUE;
            *sourceID = i;
            return TRUE;
        }
    }
    return FALSE;
}

void initAudioEngine(unsigned int maxSourceCount)
{
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    XAudio2Create(&_audioEngine, 0, XAUDIO2_DEFAULT_PROCESSOR);
    _audioEngine->lpVtbl->CreateMasteringVoice(_audioEngine, &_masterVoice, 2, XAUDIO2_DEFAULT_SAMPLERATE, 0, NULL, NULL, AudioCategory_GameMedia);
    _sourceList = (SourceData *)malloc(maxSourceCount * sizeof(SourceData));
    _sourceCount = maxSourceCount;
    memset(_sourceList, 0, _sourceCount * sizeof(SourceData));
}

void shutdownAudioEngine()
{
    if (_sourceList != NULL)
    {
        for (unsigned int i = 0; i < _sourceCount; i++)
        {
            destroySource(i);
        }
        free(_sourceList);
        _sourceList = NULL;
    }
    _masterVoice->lpVtbl->DestroyVoice(_masterVoice);
    _masterVoice = NULL;
    _audioEngine->lpVtbl->Release(_audioEngine);
    _audioEngine = NULL;
    CoUninitialize();
}

void setMasterVolume(float volume)
{
    _masterVoice->lpVtbl->SetVolume(_masterVoice, volume, XAUDIO2_COMMIT_NOW);
}

float getMasterVolume()
{
    float volume = 0.0f;
    _masterVoice->lpVtbl->GetVolume(_masterVoice, &volume);
    return volume;
}

BOOL createSource(unsigned int *sourceID, unsigned int channels, unsigned int sampleRate, unsigned int bitsPerSample, const unsigned char *data, unsigned int size, BOOL loop)
{
    if (channels != 1 && channels != 2)
    {
        return FALSE;
    }
    unsigned int id;
    BOOL ok = getSource(&id);
    if (!ok)
    {
        return FALSE;
    }
    unsigned char *copyData = (unsigned char *)malloc(size);
    if (!data)
    {
        _sourceList[id]._used = FALSE;
        return FALSE;
    }
    memcpy(copyData, data, size);
    _sourceList[id]._length = size / (channels * bitsPerSample / 8);
    _sourceList[id]._time = 0.0f;
    _sourceList[id]._volume = 1.0f;
    _sourceList[id]._pitch = 1.0f;
    _sourceList[id]._pan = 0.0f;
    _sourceList[id]._isPlaying = FALSE;
    _sourceList[id]._end = TRUE;
    _sourceList[id]._format.wFormatTag = WAVE_FORMAT_PCM;
    _sourceList[id]._format.nChannels = channels;
    _sourceList[id]._format.nSamplesPerSec = sampleRate;
    _sourceList[id]._format.wBitsPerSample = bitsPerSample;
    _sourceList[id]._format.nBlockAlign = channels * bitsPerSample / 8;
    _sourceList[id]._format.nAvgBytesPerSec = sampleRate * channels * bitsPerSample / 8;
    _sourceList[id]._format.cbSize = 0;
    _sourceList[id]._buffer.AudioBytes = size;
    _sourceList[id]._buffer.pAudioData = copyData;
    if (loop == FALSE)
    {
        _sourceList[id]._buffer.Flags = XAUDIO2_END_OF_STREAM;
    }
    else
    {
        _sourceList[id]._buffer.LoopCount = XAUDIO2_LOOP_INFINITE;
    }
    if (_sourceList[id]._callback.lpVtbl == NULL)
    {
        _sourceList[id]._callback = (IXAudio2VoiceCallback){&_voiceCallback_vtbl};
    }
    HRESULT hr = _audioEngine->lpVtbl->CreateSourceVoice(_audioEngine, &_sourceList[id]._sourceVoice, &_sourceList[id]._format, 0, 2, &_sourceList[id]._callback, NULL, NULL);
    if (FAILED(hr))
    {
        free(copyData);
        _sourceList[id]._used = FALSE;
        return FALSE;
    }
    *sourceID = id;
    return TRUE;
}

void destroySource(unsigned int sourceID)
{
    if (_sourceList[sourceID]._used == TRUE)
    {
        if (_sourceList[sourceID]._sourceVoice != NULL)
        {
            _sourceList[sourceID]._sourceVoice->lpVtbl->Stop(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
            _sourceList[sourceID]._sourceVoice->lpVtbl->FlushSourceBuffers(_sourceList[sourceID]._sourceVoice);
            _sourceList[sourceID]._sourceVoice->lpVtbl->DestroyVoice(_sourceList[sourceID]._sourceVoice);
            _sourceList[sourceID]._sourceVoice = NULL;
        }
        free((void *)_sourceList[sourceID]._buffer.pAudioData);
        _sourceList[sourceID]._used = FALSE;
    }
}

BOOL isSourcePlaying(unsigned int sourceID)
{
    return _sourceList[sourceID]._isPlaying;
}

float getSourceAudioLength(unsigned int sourceID)
{
    return 1.0f * _sourceList[sourceID]._length / _sourceList[sourceID]._format.nSamplesPerSec;
}

float getSourceCurrentTime(unsigned int sourceID)
{
    return _sourceList[sourceID]._time;
}

void setSourceCurrentTime(unsigned int sourceID, float time)
{
    if (time < 0.0f)
    {
        time = 0.0f;
    }
    unsigned int sampleOffset = time * _sourceList[sourceID]._format.nSamplesPerSec;
    if (sampleOffset >= _sourceList[sourceID]._length)
    {
        sampleOffset = _sourceList[sourceID]._length - 1;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->Stop(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._sourceVoice->lpVtbl->FlushSourceBuffers(_sourceList[sourceID]._sourceVoice);
    _sourceList[sourceID]._buffer.PlayBegin = sampleOffset;
    _sourceList[sourceID]._sourceVoice->lpVtbl->SubmitSourceBuffer(_sourceList[sourceID]._sourceVoice, &_sourceList[sourceID]._buffer, NULL);
    if (_sourceList[sourceID]._isPlaying)
    {
        _sourceList[sourceID]._sourceVoice->lpVtbl->Start(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    }
    _sourceList[sourceID]._time = 1.0f * sampleOffset / _sourceList[sourceID]._format.nSamplesPerSec;
}

void playSource(unsigned int sourceID)
{
    if (_sourceList[sourceID]._isPlaying == TRUE)
    {
        return;
    }
    if (_sourceList[sourceID]._end)
    {
        _sourceList[sourceID]._buffer.PlayBegin = 0u;
        _sourceList[sourceID]._sourceVoice->lpVtbl->SubmitSourceBuffer(_sourceList[sourceID]._sourceVoice, &_sourceList[sourceID]._buffer, NULL);
        _sourceList[sourceID]._end = FALSE;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->Start(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._isPlaying = TRUE;
}

void pauseSource(unsigned int sourceID)
{
    if (_sourceList[sourceID]._isPlaying == FALSE)
    {
        return;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->Stop(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._isPlaying = FALSE;
}

void stopSource(unsigned int sourceID)
{
    if (_sourceList[sourceID]._end)
    {
        return;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->Stop(_sourceList[sourceID]._sourceVoice, 0, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._sourceVoice->lpVtbl->FlushSourceBuffers(_sourceList[sourceID]._sourceVoice);
    _sourceList[sourceID]._time = 0.0f;
    _sourceList[sourceID]._isPlaying = FALSE;
    _sourceList[sourceID]._end = TRUE;
}

void setSourceVolume(unsigned int sourceID, float volume)
{
    if (_sourceList[sourceID]._volume == volume)
    {
        return;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->SetVolume(_sourceList[sourceID]._sourceVoice, volume, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._volume = volume;
}

float getSourceVolume(unsigned int sourceID)
{
    return _sourceList[sourceID]._volume;
}

void setSourcePitch(unsigned int sourceID, float pitch)
{
    if (_sourceList[sourceID]._pitch == pitch)
    {
        return;
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->SetFrequencyRatio(_sourceList[sourceID]._sourceVoice, pitch, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._pitch = pitch;
}

float getSourcePitch(unsigned int sourceID)
{
    return _sourceList[sourceID]._pitch;
}

void setSourcePan(unsigned int sourceID, float pan)
{
    if (_sourceList[sourceID]._pan == pan)
    {
        return;
    }
    XAUDIO2_VOICE_DETAILS src;
    _sourceList[sourceID]._sourceVoice->lpVtbl->GetVoiceDetails(_sourceList[sourceID]._sourceVoice, &src);
    if (src.InputChannels > 2)
    {
        return;
    }
    float matrix[4] = {0};
    if (src.InputChannels == 1)
    {
        matrix[0] = 0.5f - pan * 0.5f;
        matrix[1] = 0.5f + pan * 0.5;
    }
    else
    {
        if (pan < 0.0f)
        {
            matrix[0] = 1.0f;
            matrix[1] = 0.0f - pan;
            matrix[2] = 0.0f;
            matrix[3] = 1.0f + pan;
        }
        else if (pan > 0.0f)
        {
            matrix[0] = 1.0f - pan;
            matrix[1] = 0.0f;
            matrix[2] = 0.0f + pan;
            matrix[3] = 1.0f;
        }
        else
        {
            matrix[0] = 1.0f;
            matrix[1] = 0.0f;
            matrix[2] = 0.0f;
            matrix[3] = 1.0f;
        }
    }
    _sourceList[sourceID]._sourceVoice->lpVtbl->SetOutputMatrix(_sourceList[sourceID]._sourceVoice, NULL, src.InputChannels, 2, matrix, XAUDIO2_COMMIT_NOW);
    _sourceList[sourceID]._pan = pan;
}

float getSourcePan(unsigned int sourceID)
{
    return _sourceList[sourceID]._pan;
}

// Render

void setViewport(int x, int y, int w, int h)
{
    glViewport(x, y, w, h);
}

void clearBackground(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawElements(unsigned int vertexID, int count)
{
    glBindVertexArray(vertexID);
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void drawElementsInstanced(unsigned int vertexID, int count, int instanceCount)
{
    glBindVertexArray(vertexID);
    glDrawElementsInstanced(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0, instanceCount);
    glBindVertexArray(0);
}

unsigned int getGLErrorCode()
{
    return glGetError();
}

// Texture

BOOL createTexture(unsigned int *textureID, unsigned int width, unsigned int height, unsigned int channels, const unsigned char *data, BOOL linear)
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    if (linear)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, linear ? GL_LINEAR : GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, linear ? GL_LINEAR_MIPMAP_LINEAR : GL_NEAREST);
    unsigned int format = GL_RGBA;
    unsigned int internalFormat = GL_RGBA8;
    if (channels == 1)
    {
        format = GL_RED;
        internalFormat = GL_R8;
    }
    else if (channels == 2)
    {
        format = GL_RG;
        internalFormat = GL_RG8;
    }
    else if (channels == 3)
    {
        format = GL_RGB;
        internalFormat = GL_RGB8;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    *textureID = texture;
    return TRUE;
}

void destroyTexture(unsigned int textureID)
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glDeleteTextures(1, &textureID);
}

void bindTexture(unsigned int textureID, unsigned int slot)
{
    if (textureID != 0)
    {
        glActiveTexture(GL_TEXTURE0 + slot);
    }
    glBindTexture(GL_TEXTURE_2D, textureID);
}

BOOL updateTexture(unsigned int textureID, unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height, unsigned int channels, const unsigned char *data)
{
    glBindTexture(GL_TEXTURE_2D, textureID);
    unsigned int format = GL_RGBA;
    if (channels == 1)
    {
        format = GL_RED;
    }
    else if (channels == 2)
    {
        format = GL_RG;
    }
    else if (channels == 3)
    {
        format = GL_RGB;
    }
    glTexSubImage2D(GL_TEXTURE_2D, 0, offsetX, offsetY, width, height, format, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    return TRUE;
}

// Buffer

unsigned int createBuffer(const void *data, long long size, BOOL type, BOOL dynamic)
{
    unsigned int bufferID;
    glGenBuffers(1, &bufferID);
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, bufferID);
    glBufferData(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, size * 4, data, dynamic ? GL_STREAM_DRAW : GL_STATIC_DRAW);
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, 0);
    return bufferID;
}

void destroyBuffer(unsigned int bufferID, BOOL type)
{
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &bufferID);
}

void bindBuffer(unsigned int bufferID, BOOL type)
{
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, bufferID);
}

void updateBuffer(unsigned int bufferID, const void *data, long long size, long long offset, BOOL type)
{
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, bufferID);
    glBufferSubData(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, offset * 4, size * sizeof(float), data);
    glBindBuffer(type ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Vertex

unsigned int createVertex(unsigned int elementID)
{
    unsigned int vertexID;
    glGenVertexArrays(1, &vertexID);
    glBindVertexArray(vertexID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementID);
    glBindVertexArray(0);
    return vertexID;
}

void destroyVertex(unsigned int vertexID)
{
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vertexID);
}

void bindVertex(unsigned int vertexID)
{
    glBindVertexArray(vertexID);
}

void setAttribute(unsigned int vertexID, unsigned int arrayID, int location, int size, int offset, int stride, int divisor)
{
    glBindVertexArray(vertexID);
    glBindBuffer(GL_ARRAY_BUFFER, arrayID);
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, size, GL_FLOAT, FALSE, stride * sizeof(float), (void *)(offset * sizeof(float)));
    glVertexAttribDivisor(location, divisor);
    glBindVertexArray(0);
}

// Shader

static char _shaderInfo[1024] = {0};

static int getUniformLocation(unsigned int shaderID, const char *name)
{
    return glGetUniformLocation(shaderID, name);
}

BOOL createShader(unsigned int *shaderID, const char *vertSource, const char *fragSource)
{
    unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertSource, NULL);
    glCompileShader(vertShader);
    int success;
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertShader, 1024, NULL, _shaderInfo);
        glDeleteShader(vertShader);
        return FALSE;
    }
    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSource, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragShader, 1024, NULL, _shaderInfo);
        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        return FALSE;
    }
    unsigned int id = glCreateProgram();
    glAttachShader(id, vertShader);
    glAttachShader(id, fragShader);
    glLinkProgram(id);
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 1024, NULL, _shaderInfo);
        glDetachShader(id, vertShader);
        glDetachShader(id, fragShader);
        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        glDeleteProgram(id);
        return FALSE;
    }
    glDetachShader(id, vertShader);
    glDetachShader(id, fragShader);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    *shaderID = id;
    return TRUE;
}

const char *getShaderInfo()
{
    return _shaderInfo;
}

void destroyShader(unsigned int shaderID)
{
    glUseProgram(0);
    glDeleteProgram(shaderID);
}

void bindShader(unsigned int shaderID)
{
    glUseProgram(shaderID);
}

BOOL setUniform(unsigned int shaderID, const char *name, const void *value, unsigned int dimension, unsigned int count, BOOL type, BOOL matrix)
{
    glUseProgram(shaderID);
    int location = getUniformLocation(shaderID, name);
    if (location == -1)
    {
        glUseProgram(0);
        return FALSE;
    }
    if (dimension == 1)
    {
        if (type)
        {
            glUniform1fv(location, count, value);
        }
        else
        {
            glUniform1iv(location, count, value);
        }
    }
    else if (dimension == 2)
    {
        if (matrix)
        {
            glUniformMatrix2fv(location, count, 1, value);
        }
        else
        {
            if (type)
            {
                glUniform2fv(location, count, value);
            }
            else
            {
                glUniform2iv(location, count, value);
            }
        }
    }
    else if (dimension == 3)
    {
        if (matrix)
        {
            glUniformMatrix3fv(location, count, 1, value);
        }
        else
        {
            if (type)
            {
                glUniform3fv(location, count, value);
            }
            else
            {
                glUniform3iv(location, count, value);
            }
        }
    }
    else if (dimension == 4)
    {
        if (matrix)
        {
            glUniformMatrix4fv(location, count, 1, value);
        }
        else
        {
            if (type)
            {
                glUniform4fv(location, count, value);
            }
            else
            {
                glUniform4iv(location, count, value);
            }
        }
    }
    glUseProgram(0);
    return TRUE;
}

// Frame

unsigned int createFrame()
{
    unsigned int frameID;
    glGenFramebuffers(1, &frameID);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return frameID;
}

void destroyFrame(unsigned int frameID)
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, &frameID);
}

void bindFrame(unsigned int frameID)
{
    glBindFramebuffer(GL_FRAMEBUFFER, frameID);
}

void attachTexture(unsigned int frameID, unsigned int textureID, unsigned int layoutID)
{
    glBindFramebuffer(GL_FRAMEBUFFER, frameID);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + layoutID, GL_TEXTURE_2D, textureID, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

#endif