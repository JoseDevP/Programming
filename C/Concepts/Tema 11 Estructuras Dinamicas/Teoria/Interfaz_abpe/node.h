#pragma once

typedef struct s
{
    int nNodes;
    void *data;
    struct s *left;
    struct s *right;
}Node;
