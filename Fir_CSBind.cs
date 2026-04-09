using System.Runtime.InteropServices;

namespace FIRCS;

public enum KeyCode : int
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
}

public static partial class FIRAPI
{
    [LibraryImport("fir.dll", StringMarshalling = StringMarshalling.Utf16)]
    private static partial uint initWindow(uint size, string title);

    [LibraryImport("fir.dll")]
    private static partial nint getWindowHandle();

    [LibraryImport("fir.dll")]
    private static partial void closeWindow();

    [LibraryImport("fir.dll")]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static partial bool shouldClose();

    [LibraryImport("fir.dll")]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static partial bool isWindowFocused();

    [LibraryImport("fir.dll")]
    [return: MarshalAs(UnmanagedType.Bool)]
    private static partial bool isKeyPress(int keyCode);

    [LibraryImport("fir.dll")]
    private static partial void getMousePosition(out float x, out float y);

    [LibraryImport("fir.dll")]
    private static partial double getTotalTimeMs();

    [LibraryImport("fir.dll", StringMarshalling = StringMarshalling.Utf8)]
    private static partial nint getGLFunc(string name);

    [LibraryImport("fir.dll")]
    private static partial void swapScreenBuffers();

    [LibraryImport("fir.dll")]
    private static partial uint initAudio(uint bufferSizeMs);

    [LibraryImport("fir.dll")]
    private static partial void cleanupAudio();

    [LibraryImport("fir.dll")]
    private static partial uint getEmptyBufferFrameCount();

    [LibraryImport("fir.dll")]
    private static partial void submitBufferCD(nint data, uint frameCount);

    [LibraryImport("fir.dll")]
    private static partial void sleep(uint ms);

    public static (int width, int height) InitWindow(int width, int height, string title, bool isFullscreen = false)
    {
        uint result;

        if (isFullscreen == true)
        {
            result = initWindow(0, title);
        }
        else
        {
            result = initWindow((uint)(width | height << 16), title);
        }

        return ((short)result, (short)(result >> 16));
    }

    public static nint GetWindowHandle() => getWindowHandle();

    public static void CloseWindow() => closeWindow();

    public static bool ShouldClose() => shouldClose();

    public static bool IsWindowFocused() => isWindowFocused();

    public static bool IsKeyPress(KeyCode keyCode) => isKeyPress((int)keyCode);

    public static (float x, float y) GetMousePosition()
    {
        getMousePosition(out float x, out float y);
        return (x, y);
    }

    public static double GetTotalTimeMs() => getTotalTimeMs();

    public static T GetGLFunc<T>(string name) where T : System.Delegate => Marshal.GetDelegateForFunctionPointer<T>(getGLFunc(name));

    public static void SwapScreenBuffers() => swapScreenBuffers();

    public static uint InitAudio(uint bufferSizeMs) => initAudio(bufferSizeMs);

    public static void CleanupAudio() => cleanupAudio();

    public static uint GetEmptyBufferFrameCount() => getEmptyBufferFrameCount();

    public static void SubmitBufferCD(short[] data, uint frameCount)
    {
        unsafe
        {
            fixed (short* ptr = data)
            {
                submitBufferCD((nint)ptr, frameCount);
            }
        }
    }

    public static void Sleep(uint ms) => sleep(ms);
}
