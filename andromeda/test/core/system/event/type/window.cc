#include "andromeda/core/system/event/type/window.hpp"

#include "andromeda/core/system/event/manager.hpp"

#include "gtest/gtest.h"

TEST(Event, Move) {
    EXPECT_NO_THROW({
        auto move = Andromeda::System::Event::Window::Move({3, 2});
        EXPECT_EQ(move.status, Andromeda::System::Structure::Status::Event::Unused);
        move.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Resize) {
    EXPECT_NO_THROW({
        auto resize = Andromeda::System::Event::Window::Resize({3, 2});
        EXPECT_EQ(resize.status, Andromeda::System::Structure::Status::Event::Unused);
        resize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Close) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Close close;
        EXPECT_EQ(close.status, Andromeda::System::Structure::Status::Event::Unused);
        close.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Refresh) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Refresh refresh;
        EXPECT_EQ(refresh.status, Andromeda::System::Structure::Status::Event::Unused);
        refresh.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Focus) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Focus focus;
        EXPECT_EQ(focus.status, Andromeda::System::Structure::Status::Event::Unused);
        focus.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Defocus) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Defocus defocus;
        EXPECT_EQ(defocus.status, Andromeda::System::Structure::Status::Event::Unused);
        defocus.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Maximize) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Maximize maximize;
        EXPECT_EQ(maximize.status, Andromeda::System::Structure::Status::Event::Unused);
        maximize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Minimize) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Minimize minimize;
        EXPECT_EQ(minimize.status, Andromeda::System::Structure::Status::Event::Unused);
        minimize.status = Andromeda::System::Structure::Status::Event::Used;
    });
}

TEST(Event, Restore) {
    EXPECT_NO_THROW({
        Andromeda::System::Event::Window::Restore restore;
        EXPECT_EQ(restore.status, Andromeda::System::Structure::Status::Event::Unused);
        restore.status = Andromeda::System::Structure::Status::Event::Used;
    });
}


TEST(Event, Serial_Callback) {
    auto callback = [](Andromeda::System::Event::Window::Close & event) {
        EXPECT_TRUE(event.status == Andromeda::System::Structure::Status::Event::Unused);
        event.status = Andromeda::System::Structure::Status::Event::Used;
    };
    Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Window::Close> manager;
    manager.listen(callback);
    Andromeda::System::Event::Window::Close event1;
    manager.callback(event1);
    Andromeda::System::Event::Window::Close event2;
    manager.deafen(callback);
    manager.callback(event1);
    manager.listen(callback);
    manager.callback(event2);
}

TEST(Event, Parallel_Callback) {
    auto callback = [](Andromeda::System::Event::Window::Close & event) {
        EXPECT_TRUE(event.status == Andromeda::System::Structure::Status::Event::Unused);
        event.status = Andromeda::System::Structure::Status::Event::Used;
    };
    auto callback2 = [](Andromeda::System::Event::Window::Close & event) {
        EXPECT_TRUE(event.status == Andromeda::System::Structure::Status::Event::Used);
    };
    Andromeda::System::Event::Manager::Parallel<Andromeda::System::Event::Window::Close> manager;
    manager.listen(callback);
    manager.listen(callback2);
    Andromeda::System::Event::Window::Close event1;
    Andromeda::System::Event::Window::Close event2;
    manager.queue(event1);
    manager.queue(event2);
    manager.series();
}