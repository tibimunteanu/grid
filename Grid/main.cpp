#include "App.h"

int main(int argc, char* argv[])
{
    App* app = App::Instance();

    if (app)
    {
        app->Run();
    }

    App::Release();
    app = NULL;

    return 0;
}