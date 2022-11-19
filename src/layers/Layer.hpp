#pragma once

class Layer {
public:
    template <typename A>
    static void receive(A value) = delete;

    template <typename A>
    static void send(A value) = delete;
};
