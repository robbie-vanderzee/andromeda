#pragma once

#include "andromeda/core/system/graphics/display/manager.hpp"

#include "monitor.hpp"
#include "window.hpp"

#include <memory>
namespace Andromeda::System::Linux::Graphics::Display {
    class Manager : public Andromeda::System::Graphics::Display::Manager {
      public:
        Manager();
        ~Manager() override;

        void initialize();
        void update() override;

        void create(Andromeda::System::Graphics::Display::Window::Configuration configuration) override;

      private:
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Monitor>> m_Monitors;
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Window>> m_Windows;
    };
} /* Andromeda::System::Graphics::Display */