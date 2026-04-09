/*
    FIRLIB -
        相比FIRSLIB极大精简了API数量，并且获得了更底层的控制，一共只有15个函数

        FIRLIB使用最少依赖，只是用了Windows.h和必要的使用WASAPI相关的头文件
        需要链接user32.dll（创建窗口、处理输入和多线程等），gdi32.dll和opengl32.dll（OpenGL相关），ole32.dll（加载音频系统）
        由于使用了WASAPI因此FIRLIB最低系统需求是Windows Vista，如果没有音频需求可以支持更早的Windows系统

        FIRLIB并不提供简便的游戏开发体验，但是可以获得足够的底层控制，去除所有不必要的功能，因此库非常小
        要使用FIRLIB非常容易，它是单头文件的，纯C代码编写，代码量只有几百行，你可以直接将fir.h加入到自己的项目中
        或者使用宏先编译成静态链接库，之后可以链接进自己的C项目开发
        也可以绑定到其他编程语言使用，由于它的API数量非常少，因此绑定工作会很简单

        FIRLIB的源代码非常简单，我将它作为公共领域发布，我不保证它的可靠性，也不承担任何责任，我也无意处理任何法律纠纷

        FIRLIB去掉了原FIRSLIB的S，有降级之意，表示更底层的控制，FIR翻译为冷杉，是中国一种古老的树种，而FIRLIB也使用了非常“古老”的技术
*/

// #define FIRLIB_IMPLEMENTATION
// #define FIRAPI_EXPORT
// #define FIRAPI_IMPORT

#ifndef FIR_H
#define FIR_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef FIRAPI_EXPORT
#define FIRAPI __declspec(dllexport)
#elifdef FIRAPI_IMPORT
#define FIRAPI __declspec(dllimport)
#else
#define FIRAPI
#endif

    // Windows系统的虚拟键码（含鼠标，仅常用）

#define KC_MouseLeft 0x01
#define KC_MouseRight 0x02
#define KC_MouseMiddle 0x04
#define KC_Backspace 0x08
#define KC_Tab 0x09
#define KC_Return 0x0D
#define KC_Pause 0x13
#define KC_CapsLock 0x14
#define KC_Esc 0x1B
#define KC_Space 0x20
#define KC_PageUp 0x21
#define KC_PageDown 0x22
#define KC_End 0x23
#define KC_Home 0x24
#define KC_LeftArrow 0x25
#define KC_UpArrow 0x26
#define KC_RightArrow 0x27
#define KC_DownArrow 0x28
#define KC_Insert 0x2D
#define KC_Delete 0x2E
#define KC_Alpha0 0x30
#define KC_Alpha1 0x31
#define KC_Alpha2 0x32
#define KC_Alpha3 0x33
#define KC_Alpha4 0x34
#define KC_Alpha5 0x35
#define KC_Alpha6 0x36
#define KC_Alpha7 0x37
#define KC_Alpha8 0x38
#define KC_Alpha9 0x39
#define KC_A 0x41
#define KC_B 0x42
#define KC_C 0x43
#define KC_D 0x44
#define KC_E 0x45
#define KC_F 0x46
#define KC_G 0x47
#define KC_H 0x48
#define KC_I 0x49
#define KC_J 0x4A
#define KC_K 0x4B
#define KC_L 0x4C
#define KC_M 0x4D
#define KC_N 0x4E
#define KC_O 0x4F
#define KC_P 0x50
#define KC_Q 0x51
#define KC_R 0x52
#define KC_S 0x53
#define KC_T 0x54
#define KC_U 0x55
#define KC_V 0x56
#define KC_W 0x57
#define KC_X 0x58
#define KC_Y 0x59
#define KC_Z 0x5A
#define KC_LeftWin 0x5B
#define KC_RightWin 0x5C
#define KC_Menu 0x5D
#define KC_Keypad0 0x60
#define KC_Keypad1 0x61
#define KC_Keypad2 0x62
#define KC_Keypad3 0x63
#define KC_Keypad4 0x64
#define KC_Keypad5 0x65
#define KC_Keypad6 0x66
#define KC_Keypad7 0x67
#define KC_Keypad8 0x68
#define KC_Keypad9 0x69
#define KC_KeypadMultiply 0x6A
#define KC_KeypadPlus 0x6B
#define KC_KeypadMinus 0x6D
#define KC_KeypadPeriod 0x6E
#define KC_KeypadDevide 0x6F
#define KC_F1 0x70
#define KC_F2 0x71
#define KC_F3 0x72
#define KC_F4 0x73
#define KC_F5 0x74
#define KC_F6 0x75
#define KC_F7 0x76
#define KC_F8 0x77
#define KC_F9 0x78
#define KC_F10 0x79
#define KC_F11 0x7A
#define KC_F12 0x7B
#define KC_NumLock 0x90
#define KC_ScrollLock 0x91
#define KC_LeftShift 0xA0
#define KC_RightShift 0xA1
#define KC_LeftCtrl 0xA2
#define KC_RightCtrl 0xA3
#define KC_LeftAlt 0xA4
#define KC_RightAlt 0xA5
#define KC_Semicolon 0xBA
#define KC_Equals 0xBB
#define KC_Comma 0xBC
#define KC_Minus 0xBD
#define KC_Period 0xBE
#define KC_Slash 0xBF
#define KC_BackQuote 0xC0
#define KC_LeftBracket 0xDB
#define KC_BackSlash 0xDC
#define KC_RightBracket 0xDD
#define KC_Quote 0xDE

    // 用于创建全屏或窗口化的程序

