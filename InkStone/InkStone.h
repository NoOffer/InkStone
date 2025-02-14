#pragma once

#include "entt.hpp"

#include "src/Core.h"

#include "src/Layer.h"
#include "src/LayerStack.h"
#include "src/System.h"
#include "src/Time.h"

#include "src/Event/Event.h"
#include "src/Event/ApplicationEvent.h"
#include "src/Event/KeyEvent.h"
#include "src/Event/MouseEvent.h"

#include "src/Game/Component/GameComponent.h"
#include "src/Game/Component/Camera.h"
#include "src/Game/Component/MeshInfo.h"
#include "src/Game/Component/Transform.h"

#include "src/Game/GameObject.h"

#include "src/Game/Scene.h"

#include "src/Game/System/GameSystem.h"
#include "src/Game/System/CameraController.h"
#include "src/Game/System/MeshRenderer.h"

#include "src/Math/Math.h"

#include "src/Rendering/FrameBuffer.h"
#include "src/Rendering/Mesh.h"
#include "src/Rendering/Renderer.h"
#include "src/Rendering/RenderingDataBuffer.h"
#include "src/Rendering/Shader.h"
#include "src/Rendering/Texture.h"
#include "src/Rendering/VertexArray.h"

#include "src/UI/UI.h"

#include "src/Window/Window.h"

#include "src/Application.h"

#ifdef NXTN_PLATFORM_WINDOWS
//extern NXTN::Application* NXTN::CreateApplication();

int main(int argc, char** argv)
{
	//char cwd[MAX_PATH];
	//if (GetCurrentDirectoryA(MAX_PATH, cwd))
	//{
	//	std::cout << "Current Working Directory: " << cwd << std::endl;
	//}

	NXTN::Application* app = NXTN::CreateApplication();
	app->Run();
	delete app;
}
#endif // NXTN_PLATFORM_WINDOWS