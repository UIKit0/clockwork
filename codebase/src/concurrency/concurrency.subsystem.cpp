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
#include "concurrency.subsystem.hh"
#include <QThread>


clockwork::concurrency::ConcurrencySubsystem::ConcurrencySubsystem() :
_threadPool(QThreadPool::globalInstance())
{
	enableMultiThreadedExecution();
}


void
clockwork::concurrency::ConcurrencySubsystem::enableMultiThreadedExecution(const double& enable)
{
	_threadPool->setMaxThreadCount(enable ? QThread::idealThreadCount() : 1);
}


bool
clockwork::concurrency::ConcurrencySubsystem::isMultiThreadedExecutionEnabled() const
{
	return _threadPool->maxThreadCount() > 1;
}


void
clockwork::concurrency::ConcurrencySubsystem::submitTask(clockwork::concurrency::Task* const task)
{
	if (task != nullptr)
		_threadPool->start(task, task->getPriority());
}


void
clockwork::concurrency::ConcurrencySubsystem::wait()
{
	if (_threadPool->activeThreadCount() > 0)
		_threadPool->waitForDone();
}