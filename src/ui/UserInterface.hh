/*
 * This file is part of Clockwork.
 *
 * Copyright (c) 2014-2016 Jeremy Othieno.
 *
 * The MIT License (MIT)
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
#ifndef CLOCKWORK_USER_INTERFACE_HH
#define CLOCKWORK_USER_INTERFACE_HH

#include <QQmlApplicationEngine>
#include "Error.hh"


namespace clockwork {

class Application;
class Framebuffer;

class UserInterface
{
	friend class Application;
public:
    UserInterface(const UserInterface&) = delete;
    UserInterface(UserInterface&&) = delete;
    UserInterface& operator=(const UserInterface&) = delete;
    UserInterface& operator=(UserInterface&&) = delete;

    Error initialize(const Framebuffer& framebuffer);
private:
    QQmlApplicationEngine engine_;

    UserInterface() = default;
};

} // namespace clockwork

#endif // CLOCKWORK_USER_INTERFACE_HH