#define FULLSCREEN ((unsigned int)0)
#define WINDOWED(width, height) ((unsigned short)(width) | ((unsigned int)(height) << 16))

    // 创建窗口，参数size为0时创建全屏窗口，不为0时LOWORD=w，HIWORD=h，title为窗口的标题(UTF-16)，返回实际的窗口分辨率（w=LOWORD, h=HIWORD）
    FIRAPI unsigned int initWindow(unsigned int size, const unsigned short *title);

    // 获取窗口句柄，通常用不到，除非需要使用窗口的拓展功能
    FIRAPI void *getWindowHandle();

    // 主动关闭窗口
    FIRAPI void closeWindow();

    // 检查窗口是否关闭，用于主循环的退出条件
    FIRAPI int shouldClose();

    // 检查窗口是否聚焦，可以和检测键盘鼠标输入配合使用
    FIRAPI int isWindowFocused();

    // 检查鼠标或键盘按键是否按下
    FIRAPI int isKeyPress(int keyCode);

    // 获取鼠标位置，如果创建了窗口则是以窗口客户区左上角为原点，否则以显示器左上角为原点
    FIRAPI void getMousePosition(float *x, float *y);

    // 获取从窗口初始化以来的时间（毫秒）
    FIRAPI double getTotalTimeMs();

    // 从显卡驱动获取支持的OpenGL函数，若为1.1版本及以前的函数则从opengl32.dll获取
    FIRAPI long long getGLFunc(const char *name);

    // 交换屏幕缓冲区，可以设置wglSwapIntervalEXT（需通过getGLFunc绑定）改变垂直同步的行为
    FIRAPI void swapScreenBuffers();

    // 初始化音频，参数为预期的缓冲区毫秒数，返回实际的缓冲区帧数
    FIRAPI unsigned int initAudio(unsigned int bufferSizeMs);

    // 清理音频，通常放在程序退出之前
    FIRAPI void cleanupAudio();

    // 获取空白缓冲区帧数
    FIRAPI unsigned int getEmptyBufferFrameCount();

    // 提交缓冲区，16位深，44100hz采样率，双声道
    FIRAPI void submitBufferCD(const short *data, unsigned int frameCount);

    // 阻塞一会儿（非忙等），实际睡眠时长受系统精度影响，大概为15.6ms
    FIRAPI void sleep(unsigned int ms);

