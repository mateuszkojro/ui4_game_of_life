//
// Created by mateu on 3/24/2021.
//

#ifndef GAME_OF_LIFE_GAMEOFLIFE_H
#define GAME_OF_LIFE_GAMEOFLIFE_H

#include "GameEngine.h"

class GameOfLife : public GameEngine {
public:
    explicit GameOfLife(const Config &config)
            : GameEngine(config) {};

    void on_start() override;

    void on_tick() override;

    void on_end() override;

    ~GameOfLife() override;

private:
    /// \brief Gets value at position from current board
    bool get_element(int x, int y) const;
    /// \brief Sets value at position on next_board
    void set_element(int x, int y, bool value);
    /// \brief Swaps current_board with next_board to be shown and to prepare for next tick
    void swap_boards();
    /// \brief Counts a number of alive cells around cell at position
    unsigned count_alive_near_position(int x, int y) const;

    /// \brief board that is currently shown on the screen
    bool* current_board_;
    ///\brief board that will be shown on the next tick
    bool* next_board_;

};

#endif //GAME_OF_LIFE_GAMEOFLIFE_H
