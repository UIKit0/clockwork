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

#include "subsystem.hh"
#include <QThreadPool>


namespace clockwork {
namespace concurrency {

class ConcurrencySubsystem : public clockwork::system::Subsystem
{
friend clockwork::system::Services;
public:
   /**
    * Enable or disable multi-threaded execution.
    * @param enable true to enable multi-threaded execution, false to disable.
    */
   void enableMultiThreadedExecution(const bool& enable = true);
   /**
    * Is multi-threading enabled?
    */
   bool isMultiThreadedExecutionEnabled() const;
	/**
	 * Submit a task to be processed.
	 * @param task a pointer to the task to process.
	 */
	void submitTask(clockwork::concurrency::Task* const task);
	/**
	 * Wait for all current tasks to complete.
	 */
	void wait();
private:
	/**
	 * All subsystems are singletons. As such the default constructor is hidden,
	 * and the copy operator and constructor are deleted from the implementation.
	 */
	ConcurrencySubsystem();
	ConcurrencySubsystem(const ConcurrencySubsystem&) = delete;
	ConcurrencySubsystem& operator=(const ConcurrencySubsystem&) = delete;
	/**
	 * A reference to the thread pool.
	 */
	QThreadPool* const _threadPool;
};

} // namespace concurrency
} // namespace clockwork
