#pragma once
#include "Board.h"
#include "Drawable.h"
#include "Entity.h"

#include <memory>
#include <vector>


class Scene : public IDrawable {
public:
    Scene() {
        std::unique_ptr<IDrawable> board = std::make_unique<Board>(600, 600);
        drawables.push_back(std::move(board));
    }

    void draw() const override {
        for (const auto& entity : drawables)
            entity->draw();
    }

private:
    std::vector<std::unique_ptr<IDrawable>> drawables;
};

