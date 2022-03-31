compiler		=	g++

cpp_standard	=	-std=c++11

framewerke		=	-framework OpenGL		\
				 	-framework Cocoa		\
				 	-framework IOKit		\
				 	-framework CoreVideo

libs			=	libs/imgui.cpp				\
					libs/imgui_demo.cpp 		\
					libs/imgui_draw.cpp 		\
					libs/imgui_tables.cpp 		\
					libs/imgui_widgets.cpp 		\
					libs/imgui_impl_glfw.cpp 	\
					libs/imgui_impl_opengl3.cpp	\

flags			=	-lglfw

final_name		=	app

success: compile
	@echo "-------------------------------------"
	@echo "\tSuccessfully Compiled"
	@echo "-------------------------------------"

compile:
	$(compiler) $(cpp_standard) $(framewerke) main.cpp $(libs) $(flags) -o $(final_name)

run:
	./app
