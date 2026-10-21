// See jsimgui_throw_assert.h.
#include <emscripten.h>

// EM_JS functions are JS imports and can only be called from the translation unit that defines
// them, so IM_ASSERT goes through the plain C function below.
EM_JS(void, jsimgui_throw_assert_error, (const char* expr, const char* file, int line), {
	const error = new Error("IM_ASSERT(" + UTF8ToString(expr) + ") failed at " + UTF8ToString(file) + ":" + line);
	error.name = "ImGuiAssertError";
	throw error;
});

extern "C" void jsimgui_assert_failed(const char* expr, const char* file, int line) {
	jsimgui_throw_assert_error(expr, file, line);
}