#ifdef FIRLIB_IMPLEMENTATION

#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN
#define COBJMACROS
#define INITGUID

#include <Windows.h>
#include <mmdeviceapi.h>
#include <Audioclient.h>

    static HWND g_hWnd = NULL;
    static HDC g_hDC = NULL;
    static HGLRC g_hGLRC = NULL;
    static volatile BOOL g_shouldClose = FALSE;

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (uMsg == WM_CLOSE)
        {
            DestroyWindow(g_hWnd);
        }
        else if (uMsg == WM_DESTROY)
        {
            wglMakeCurrent(NULL, NULL);
            if (g_hGLRC != NULL)
            {
                wglDeleteContext(g_hGLRC);
                g_hGLRC = NULL;
            }
            if (g_hWnd != NULL && g_hDC != NULL)
            {
                ReleaseDC(g_hWnd, g_hDC);
                g_hDC = NULL;
            }
            PostQuitMessage(0);
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    static const unsigned short *g_windowTitle = NULL;
    static unsigned int g_windowSize = 0;

    static DWORD WINAPI MessageThreadFunc(LPVOID param)
    {
        WNDCLASS wc = {0};
        wc.style = CS_OWNDC;
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = L"FIRWND";
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

        RegisterClass(&wc);

        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);
        DWORD style = WS_POPUP;
        if (g_windowSize != 0)
        {
            style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
            RECT rect = {0, 0, LOWORD(g_windowSize), HIWORD(g_windowSize)};
            AdjustWindowRect(&rect, style, FALSE);
            width = rect.right - rect.left;
            height = rect.bottom - rect.top;
        }
        else
        {
            g_windowSize = WINDOWED(width, height);
        }

        g_hWnd = CreateWindow(wc.lpszClassName, g_windowTitle, style, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, wc.hInstance, NULL);

        g_hDC = GetDC(g_hWnd);

        PIXELFORMATDESCRIPTOR pfd = {0};
        pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.cStencilBits = 8;
        pfd.iLayerType = PFD_MAIN_PLANE;

        int format = ChoosePixelFormat(g_hDC, &pfd);
        SetPixelFormat(g_hDC, format, &pfd);

        g_hGLRC = wglCreateContext(g_hDC);

        ShowWindow(g_hWnd, SW_SHOW);

        SetEvent((HANDLE)param);

        MSG msg = {0};
        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        g_shouldClose = TRUE;

        return 0;
    }

    static LARGE_INTEGER g_clockFreq = {0};
    static LARGE_INTEGER g_clockStart = {0};

    FIRAPI unsigned int initWindow(unsigned int size, const unsigned short *title)
    {
        HANDLE windowInitedEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

        g_windowSize = size;
        g_windowTitle = title;

        HANDLE hMsgTrd = CreateThread(NULL, 0, MessageThreadFunc, (void *)windowInitedEvent, 0, NULL);

        WaitForSingleObject(windowInitedEvent, INFINITE);

        CloseHandle(windowInitedEvent);

        CloseHandle(hMsgTrd);

        wglMakeCurrent(g_hDC, g_hGLRC);

        QueryPerformanceFrequency(&g_clockFreq);
        QueryPerformanceCounter(&g_clockStart);

        return g_windowSize;
    }

    FIRAPI void *getWindowHandle()
    {
        return g_hWnd;
    }

    FIRAPI void closeWindow()
    {
        SendMessage(g_hWnd, WM_CLOSE, 0, 0);
    }

    FIRAPI BOOL shouldClose()
    {
        return g_shouldClose;
    }

    FIRAPI BOOL isWindowFocused()
    {
        return GetForegroundWindow() == g_hWnd;
    }

    FIRAPI int isKeyPress(int keyCode)
    {
        return !!(GetAsyncKeyState(keyCode) & 0x8000);
    }

    FIRAPI void getMousePosition(float *x, float *y)
    {
        POINT point;
        GetCursorPos(&point);
        if (g_hWnd != NULL)
        {
            ScreenToClient(g_hWnd, &point);
        }
        *x = point.x;
        *y = point.y;
    }

    FIRAPI double getTotalTimeMs()
    {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (double)(now.QuadPart - g_clockStart.QuadPart) * 1000.0 / g_clockFreq.QuadPart;
    }

    FIRAPI long long getGLFunc(const char *name)
    {
        PROC func = wglGetProcAddress(name);
        if (func == NULL)
        {
            func = GetProcAddress(GetModuleHandleA("opengl32.dll"), name);
        }
        return (long long)func;
    }

    FIRAPI void swapScreenBuffers()
    {
        SwapBuffers(g_hDC);
    }

    static IAudioClient *g_audioClient = NULL;
    static IAudioRenderClient *g_renderClient = NULL;

    static unsigned int g_bufferFrameCount = 0;

    FIRAPI unsigned int initAudio(unsigned int bufferSizeMs)
    {
        CoInitializeEx(NULL, COINIT_MULTITHREADED);

        IMMDeviceEnumerator *pEnum;
        CoCreateInstance(&CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL, &IID_IMMDeviceEnumerator, (void **)&pEnum);

        IMMDevice *pDevice;
        IMMDeviceEnumerator_GetDefaultAudioEndpoint(pEnum, eRender, eConsole, &pDevice);

        IMMDeviceEnumerator_Release(pEnum);

        IMMDeviceActivator_Activate(pDevice, &IID_IAudioClient, CLSCTX_ALL, NULL, (void **)&g_audioClient);

        IMMDevice_Release(pDevice);

        WAVEFORMATEX wfx = {0};
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 2;
        wfx.nSamplesPerSec = 44100;
        wfx.wBitsPerSample = 16;
        wfx.nBlockAlign = 4;
        wfx.nAvgBytesPerSec = 176400;

        IAudioClient_Initialize(g_audioClient, AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM | AUDCLNT_STREAMFLAGS_SRC_DEFAULT_QUALITY, bufferSizeMs * 10000, 0, &wfx, NULL);

        IAudioClient_GetService(g_audioClient, &IID_IAudioRenderClient, (void **)&g_renderClient);

        IAudioClient_GetBufferSize(g_audioClient, &g_bufferFrameCount);

        unsigned char *preFillData;
        IAudioRenderClient_GetBuffer(g_renderClient, g_bufferFrameCount, &preFillData);

        memset(preFillData, 0, g_bufferFrameCount * wfx.nBlockAlign);

        IAudioRenderClient_ReleaseBuffer(g_renderClient, g_bufferFrameCount, 0);

        IAudioClient_Start(g_audioClient);

        return g_bufferFrameCount;
    }

    FIRAPI void cleanupAudio()
    {
        IAudioClient_Stop(g_audioClient);

        IAudioRenderClient_Release(g_renderClient);
        g_renderClient = NULL;

        IAudioClient_Release(g_audioClient);
        g_audioClient = NULL;

        CoUninitialize();
    }

    FIRAPI unsigned int getEmptyBufferFrameCount()
    {
        unsigned int paddingFrameCount;
        IAudioClient_GetCurrentPadding(g_audioClient, &paddingFrameCount);
        return g_bufferFrameCount - paddingFrameCount;
    }

    FIRAPI void submitBufferCD(const short *data, unsigned int frameCount)
    {
        unsigned char *pData;
        IAudioRenderClient_GetBuffer(g_renderClient, frameCount, &pData);

        memcpy(pData, data, frameCount * 2 * sizeof(short));

        IAudioRenderClient_ReleaseBuffer(g_renderClient, frameCount, 0);
    }

    FIRAPI void sleep(unsigned int ms)
    {
        Sleep(ms);
    }

#ifdef __cplusplus
}
#endif

#endif

#endif