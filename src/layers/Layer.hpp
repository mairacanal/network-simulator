#pragma once

class Layer {
    public:

    template <typename R, typename A>
    static R receive(A value) = delete;

    template <typename R, typename A>
    static R send(A value) = delete;
};