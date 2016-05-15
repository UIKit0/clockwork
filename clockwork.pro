include(resources/theme/material/material.pri)

TEMPLATE = app
TARGET = clockwork
CONFIG += c++14
RESOURCES += clockwork.qrc

QMAKE_CXXFLAGS += -Wextra

DESTDIR = build
OBJECTS_DIR = $${DESTDIR}/obj
MOC_DIR = $${DESTDIR}/moc
RCC_DIR = $${DESTDIR}/rcc
UI_DIR = $${DESTDIR}/ui

INCLUDEPATH += \
    src/graphics \
    src/graphics/renderer \
    src/io \
    src/math \
    src/scene \
    src/system \
    src/task \
    src/ui \
    src

HEADERS += \
    src/graphics/Framebuffer.hh \
    src/graphics/GraphicsEngine.hh \
    src/system/Application.hh \
    src/system/Error.hh \
    src/system/Service.hh \
    src/task/TaskManager.hh \
    src/ui/FramebufferProvider.hh \
    src/ui/UserInterface.hh \
    src/clockwork.hh

SOURCES += \
    src/graphics/Framebuffer.cc \
    src/graphics/GraphicsEngine.cc \
    src/system/Application.cc \
    src/system/Error.cc \
    src/system/Service.cc \
    src/task/TaskManager.cc \
    src/ui/FramebufferProvider.cc \
    src/ui/UserInterface.cc \
    src/clockwork.cc
