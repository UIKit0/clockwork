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


namespace clockwork {

/**
 * @see render.task.hh
 */
namespace concurrency { class RenderTask; }

/**
 * @see rigid.body.hh
 */
namespace physics { class RigidBody; }

/**
 * @see scene.viewer.hh
 */
namespace scene { class Viewer; }


namespace graphics {

class Renderer
{
public:
	/**
	 * Types of renderers.
	 */
	enum class Type
	{
		Point,
		Wireframe,
		Random,
		Depth,
		Normals,
		Texture,
		Constant,
		Phong,
		Cel,
		Bump,
		Deferred
	};
	/**
	 * Return the renderer's type.
	 */
	const Renderer::Type& getType() const;
	/**
	 * Create a new render task.
	 * @param body the rigid body that contains the 3D model and transformation matrices.
	 * @param viewer the viewer containing the scene's point of view.
	 */
	virtual clockwork::concurrency::RenderTask* createRenderTask
	(
		const clockwork::physics::RigidBody& body,
		const clockwork::scene::Viewer& viewer

	) const = 0;
protected:
	/**
	 * Instantiate a renderer with a given type.
	 */
	Renderer(const Renderer::Type& type);
private:
	/**
	 * This renderer's type.
	 */
	const Renderer::Type _type;
};

} // namespace graphics
} // namespace clockwork
