// Author: Luke Chikkala

#include "libs/imgui.h"
#include "libs/imgui_impl_glfw.h"
#include "libs/imgui_impl_opengl3.h"

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	int window_width 	= 400; 	int window_height	= 200;
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Background Color", NULL, NULL); // Replace first NULL with 'glfwGetPrimaryMonitor()' to run Full Screen on First Monitor.
	if (window == NULL)
	{
		std::cout << "Failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	// ImGUI Stuff
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	// --> DOCKING
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PopStyleVar(2);
	// --> End of DOCKING
	ImGuiIO& io = ImGui::GetIO();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		float Red, Green, Blue;
		glClearColor(Red, Green, Blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Hello");
		ImGui::Text("World");

		ImGui::SliderFloat("Red", &Red, 0.0f, 1.0f);
		ImGui::SliderFloat("Green", &Green, 0.0f, 1.0f);
		ImGui::SliderFloat("Blue", &Blue, 0.0f, 1.0f);

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}