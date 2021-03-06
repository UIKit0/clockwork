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

#include "ui.view.hh"
#include <QTreeView>


namespace clockwork {
namespace ui {

class GUISceneView : public GUIView
{
Q_OBJECT
public:
   /**
    * Instantiate a GUISceneView that is attached to the user interface.
    * @param ui the user interface that this component is attached to.
    */
   GUISceneView(UserInterface& ui);
   /**
    * Build the view.
    */
   void build();
private:
   /**
    * The tree view used to present the scene graph.
    */
   QTreeView* const _treeView;
private slots:
   /**
    * This slot is called when an item in the view is clicked.
    */
   void onClicked(const QModelIndex&);
};

} // namespace ui
} // namespace clockwork

