######################################################################
# Automatically generated by qmake (2.01a) Thu Jan 9 17:47:03 2014
######################################################################

TEMPLATE = app
TARGET = clockwork 
DEPENDPATH += . \
              src \
              include/concurrency \
              include/graphics \
              include/io \
              include/physics \
              include/scene \
              include/system \
              include/types \
              include/ui \
              src/concurrency \
              src/graphics \
              src/io \
              src/physics \
              src/scene \
              src/system \
              src/types \
              src/ui \
              include/concurrency/task \
              include/graphics/filter \
              include/graphics/projection \
              include/graphics/renderer \
              include/types/math \
              include/ui/comboboxes \
              include/ui/views \
              src/concurrency/task \
              src/graphics/filter \
              src/graphics/projection \
              src/graphics/renderer \
              src/ui/comboboxes \
              src/ui/views \
              include/graphics/renderer/implementation \
              src/graphics/renderer/implementation
INCLUDEPATH += . \
               include/ui \
               include/types \
               include/graphics \
               include/types/math \
               include/io \
               include/graphics/renderer \
               include/graphics/projection \
               include/graphics/filter \
               include/graphics/renderer/implementation \
               include/system \
               include/concurrency \
               include/scene \
               include/physics \
               include/ui/views \
               include/ui/comboboxes \
               include/concurrency/task

# Input
HEADERS += include/concurrency/concurrency.subsystem.hh \
           include/concurrency/graphics.update.task.hh \
           include/concurrency/render.task.hh \
           include/concurrency/task.hh \
           include/graphics/camera.hh \
           include/graphics/color.hh \
           include/graphics/face.hh \
           include/graphics/fragment.hh \
           include/graphics/framebuffer.hh \
           include/graphics/frustum.hh \
           include/graphics/graphics.subsystem.hh \
           include/graphics/material.hh \
           include/graphics/mesh.hh \
           include/graphics/model3d.hh \
           include/graphics/texture.hh \
           include/graphics/vertex.hh \
           include/graphics/viewport.hh \
           include/graphics/vsd.hh \
           include/io/asset.hh \
           include/io/file.reader.hh \
           include/io/io.output.hh \
           include/physics/rigid.body.hh \
           include/scene/scene.entity.hh \
           include/scene/scene.hh \
           include/scene/scene.node.hh \
           include/scene/scene.object.hh \
           include/scene/scene.property.hh \
           include/scene/scene.viewer.hh \
           include/system/asset.manager.hh \
           include/system/debug.hh \
           include/system/execution.context.hh \
           include/system/services.hh \
           include/system/subsystem.hh \
           include/types/error.hh \
           include/types/factory.hh \
           include/types/uid.hh \
           include/ui/ui.busy.indicator.hh \
           include/ui/ui.component.hh \
           include/ui/ui.control.panel.hh \
           include/ui/ui.display.hh \
           include/ui/ui.hh \
           include/ui/ui.window.hh \
           include/concurrency/task/point.render.task.hh \
           include/concurrency/task/polygon.render.task.hh \
           include/concurrency/task/random.render.task.hh \
           include/concurrency/task/texture.render.task.hh \
           include/concurrency/task/wireframe.render.task.hh \
           include/graphics/filter/image.filter.factory.hh \
           include/graphics/filter/image.filter.hh \
           include/graphics/filter/texture.filter.factory.hh \
           include/graphics/filter/texture.filter.hh \
           include/graphics/projection/projection.factory.hh \
           include/graphics/projection/projection.hh \
           include/graphics/renderer/renderer.factory.hh \
           include/graphics/renderer/renderer.hh \
           include/types/math/matrix4.hh \
           include/types/math/point3.hh \
           include/types/math/point4.hh \
           include/types/math/vector3.hh \
           include/ui/comboboxes/ui.combobox.hh \
           include/ui/comboboxes/ui.combobox.image.filter.hh \
           include/ui/comboboxes/ui.combobox.line.algorithm.hh \
           include/ui/comboboxes/ui.combobox.projection.hh \
           include/ui/comboboxes/ui.combobox.renderer.hh \
           include/ui/comboboxes/ui.combobox.texture.filter.hh \
           include/ui/views/ui.view.hh \
           include/ui/views/ui.view.scene.entity.hh \
           include/ui/views/ui.view.scene.hh \
           include/graphics/renderer/implementation/renderer.implementation.point.hh \
           include/graphics/renderer/implementation/renderer.implementation.polygon.hh \
           include/graphics/renderer/implementation/renderer.implementation.random.hh \
           include/graphics/renderer/implementation/renderer.implementation.texture.hh \
           include/graphics/renderer/implementation/renderer.implementation.wireframe.hh
