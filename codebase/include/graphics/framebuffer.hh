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

#include <QObject>
#include <QImage>
#include <cstdint>
#include <atomic>
#include <functional>
#include "fragment.hh"


namespace clockwork {
namespace graphics {

class Framebuffer : public QObject
{
Q_OBJECT
public:
   /**
    * Available framebuffer resolutions.
    */
   enum class Resolution
   {
      VGA,     //  640 x 480
      SVGA,    //  800 x 600
      XGA,     // 1024 x 768
      SXGA,    // 1280 x 1024
      FHD,     // 1920 x 1080
      QSXGA,   // 2560 x 2048
      UHD8K    // 7680 x 4320
   };
   /**
    * Instantiate a framebuffer with a given resolution.
    * @param resolution the framebuffer's resolution.
    */
   explicit Framebuffer(const Framebuffer::Resolution& resolution = Framebuffer::Resolution::SVGA);
   /**
    * The destructor.
    */
   ~Framebuffer();
   /**
    * Return the pixel buffer.
    */
   const uint32_t* getPixelBuffer() const;
   /**
    * Return the pixel buffer's clear value.
    */
   const uint32_t& getPixelBufferClearValue() const;
   /**
    * Set the pixel buffer's clear value.
    * @param value the clear value to set.
    */
   void setPixelBufferClearValue(const uint32_t& value);
   /**
    * Return the depth buffer.
    */
   const double* getDepthBuffer() const;
   /**
    * Return the depth buffer's clear value.
    */
   const double& getDepthBufferClearValue() const;
   /**
    * Set the depth buffer's clear value.
    * @param value the clear value to set.
    */
   void setDepthBufferClearValue(const double& value);
   /**
    * Return the stencil buffer.
    */
   const uint8_t* getStencilBuffer() const;
   /**
    * Return the stencil buffer's clear value.
    */
   const uint8_t& getStencilBufferClearValue() const;
   /**
    * Set the stencil buffer's clear value.
    * @param value the clear value to set.
    */
   void setStencilBufferClearValue(const uint8_t& value);
   /**
    * Return the accumulation buffer.
    */
   const uint32_t* getAccumulationBuffer() const;
   /**
    * Return the accumulation buffer's clear value.
    */
   const uint32_t& getAccumulationBufferClearValue() const;
   /**
    * Set the accumulation buffer's clear value.
    * @param value the clear value to set.
    */
   void setAccumulationBufferClearValue(const uint32_t& value);
   /**
    * Write a fragment to the framebuffer.
    * @param fragment the fragment to write to the framebuffer.
    * @param fop the fragment operation that converts a fragment into a pixel value.
    */
   void plot(const Fragment& fragment, const std::function<uint32_t(const Fragment&)>& fop);
   /**
    * Write a pixel and its depth value to the framebuffer at the given coordinate.
    * @param x the framebuffer element's row position.
    * @param y the framebuffer element's column position.
    * @param depth the depth value to write.
    * @param pixel the pixel value to write.
    */
   void plot(const uint32_t& x, const uint32_t& y, const double& depth, const uint32_t& pixel);
   /**
    * Return the framebuffer's resolution.
    */
   const Framebuffer::Resolution& getResolution() const;
   /**
    * Return the framebuffer's width.
    */
   const uint32_t& getWidth() const;
   /**
    * Return the framebuffer's height.
    */
   const uint32_t& getHeight() const;
   /**
    * Clear the framebuffer.
    */
   void clear();
   /**
    * Resize the framebuffer.
    * @param resolution the framebuffer's new resolution.
    * @param force true to force the framebuffer resize, false otherwise.
    */
   void resize(const Framebuffer::Resolution& resolution, const bool& force = false);
   /**
    * Discard the fragment at the given <x, y> coordinate.
    * @param x the framebuffer element's row position.
    * @param y the framebuffer element's column position.
    */
   void discard(const uint32_t& x, const uint32_t& y);
   /**
    * Return all available framebuffer resolutions.
    */
   static QList<Framebuffer::Resolution> getAvailableResolutions();
   /**
    * Return the buffer offset for a given <x, y> coordinate. If the coordinate
    * is out of the framebuffer's bounds, then -1 is returned.
    * @param x the buffer element's row position.
    * @param y the buffer element's column position.
    */
   int getOffset(const uint32_t& x, const uint32_t& y) const;
private:
   /**
    * The framebuffer's resolution.
    */
   Framebuffer::Resolution _resolution;
   /**
    * The framebuffer's width.
    */
   uint32_t _width;
   /**
    * The framebuffer's height.
    */
   uint32_t _height;
   /**
    * The depth buffer which holds color information for each pixel in the display.
    */
   uint32_t* _pixelBuffer;
   /**
    * The pixel buffer's clear value.
    */
   uint32_t _pixelBufferClearValue;
   /**
    * The depth buffer which holds depth information for each pixel in the display.
    */
   double* _depthBuffer;
   /**
    * The depth buffer's clear value.
    */
   double _depthBufferClearValue;
   /**
    * TODO Explain me.
    */
   uint8_t* _stencilBuffer;
   /**
    * The depth buffer's clear value.
    */
   uint8_t _stencilBufferClearValue;
   /**
    * TODO Explain me.
    */
   uint32_t* _accumulationBuffer;
   /**
    * The depth buffer's clear value.
    */
   uint32_t _accumulationBufferClearValue;
   /**
    * A flag to make the framebuffer writable or readable-only.
    */
   std::atomic<bool> _ignoreWrites;
   /**
    * Test if a given fragment passes all fragment tests. It will return the
    * fragment's buffer offset if the fragment passes all tests, otherwise -1.
    * @param fragment the fragment to test.
    */
   int fragmentPasses(const Fragment& fragment) const;
   /**
    * Free the memory used by the internal buffers.
    */
   void free();
signals:
   /**
    * This signal is emitted when the framebuffer contains a frame that can
    * be drawn to the display device.
    */
   void frameReady();
};

} // namespace graphics
} // namespace clockwork

std::ostream& operator<<(std::ostream&, const clockwork::graphics::Framebuffer&);
std::ostream& operator<<(std::ostream&, const clockwork::graphics::Framebuffer::Resolution&);
