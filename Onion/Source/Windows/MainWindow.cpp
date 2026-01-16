#include "../Global.h"

void MainWindow::Render()
{
	// Basic Metadata
	ImGui::TextDisabled("App Version: 1.0.0");
	ImGui::Text("Build on:");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(0.54f, 0.70f, 0.97f, 1.00f), __DATE__);
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(0.54f, 0.70f, 0.97f, 1.00f), __TIME__);

	ImGui::Separator();
	ImGui::Spacing();

	// Section: Interactive Elements
	if (ImGui::CollapsingHeader("UI Component Preview", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::TextWrapped("This window showcases the Google-inspired dark theme with Rubik font and high-contrast blue accents.");

		static char buffer[64] = "Modern C++ Template";
		ImGui::InputText("Project Name", buffer, IM_ARRAYSIZE(buffer));

		static float slider_val = 0.5f;
		ImGui::SliderFloat("Performance Scale", &slider_val, 0.0f, 1.0f);

		static bool check_val = true;
		ImGui::Checkbox("Enable Hardware Acceleration", &check_val);

		ImGui::Spacing();

		// Demonstrating the "Stand Out" Buttons
		ImGui::Text("Action Center:");
		if (ImGui::Button("Primary Action", ImVec2(120, 35))) {
			// Logic here
		}
		ImGui::SameLine();
		if (ImGui::Button("Secondary", ImVec2(120, 35))) {
			// Logic here
		}
	}

	// Section: Status
	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Text("System Status:");
	ImGui::SameLine();

	// Simple status indicator using a colored bullet
	ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "ONLINE");
}