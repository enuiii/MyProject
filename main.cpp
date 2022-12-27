#include <Header.h>

int main()
{
    mt::Race race;

    race.SetResolution(1600, 900);
    race.SetCaption("Race");
    race.Setup();
    race.Run();

    return 0;
}