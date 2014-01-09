/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Jeremy Othieno.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include "renderer.hh"


namespace clockwork {
namespace graphics {

/**
 * @see renderer.factory.hh.
 */
class RendererFactory;

class PointRenderer : public clockwork::graphics::Renderer
{
public:
	/**
	 * @see Renderer::createRenderTask.
	 */
	virtual clockwork::concurrency::RenderTask* createRenderTask
	(
		const clockwork::physics::RigidBody&,
		const clockwork::scene::Viewer&
	) const override final;
private:
	/**
	 * The default constructor. A renderer can only be instantiated by the renderer
	 * factory, as such the default constructor is private.
	 */
	PointRenderer();
	/**
	 * A renderer cannot be copied.
	 */
	PointRenderer(const PointRenderer&) = delete;
	PointRenderer& operator=(const PointRenderer&) = delete;
	/**
	 * Friendship between the renderer factory and this renderer.
	 */
	friend clockwork::graphics::RendererFactory;
};

} // namespace graphics
} // namespace clockwork
