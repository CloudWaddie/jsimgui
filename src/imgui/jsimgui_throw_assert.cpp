// See jsimgui_throw_assert.h.
#include <emscripten.h>

EM_JS(void, jsimgui_assert_failed, (const char* expr, const char* file, int line), {
	const error = new Error("IM_ASSERT(" + UTF8ToString(expr) + ") failed at " + UTF8ToString(file) + ":" + line);
	error.name = "ImGuiAssertError";
	throw error;
});
