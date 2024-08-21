#pragma once

#include "src/Window.h"

#include "src/Component/Camera.h"
#include "src/Component/Mesh.h"

#include "src/Rendering/Renderer.h"
#include "src/Rendering/RenderingDataBuffer.h"
#include "src/Rendering/Shader.h"
#include "src/Rendering/VertexArray.h"

#include "src/Application.h"

#ifdef NXTN_PLATFORM_WINDOWS
//extern NXTN::Application* NXTN::CreateApplication();

int main(int argc, char** argv)
{
	NXTN::Application* app = NXTN::CreateApplication();
	app->Run();
	delete app;
}
#endif // NXTN_PLATFORM_WINDOWS