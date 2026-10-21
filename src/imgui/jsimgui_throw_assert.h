// Used with `node build.ts --throw-asserts` (via IMGUI_USER_CONFIG).
// A failed IM_ASSERT throws a JavaScript Error instead of aborting the WebAssembly runtime,
// so a host page can catch it, report it and keep running. The C++ stack is unwound without
// running destructors, which Dear ImGui tolerates (its error recovery cleans up the frame).
#pragma once

#ifdef __cplusplus
extern "C"
#endif
void jsimgui_assert_failed(const char* expr, const char* file, int line);

#define IM_ASSERT(_EXPR) ((_EXPR) ? (void)0 : jsimgui_assert_failed(#_EXPR, __FILE__, __LINE__))
