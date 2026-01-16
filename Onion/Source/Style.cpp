#include "Global.h"
#include "Font.h"

void Style::Apply()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();

	// --- Font Loading ---
	// Note: This should ideally be called once during your App's initialization, 
	static bool bIsFontLoaded = false;
	if (!bIsFontLoaded) {
		ImFontConfig font_cfg;
		font_cfg.FontDataOwnedByAtlas = false; // Important since it's a static array
		io.Fonts->AddFontFromMemoryTTF((void*)Rubik_Regular, sizeof(Rubik_Regular), 16.0f, &font_cfg);
		io.Fonts->Build();
		bIsFontLoaded = true;
	}

	// --- 2. Geometry & Smoothness ---
	style.WindowRounding = 8.0f;
	style.ChildRounding = 8.0f;
	style.FrameRounding = 8.0f;
	style.PopupRounding = 8.0f;
	style.ScrollbarRounding = 8.0f;
	style.GrabRounding = 8.0f;
	style.TabRounding = 8.0f;

	style.WindowPadding = ImVec2(15, 15);
	style.FramePadding = ImVec2(12, 8);
	style.ItemSpacing = ImVec2(10, 10);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);

	style.WindowBorderSize = 1.0f;
	style.FrameBorderSize = 0.0f;
	style.AntiAliasedLines = true;
	style.AntiAliasedFill = true;

	// --- 3. Color Palette: High Contrast Blue ---
	ImVec4* colors = style.Colors;

	// --- BUTTON COLORS ---
	// A vibrant, solid blue
	ImVec4 btnActiveBlue = ImVec4(0.06f, 0.45f, 0.91f, 1.00f); // #1073E9
	ImVec4 btnHoverBlue = ImVec4(0.15f, 0.56f, 1.00f, 1.00f); // Electric Blue #268FFF
	ImVec4 btnStaticBlue = ImVec4(0.12f, 0.38f, 0.76f, 1.00f); // Deep Primary Blue

	// Background & Surface
	colors[ImGuiCol_WindowBg] = ImVec4(0.07f, 0.07f, 0.08f, 1.00f); // Deep Charcoal
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.09f, 0.09f, 0.11f, 1.00f);

	// Text
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);

	// Borders
	colors[ImGuiCol_Border] = ImVec4(0.18f, 0.18f, 0.22f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.18f, 0.18f, 0.22f, 1.00f);

	// Title Bar
	colors[ImGuiCol_TitleBg] = ImVec4(0.05f, 0.05f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.05f, 0.05f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.50f);

	// Inputs / Frames (Darker to make buttons pop)
	colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.16f, 0.16f, 0.19f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.18f, 0.22f, 1.00f);

	// --- Stand-Out Buttons ---
	colors[ImGuiCol_Button] = btnStaticBlue;
	colors[ImGuiCol_ButtonHovered] = btnHoverBlue;
	colors[ImGuiCol_ButtonActive] = btnActiveBlue;

	// Checkbox & Sliders
	colors[ImGuiCol_CheckMark] = btnHoverBlue;
	colors[ImGuiCol_SliderGrab] = btnStaticBlue;
	colors[ImGuiCol_SliderGrabActive] = btnHoverBlue;

	// Tabs & Headers
	colors[ImGuiCol_Header] = ImVec4(0.16f, 0.16f, 0.19f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.20f, 0.20f, 0.25f, 1.00f);
	colors[ImGuiCol_HeaderActive] = btnStaticBlue;

	colors[ImGuiCol_Tab] = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
	colors[ImGuiCol_TabHovered] = btnHoverBlue;
	colors[ImGuiCol_TabActive] = btnStaticBlue;
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);

	// Scrollbar
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.07f, 0.07f, 0.08f, 1.00f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.25f, 0.28f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.35f, 0.35f, 0.38f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.45f, 0.45f, 0.48f, 1.00f);

	// Selection
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.15f, 0.56f, 1.00f, 0.30f);
	colors[ImGuiCol_NavHighlight] = btnHoverBlue;
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.65f);
}