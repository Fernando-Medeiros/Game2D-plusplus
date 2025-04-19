#pragma once

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

    struct Vector {
	  int x;
	  int y;
    };

    typedef void* ViewportHandle;

    DLL_EXPORT ViewportHandle CreateViewport(Vector size, Vector center);
    DLL_EXPORT void DestroyViewport(ViewportHandle handle);
    DLL_EXPORT Vector GetViewportSize(ViewportHandle handle);
    DLL_EXPORT Vector GetViewportCenter(ViewportHandle handle);
    DLL_EXPORT void ZoomViewport(ViewportHandle handle, float scale);

#ifdef __cplusplus
}
#endif
