/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Jeremy Othieno.
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

#include "polygon.render.algorithm.hh"


namespace clockwork {
namespace graphics {

/**
 * @see render.algorithm.factory.hh.
 */
class RenderAlgorithmFactory;

/**
 * A wireframe render algorithm.
 */
class WireframeRenderAlgorithm : public PolygonRenderAlgorithm
{
friend class RenderAlgorithmFactory;
public:
   /**
    * Rasterise each triangular polygonal face's piecewise linear curve, under a given set of render parameters.
    * @see RenderAlgorithm::rasterise.
    */
   void rasterise(const RenderAlgorithm::Parameters&, const VertexArray&) const override final;
private:
   /**
    * The WireframeRenderAlgorithm is a singleton, and only instantiable by the RenderAlgorithmFactory.
    */
   WireframeRenderAlgorithm();
   WireframeRenderAlgorithm(const WireframeRenderAlgorithm&) = delete;
   WireframeRenderAlgorithm& operator=(const WireframeRenderAlgorithm&) = delete;
};

} // namespace graphics
} // namespace clockwork
