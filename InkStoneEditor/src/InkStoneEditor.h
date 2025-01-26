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
		virtual bool OnEvent(NXTN::Event& event) override;

	private:
		std::shared_ptr<NXTN::Camera> m_Camera;
		std::shared_ptr<NXTN::FrameBuffer> m_FrameBuffer;  // Temp
		std::shared_ptr<NXTN::Mesh> m_Mesh;
		std::shared_ptr<NXTN::Texture2D> m_Texture;
		std::shared_ptr<NXTN::Shader> m_Shader;

		ImGuiID m_DockspaceID;
		ImGuiWindowFlags m_WindowFlag;
	};

	class InkStoneEditor : public Application
	{
	public:
		InkStoneEditor();
		~InkStoneEditor() {}

		virtual void Update() override;
	};
}

