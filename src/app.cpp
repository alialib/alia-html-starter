#include <alia/html.hpp>

using namespace alia;

// Here's the 'Interactive Hello' example from the docs.
void
greeting_ui(html::context ctx, duplex<std::string> name)
{
    html::p(ctx, "What's your name?");

    // Allow the user to input their name.
    html::input(ctx, name);

    // If we have a name, greet the user.
    alia_if(name != "")
    {
        html::p(ctx, "Hello, " + name + "!");
    }
    alia_end
}

void
app_ui(html::context ctx)
{
    document_title(ctx, "alia/HTML Starter");

    placeholder_root(ctx, "app-content", [&] {
        h1(ctx, "Hello, World!").attr("class", "mt-5 mb-3");

        p(ctx, "Welcome to alia/HTML!");

        auto name = get_state(ctx, "");
        greeting_ui(ctx, name);
    });
}

int
main()
{
    static html::system the_sys;
    initialize(the_sys, app_ui);
};