SOURCES += src/main.cpp \
           src/concurrency/concurrency.subsystem.cpp \
           src/concurrency/graphics.update.task.cpp \
           src/concurrency/render.task.cpp \
           src/concurrency/task.cpp \
           src/graphics/camera.cpp \
           src/graphics/color.cpp \
           src/graphics/face.cpp \
           src/graphics/fragment.cpp \
           src/graphics/framebuffer.cpp \
           src/graphics/frustum.cpp \
           src/graphics/graphics.subsystem.cpp \
           src/graphics/material.cpp \
           src/graphics/mesh.cpp \
           src/graphics/model3d.cpp \
           src/graphics/texture.cpp \
           src/graphics/vertex.cpp \
           src/graphics/viewport.cpp \
           src/graphics/vsd.cpp \
           src/io/file.reader.obj.cpp \
           src/io/output.cpp \
           src/physics/rigid.body.cpp \
           src/physics/suzanne.rigid.body.cpp \
           src/scene/entity.cpp \
           src/scene/node.cpp \
           src/scene/object.cpp \
           src/scene/scene.cpp \
           src/scene/viewer.cpp \
           src/system/asset.manager.cpp \
           src/system/debug.cpp \
           src/system/services.cpp \
           src/system/subsystem.cpp \
           src/types/matrix4.cpp \
           src/types/point3.cpp \
           src/types/point4.cpp \
           src/types/uid.cpp \
           src/types/vector3.cpp \
           src/ui/ui.busy.indicator.cpp \
           src/ui/ui.component.cpp \
           src/ui/ui.control.panel.cpp \
           src/ui/ui.cpp \
           src/ui/ui.display.cpp \
           src/ui/ui.window.cpp \
           src/concurrency/task/point.render.task.cpp \
           src/concurrency/task/polygon.render.task.cpp \
           src/concurrency/task/random.render.task.cpp \
           src/concurrency/task/texture.render.task.cpp \
           src/concurrency/task/wireframe.render.task.cpp \
           src/graphics/filter/image.filter.cpp \
           src/graphics/filter/image.filter.factory.cpp \
           src/graphics/filter/texture.filter.cpp \
           src/graphics/filter/texture.filter.factory.cpp \
           src/graphics/projection/projection.cpp \
           src/graphics/projection/projection.factory.cpp \
           src/graphics/renderer/renderer.cpp \
           src/graphics/renderer/renderer.factory.cpp \
           src/ui/comboboxes/ui.combobox.cpp \
           src/ui/comboboxes/ui.combobox.image.filter.cpp \
           src/ui/comboboxes/ui.combobox.line.algorithm.cpp \
           src/ui/comboboxes/ui.combobox.projection.cpp \
           src/ui/comboboxes/ui.combobox.renderer.cpp \
           src/ui/comboboxes/ui.combobox.texture.filter.cpp \
           src/ui/views/ui.view.cpp \
           src/ui/views/ui.view.scene.cpp \
           src/ui/views/ui.view.scene.entity.cpp \
           src/graphics/renderer/implementation/renderer.implementation.point.cpp \
           src/graphics/renderer/implementation/renderer.implementation.polygon.cpp \
           src/graphics/renderer/implementation/renderer.implementation.random.cpp \
           src/graphics/renderer/implementation/renderer.implementation.texture.cpp \
           src/graphics/renderer/implementation/renderer.implementation.wireframe.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wextra

DESTDIR = ../build
OBJECTS_DIR = $${DESTDIR}/obj
MOC_DIR = $${DESTDIR}/moc
RCC_DIR = $${DESTDIR}/rcc
UI_DIR = $${DESTDIR}/ui