#include <stdio.h>

typedef enum
{
    EMPTY = -1,
    I,
    J,
    L,
    O,
    S,
    T,
    Z
}ShapeId;

typedef enum {
    RED = 41,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
    BLACK = 0,
}Color;

typedef struct
{
    ShapeId shape;
    Color color;
    int size;
    char rotates[4][4][4];
}Shape;

typedef struct {
    int x;
    int y;
    int score;
    int rotate;
    int fallTime;
    ShapeId queue[4];
}State;

typedef struct {
    Color color;
    ShapeId shape;
    bool current;
}Block;

Shape shapes[7] =
{
    {
        .shape = I,
        .color = CYAN,
        .size = 4,
        .rotates = {
            {
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0},
                {0,0,0,0}
            },
            {
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0}
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0}
            },
            {
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0}
            },
        }
    },
    {
        .shape = J,
        .color = GREEN,
        .size = 3,
        .rotates = {
            {
                {0,1,0},
                {0,1,0},
                {1,1,0}
            },
            {
                {1,0,0},
                {1,1,1},
                {0,0,0}
            },
            {
                {0,1,1},
                {0,1,0},
                {0,1,0}
            },
            {
                {0,0,0},
                {1,1,1},
                {0,0,1}
            },
        }
    },
    {
        .shape = O,
        .color = YELLOW,
        .size = 4,
        .rotates = {
            {
                {0,0,1},
                {1,1,1},
                {0,0,0}
            },
            {
                {0,1,0},
                {0,1,0},
                {0,1,1}
            },
            {
                {0,0,0},
                {1,1,1},
                {1,0,0}
            },
            {
                {1,1,0},
                {0,1,0},
                {0,1,0}
            },
        }
    },
    {
        .shape = L,
        .color = PURPLE,
        .size = 4,
        .rotates = {
            {
                {1,1},
                {1,1},
            },
            {
                {1,1},
                {1,1},            
            },
            {
                {1,1},
                {1,1},
            },
            {
                {1,1},
                {1,1},
            },
        }
    },
    {
        .shape = S,
        .color = YELLOW,
        .size = 4,
        .rotates = {
            {
                {0,1,1},
                {1,1,0},
                {0,0,0},
            },
            {
                {0,1,0},
                {0,1,1},
                {0,0,1},
            },
            {
                {0,0,0},
                {0,1,1},
                {1,1,0},
            },
            {
                {1,0,0},
                {1,1,0},
                {0,1,0},
            },
        }
    },
    {
        .shape = T,
        .color = RED,
        .size = 4,
        .rotates = {
            {
                {0,1,0},
                {1,1,1},
                {0,0,0},
            },
            {
                {0,1,0},
                {0,1,1},
                {0,1,0},
            },
            {
                {0,0,0},
                {1,1,1},
                {0,1,0},
            },
            {
                {0,1,0},
                {1,1,0},
                {0,1,0},
            },
        }
    },
    {
        .shape = Z,
        .color = BLUE,
        .size = 4,
        .rotates = {
            {
                {0,1,0},
                {1,1,1},
                {0,0,0},
            },
            {
                {0,0,1},
                {0,1,1},
                {0,1,0},
            },
            {
                {0,0,0},
                {1,1,0},
                {0,1,1},
            },
            {
                {0,1,0},
                {1,1,0},
                {1,0,0},
            },
        }
    },
};

void setBlock(Block* block, Color color, ShapeId shape, bool current)
{
    block->color = color;
    block->shape = shape;
    block->current = current;

}

int main()
{
    Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH];
    Color cur;
    // �X�ؤ�� (�ثe�u�� I)
    for (int i = 0; i < 7; i++) {
        //�L�X���
        //�ĴX�Ӽ˦�
        for (int r = 0; r < 4; r++) {
            // �G���}�C��������X
            for (int s = 0; s < shapes[i].size; s++) {
                for (int t = 0; t < shapes[i].size; t++) {
                    //�p�G�O 0 �N��X�զ�
                    if (shapes[i].rotates[r][s][t] == 0) {
                        cur = WHITE;
                    }
                    else {
                        cur = shapes[i].color;
                    }
                    printf("\033[%dm  \033[0m", cur);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}