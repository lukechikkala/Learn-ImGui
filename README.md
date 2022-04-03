# Learn-ImGui

## 0_demo
![0_demo](0_demo/docs/0_demo.png)

## 1_hello_world
![1_hello_world](1_hello_world/docs/1_hello_world.png)

## 2_basic_rgb
![2_basic_rgb](2_basic_rgb/docs/2_basic_rgb.png)

## 3_basic_docking
![3_basic_docking](3_basic_docking/docs/3_basic_docking.png)

This is the same window as before, except that now, "Hello World" window is docked directly onto our OpenGL Window.<br>
This example deserves it's own folder as, at the time of writing this, I couldn't find how to create a simple docking mechanism anywhere on the browsable internet.

To achieve this, add the following lines inside the OpenGL's loop:
```C++
// #################### DOCKING
const ImGuiViewport* viewport = ImGui::GetMainViewport();
ImGui::SetNextWindowPos(viewport->WorkPos);
ImGui::SetNextWindowSize(viewport->WorkSize);
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
ImGui::PopStyleVar(2);
// #################### End of DOCKING
```


Note: From the picture, it should be pretty obvious that the background color is now red.<br>
However, since ImGui is now docked and sits on top of the OpenGL window, it's original color is only seen through the mercy of ImGui's window transparency.