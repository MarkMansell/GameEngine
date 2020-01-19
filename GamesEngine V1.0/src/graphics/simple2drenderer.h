#pragma once

#include <deque>
#include "static_sprite.h"
#include "renderer2d.h"

namespace Engine{
	namespace graphics {
	
		class Simple2DRenderer : public Renderer2D
		{

		private:
			std::deque<const StaticSprite*> m_RenderQueue;
		public:
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		};
	
	
} }