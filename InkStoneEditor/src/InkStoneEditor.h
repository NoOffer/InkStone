#pragma once

#include "InkStone.h"

#include "include/imgui/imgui.h"

namespace NXTN {
	class EditorLayer : public Layer
	{
	public:
		EditorLayer(unsigned int windowWidth, unsigned int windowHeight);

		virtual void Update() override;
		virtual void UIUpdate() override;

		virtual bool OnEvent(Event*& event_ptr) override;

	private:
		std::shared_ptr<NXTN::Camera> m_SceneCamera;
		std::shared_ptr<NXTN::FrameBuffer> m_FrameBuffer;  // Temp
		std::shared_ptr<NXTN::GameObject> m_TestObj;
		std::shared_ptr<NXTN::Texture2D> m_Texture;
		std::shared_ptr<NXTN::Shader> m_Shader;

		ImGuiID m_DockspaceID;
		ImGuiWindowFlags m_WindowFlag;

		ImVec2 m_ViewportSize;
	};

	class InkStoneEditor : public Application
	{
	public:
		InkStoneEditor();
		~InkStoneEditor() {}

		virtual void Update() override;
	};
}

