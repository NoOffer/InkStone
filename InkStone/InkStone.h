#pragma once

#include "src/Math/Math.h"

#include "src/Window.h"
#include "src/UI.h"

#include "src/Layer.h"
#include "src/LayerStack.h"

#include "src/Component/Camera.h"
#include "src/Component/Mesh.h"

#include "src/Event/Event.h"
#include "src/Event/ApplicationEvent.h"
#include "src/Event/KeyEvent.h"
#include "src/Event/MouseEvent.h"

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