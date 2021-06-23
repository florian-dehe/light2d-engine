#include "GuiWindow.h"

#include "../third_party/imgui/imgui.h"

using namespace light2d::ui;

GuiWindow::GuiWindow(std::string name, int flags) {
    this->name = name;
    this->windowFlags = flags;
}

GuiWindow::~GuiWindow() {
}

void GuiWindow::render() {
    if (!visible)
        return;
    
    ImGui::Begin(name.c_str(), &visible, windowFlags);
    
    this->onUpdate();
    
    ImGui::End();
}

void GuiWindow::setVisible(bool value) {
    this->visible = value;
}
