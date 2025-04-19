using System.Runtime.InteropServices;

namespace GameEngine.Interop;

public struct Vector
{
    public float x;
    public float y;
}

internal class ViewportAdapter : IDisposable
{
    private IntPtr handle;

    [DllImport("GameInterop.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr CreateViewport(Vector size, Vector center);

    [DllImport("GameInterop.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern void DestroyViewport(IntPtr handle);

    [DllImport("GameInterop.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern Vector GetViewportSize(IntPtr handle);

    [DllImport("GameInterop.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern Vector GetViewportCenter(IntPtr handle);

    [DllImport("GameInterop.dll", CallingConvention = CallingConvention.Cdecl)]
    private static extern void ZoomViewport(IntPtr handle, float scale);

    public ViewportAdapter(Vector size, Vector center)
    {
        handle = CreateViewport(size, center);
    }

    public Vector Size => GetViewportSize(handle);
    public Vector Center => GetViewportCenter(handle);

    public void Zoom(float scale) => ZoomViewport(handle, scale);

    public void Dispose()
    {
        DestroyViewport(handle);
    }
}
