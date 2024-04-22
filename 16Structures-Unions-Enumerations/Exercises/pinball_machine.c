

enum type
{
    EM, // Electromechanical
    SS // Solid state
};

struct pinball_machine
{
    char name[40];
    int year; // Manufacture year
    enum type value;
    int players; // representing the maximum number of players
};