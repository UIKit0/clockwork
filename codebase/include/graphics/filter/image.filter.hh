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

#include "factory.hh"


namespace clockwork {
namespace graphics {

class ImageFilter
{
public:
   /**
    * Types of image filters.
    */
   enum class Type
   {
      None,
      BlackAndWhite,
      Grayscale
   };
   /**
    * Return the filter's type.
    */
   const Type& getType() const;
protected:
   /**
    * Instantiate a filter with a given type.
    */
   explicit ImageFilter(const Type type);
private:
   /**
    * This filter's type.
    */
   const Type _type;
};


/**
 * The ImageFilterFactory is a factory that creates and stores ImageFilter objects.
 */
class ImageFilterFactory : public clockwork::Factory<ImageFilter::Type, const ImageFilter*>
{
public:
   /**
    * Return the factory's unique instance.
    */
   static ImageFilterFactory& getInstance();
private:
   /**
    * The ImageFilterFactory is a singleton.
    */
   ImageFilterFactory();
   ImageFilterFactory(const ImageFilterFactory&) = delete;
   ImageFilterFactory& operator=(const ImageFilterFactory&) = delete;
};

} // namespace graphics
} // namespace clockwork
