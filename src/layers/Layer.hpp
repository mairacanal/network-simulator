#pragma once

class Layer {
public:
    /**
     * @brief A camada recebe algo da camada inferior e processa.
     */
    template <typename A>
    static void receive(A value) = delete;

    /**
     * @brief A camada recebe algo da camada superior e processa.
     */
    template <typename A>
    static void send(A value) = delete;
};
