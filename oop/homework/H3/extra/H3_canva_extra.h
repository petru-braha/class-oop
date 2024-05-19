#pragma once
class Canvas_extra {
    char** canva_matrix;
    int max_line, max_column;
public:
    Canvas_extra(int lines, int columns);

    void set_pixel(int x, int y, char value);
    void set_pixels(int count, ...);

    void clear();
    void print() const;
    ~Canvas_extra();
};
